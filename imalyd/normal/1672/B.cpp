#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		string s;
		cin>>s;
		int n=s.length();
		if(s[n-1]=='A')puts("no");
		else {
			int i,v=0;
			for(i=0;i!=n;++i){
				if(s[i]=='B'){
					if((--v)<0)break;
				}else ++v;
			}
			if(i==n)puts("yes");else puts("NO");
		}
	}
	return 0;
}