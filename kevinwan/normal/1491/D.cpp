#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;


vector<int>getbits(int x){
	vector<int>v;
	for(int i=30;i>=0;i--)if((x>>i)&1)v.push_back(i);
	return v;
}

signed main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(b<a){printf("NO\n");continue;}
		vi va=getbits(a),vb=getbits(b);
		if(va.size()<vb.size()){printf("NO\n");continue;}
		int st=0;
		while(st<min(va.size(),vb.size())&&va[st]==vb[st])st++;
		if(st==vb.size()){printf("YES\n");continue;}
		if(va[st]>vb[st]){printf("NO\n");continue;}
		bool fail=0;
		for(int i=0;i<vb.size()-(st+1);i++){
			if(va[va.size()-1-i]>vb[vb.size()-1-i])fail=1;
		}
		if(st==vb.size()&&st!=va.size())fail=1;
		if(!fail)printf("YES\n");
		else printf("NO\n");
	}
}