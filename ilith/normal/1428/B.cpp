#include<bits/stdc++.h>
using namespace std;
int n,t;
int vs[400010];
string s;
int main(){
	cin>>t;
	while(t--){
		memset(vs,0,sizeof vs);
		cin>>n>>s;
		bool k1=0,k2=0;
		for(int i=0;i<n;i++){
			if(s[i]=='>')k1=1;
			else if(s[i]=='<')k2=1;
			else vs[i]=1,vs[(i+1)%n]=1;
		}
		if(!k1||!k2){
			cout<<n<<'\n';
		}
		else{
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=vs[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}