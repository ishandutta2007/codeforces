#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
#define PI 3.14159265358979
bool col[200001],vis[200001];
vector<int> gg[200001];
set<int> g[200001];
int cnt = 1,num[200001],dep[200001],evil=0,val;
long double angle(long double x, long double y) {
	if (x == 0 && y > 0)return PI/2;
	if (x == 0 && y < 0)return 3 * PI / 2;
	long double ang = atan(y / x);
	if (x < 0)ang += PI;
	if (ang < 0)ang += 2 * PI;
	return ang;
}
pair<long double,int> v[100001];
int main() {
	scanf("%d", &n);
	int i,a,b;
	for (i = 0; i < n; i++)scanf("%d%d", &a, &b), v[i] = { angle(a,b),i };
	sort(v, v + n);
	v[n] = v[0];
	v[n].first += 2 * PI;
	int num;
	long double diff = 1e300;
	for (i = 0; i < n; i++)if (v[i+1].first-v[i].first< diff)diff=v[i+1].first-v[i].first, num = i;
	printf("%d %d", v[num].second+1, v[num + 1].second+1);
}