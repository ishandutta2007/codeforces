#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const llint INF = 1000000000000000007LL;

int n, ok=1;
llint a[MAXN], b[MAXN];
vector < pair <int, llint> > v[MAXN];

llint f (int cvor) {
	if (!ok) return -1;
	llint res=b[cvor]-a[cvor];
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].first;
		llint dis=v[cvor] [i].second;
		llint t=f(sus);
		if (t>0) {
			res+=t;
		} else {
			if (!ok) return -1;
			if (t<-INF/dis) {
				cout << "NO";
				ok=0;
				return -1;
			}
			res+=t*dis;
			if (res<-INF) {
				cout << "NO";
				ok=0;
				return -1;
			}
		}	
	}
	return res;
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		scanf("%lld", &b[i]);
	}
	for (int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i=2; i<=n; i++) {
		int x; llint k;
		scanf("%d%lld", &x, &k);
		v[x].push_back(make_pair(i, k));
	}
	if (f(1)>=0) {
		cout << "YES";
	} else {
		if (ok) cout << "NO";
	}
	return 0;
}