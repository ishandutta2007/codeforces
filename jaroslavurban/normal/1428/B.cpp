#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;
		string s;cin>>n>>s;
		bool r=true,l=true;
		for(int i=0;i<n;++i)if(s[i]=='>')l=false;
		else if(s[i]=='<')r=false;
		if(l||r){
			cout<<n<<endl;continue;
		}
		ll res=0;
		for(int i=0;i<n;++i)if(s[(i-1+n)%n]=='-'||s[i]=='-')++res;
		cout<<res<<endl;
	}
}