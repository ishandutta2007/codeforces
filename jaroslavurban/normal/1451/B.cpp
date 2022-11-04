#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int l,r;
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int q;cin>>n>>q;
		string s;cin>>s;
		while(q--){
			int l,r;cin>>l>>r;
			bool pos=false;
			for(int i=0;i<l-1;++i)
				if(s[i]==s[l-1])pos=true;
			for(int i=n-1;i>=r;--i)
				if(s[i]==s[r-1])pos=true;
			if(pos)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}