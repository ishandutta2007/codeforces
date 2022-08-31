#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"

const int N = 2e5 + 10;
int p[N], a[N], b[N];
set<pii> fr[4], ba[4];
const int INF = 1.5e9;
int main(){
	int t = 1, n, m;
	// sd(t);
	while(t--){
		sd(n);	
		for(int i = 1; i <= n; i++) sd(p[i]);
		for(int i = 1; i <= n; i++) sd(a[i]), fr[a[i]].insert({p[i], i});
		for(int i = 1; i <= n; i++) sd(b[i]), ba[b[i]].insert({p[i], i});
		sd(m);
		for(int i = 1; i <= m; i++){
			int c;
			sd(c);
			int price = INF;
			int s1= fr[c].size(), s2 = ba[c].size();
			if(s1 == 0 && s2 == 0){
				printf("%d ", -1);
				continue;
			}
			pii P;
			if(s1 != 0 && s2 != 0){
				pii p1 = *fr[c].begin();
				pii p2 = *ba[c].begin();
				P = min(p1, p2);
			}
			else if(s1 != 0) P = *fr[c].begin();
			else if(s2 != 0) P = *ba[c].begin();
			printf("%d ", P.F);
			for(int j = 1; j <= 3; j++){
				fr[j].erase(P);
				ba[j].erase(P);
			}
		}
	}
}