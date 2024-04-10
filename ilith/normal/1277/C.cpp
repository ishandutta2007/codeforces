#include<bits/stdc++.h>
using namespace std;
int t;
string s;
bool vis[150010];
int ans[150010];
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		int len=s.length();
		for(int i=1;i<=len;i++){
			vis[i]=0;
		}
		int cnt=0;
		for(int i=1;i<len-1;i++){
			if(s.substr(i-1,3)=="one"||s.substr(i-1,3)=="two"){
				vis[i]=1;
			}
		}
		for(int i=1;i<=len;i++){
			if(vis[i]&&!vis[i+2]){
				ans[++cnt]=i+1;
				vis[i+1]=0;
			}
			if(vis[i]&&vis[i+2]){
				ans[++cnt]=i+2;
				vis[i+1]=vis[i+2]=0;
			}
		}
		cout<<cnt<<'\n';
		for(int i=1;i<=cnt;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}