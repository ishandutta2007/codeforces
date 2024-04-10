#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+5;
int t,x,ans[maxn],ans1[maxn],l,r;
string s;
int main(){
	cin>>t; 
	while(t--){
		cin>>s;
		int len=s.size();
		l=1;r=0;
		int k=0;
		for(int i=0;i<len;i++){
			int now=s[i]-'0';
			if(l>r){
				ans1[++r]=now;
				continue;
			}
			if(now%2!=ans1[l]%2){
				bool flag=false;
				for(int j=l;j<=r;j++){
					int u=ans1[j];
					if(now<u){
						ans[++k]=now;
						flag=true;
						break;
					}
					l++;
					ans[++k]=u;
				}
				if(!flag)
					ans1[++r]=now;
			}else ans1[++r]=now;
		}
		for(int i=1;i<=k;i++)
			cout<<ans[i];
		for(int i=l;i<=r;i++)
			cout<<ans1[i];
		puts("");
	}
	return 0;
}