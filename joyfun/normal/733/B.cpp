#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 100005;

int n, l[N], r[N];
int sl[N], sr[N];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		sl[i] = sl[i - 1] + l[i];
		sr[i] = sr[i - 1] + r[i];
	}
	int Max = -1, Maxv = 0;
	for (int i = 1; i <= n; i++) {
		int x = sl[i - 1] + sl[n] - sl[i] + r[i];
		int y = sr[i - 1] + sr[n] - sr[i] + l[i];
		int tmp = abs(x - y);
		if (tmp > Max) {
			Max = tmp;
			Maxv = i;
		}
	}
	if (Max <= abs(sl[n] - sr[n])) Maxv = 0;
	printf("%d\n", Maxv);
    return 0;
}