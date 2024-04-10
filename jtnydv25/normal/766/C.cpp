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
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int mod = 1e9+7;
const int N = 1e3+10;
int dp1[N], dp2[N], dp3[N], p[26][N], a[26];
inline int add(int x, int y){x+=y; if(x>=mod)x-=mod; return x;}
int main(){
	int t = 1,n;
	string s;
	// sd(t);
	while(t--){
		sd(n); cin>>s;
		rep(i,0,26) sd(a[i]);
		rep(i,1,n+1){
			int x = s[i-1]-'a';
			rep(j,0,26) p[j][i] = p[j][i-1];
			p[x][i]++;
			dp3[i] = 1000000000;
		}
		dp1[0] = 1;
		for(int i = 1;i<=n;i++){
			int j = i-1;
			for(;j>=0;j--){
				bool flag = 0;
				for(int k = 0;k<26;k++) if(p[k][i]-p[k][j]>0 && i-j > a[k]){flag = 1; break;}
				if(flag) break;
				dp1[i] = add(dp1[i],dp1[j]);
				if(j == 0 || dp2[j] != 0) dp2[i] = max(dp2[i],max(dp2[j],i-j));
				dp3[i] = min(dp3[i], 1 + dp3[j]);
			}
		}
		pd(dp1[n]);
		pd(dp2[n]);
		pd(dp3[n]);
	}
}