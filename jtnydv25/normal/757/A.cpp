#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
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
#define print(s) cerr <<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
map<char,int> freq, cnt;
int main(){
	cin.tie(0);
	int t = 1,n;
	// sd(t);
	while(t--){
		string s = "Bulbasaur";
		string S1;
		cin>>S1;
		for(int i = 0;i<S1.length();i++) freq[S1[i]]++;
		int ans = 1e6;
		for(int i = 0;i<s.length();i++) cnt[s[i]]++;
		for(auto it: cnt) ans = min(ans, freq[it.F]/it.S);
		pd(ans);
	}
}