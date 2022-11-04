#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s,t;cin>>s>>t;
		int n=s.size(),m=t.size();
		string res;
		int l=0,r=0;
		bool pos=true;
		while(!(l==n&&r==m)){
			l%=n;r%=m;
			if(s[l]!=t[r]){pos=false;break;}
			res+=s[l];
			++l;++r;
		}
		if(pos)cout<<res<<endl;
		else cout<<-1<<endl;
	}
}