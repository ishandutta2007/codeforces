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

const int mn=2e5+10;

void solve(){
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	vi a,b;
	for(int i=0;i<n;i++){
		if(s[i]=='1')a.push_back(i);
		else b.push_back(i);
	}
	string aa(s),bb(s);
	if(s[0]=='0'||s[n-1]=='0'||(a.size()&1)){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=0;i<a.size();i++){
		aa[a[i]]=bb[a[i]]=')'^(i<a.size()/2);
	}
	for(int i=0;i<b.size();i++){
		bb[b[i]]=')'^(i&1);
		aa[b[i]]=bb[b[i]]^1;
	}
	printf("%s\n%s\n",aa.c_str(),bb.c_str());
}

signed main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
}