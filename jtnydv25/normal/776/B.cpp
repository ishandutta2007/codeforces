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

int main(){
	int n;
	sd(n);
	for(int i = 2;i*i<N;i++)
		if(!p[i]){
			for(int j = i*i;j<N;j+=i) p[j] = 1;
		}
	cout<< (n<=2?1:2) << endl;
	for(int i = 2;i<=n+1;i++){
		int k = (p[i]==0)?1:2;
		printf("%d ", k);
	}
}