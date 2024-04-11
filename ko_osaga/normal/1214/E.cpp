#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 300005;

int n;
pi a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	reverse(a, a + n);
	vector<int> v(n);
	for(int i=0; i<n; i++){
		v[i] = a[i].second * 2;
		if(i > 0) printf("%d %d\n", v[i-1], v[i]);
	}
	for(int i=0; i<n; i++){
		int nxt = i + a[i].first;
		assert(sz(v) >= nxt);
		printf("%d %d\n", v[nxt - 1], 2 * a[i].second - 1);
		if(sz(v) == nxt){
			v.push_back(2 * a[i].second - 1);
		}
	}
}