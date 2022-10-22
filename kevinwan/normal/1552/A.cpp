#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=300+10;
const ll mod=1e9+7;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		string s,t;
		cin>>s;
		t=s;
		sort(t.begin(),t.end());
		int c=0;
		for(int i=0;i<n;i++)c+=(s[i]!=t[i]);
		printf("%d\n",c);
	}
}