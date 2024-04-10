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
string X,Y,X1,Y1;
int main(){
	cin>>X>>Y;
	set<string> s = {X,Y};
	int n;
	sd(n);
	for(int i = 0;i<n;i++){
		for(auto it:s) cout<< it <<" ";
			cout<<endl;
		cin>>X1>>Y1;
		s.erase(X1);
		s.insert(Y1);
	}
		for(auto it:s) cout<< it <<" ";
}