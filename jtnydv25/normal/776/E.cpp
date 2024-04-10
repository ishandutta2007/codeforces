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

const int N= 1e6+1e3;
int p[N];

inline ll phi(ll n){
	ll ret = n;
	for(int i = 0;p[i]*1ll*p[i]<=n;i++){
		if(n%p[i] == 0){
			ret/=p[i];
			ret *= (p[i]-1);
			while(n%p[i] == 0) n/=p[i];
		}
	}
	if(n != 1) {
		ret /= n;
		ret *= (n-1);
	}
	return ret;
}

ll F(ll k, ll n){
	if(k>100) return 1; 
	if(n==1) return 1;
	if(k==1) return phi(n);
	if(k&1) return phi(F(k-2,n));
	return F(k-1,n);
}
int main(){
	for(int i = 2;i*i<N;i++)
		if(!p[i]){
			for(int j = i*i;j<N;j+=i) p[j] = 1;
		}
	int j = 0;			
	for(int i = 2;i<N;i++) if(!p[i]) p[j++] = i;
	ll n,k;
	cin>>n>>k;
	cout<< F(k,n)%(1000000007);			
}