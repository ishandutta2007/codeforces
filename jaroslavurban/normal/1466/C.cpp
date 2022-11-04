#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int g[N];
ll w[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		int n=s.size();
		int res=0;
		for(int i=1;i<n;++i){
			if(s[i]==s[i-1]||(i-2>=0&&s[i]==s[i-2])){
				++res;
				for(int j=0;j<26;++j){
					bool in=false;
					for(int k=i-2;k<=i+2;++k)if(i!=k&&i<n&&s[k]==char(j+'a'))in=true;
					if(!in){s[i]=j+'a';break;}
				}
			}
		}
		cout<<res<<endl;
	}
}