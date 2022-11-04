#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool isreg(string s){
	int cnt=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='(')++cnt;
		else if(--cnt<0)return false;
	}
	return cnt==0;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		bool pos=false;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					string t=s;
					for(int l=0;l<t.size();++l){
						if(t[l]=='A'){
							if(i)t[l]='(';
							else t[l]=')';
						}
						else if(t[l]=='B'){
							if(j)t[l]='(';
							else t[l]=')';
						}
						else if(t[l]=='C'){
							if(k)t[l]='(';
							else t[l]=')';
						}
					}
					pos|=isreg(t);
				}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}