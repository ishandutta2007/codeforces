#include<bits/stdc++.h>
using namespace std; 
int t;
int a,b;
string s;
int main(){
	cin>>t;
	while(t--){
		int ans=0;
		cin>>a>>b>>s;
		s+='0';
		int fg=0;
		int l=0;
		while(s[l]=='0')l++;
		for(int i=l;i<s.size();i++){
			if(s[i]=='1'){
				if(s[i+1]=='0')ans+=a;
				fg=0;
			}
			if(s[i]=='0'){
				fg++;
				if(s[i+1]=='1'){
					if(b*fg<=a){
						ans-=a;
						ans+=b*fg;
					}
					fg=0;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}