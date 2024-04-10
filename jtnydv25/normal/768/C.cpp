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
const int N = 1e5+10;
int cnt1[10000], cnt2[10000], A[N], ind[N], val[N];
set<int> s;	
vector<int> vec;
int main(){
	int n,k,x;
	sd(n), sd(k), sd(x);
	rep(i,1,n+1) sd(A[i]), s.insert(A[i]), s.insert(A[i]^x);
	int m = 0;
	for(auto it:s) vec.eb(it), ind[it]=++m;
	rep(i,1,n+1) cnt1[ind[A[i]]]++;	
	int l,odd,even;
	for(int i = 1;i<=k;i++){
		int C = 1;
		memcpy(cnt2,cnt1,sizeof cnt1);
		memset(cnt1,0,sizeof cnt1);
		for(int it: vec){
			l = cnt2[ind[it]];
			if(!l) continue;
			odd = (C==1)?l-l/2 : l/2;
			even = l - odd;
			cnt1[ind[it^x]] += odd;
			cnt1[ind[it]] += even;
			C = ((C+l)&1);
		}
	}
	int MX = 0, MN = 1025;
	for(int i:vec) if(cnt1[ind[i]]) MN = min(MN,i), MX = max(MX,i);
	printf("%d %d\n", MX, MN);
}