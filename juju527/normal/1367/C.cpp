#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int pre[maxn],suf[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,k,ans=0;
		string s;
		n=read();k=read();
		cin>>s;
		s=" "+s;
		pre[0]=-4e5;
		for(int i=1;i<s.size();i++){
			if(s[i]=='0')pre[i]=pre[i-1];
			else pre[i]=i;
		}
		suf[s.size()]=4e5;
		for(int i=s.size()-1;i>=1;i--){
			if(s[i]=='0')suf[i]=suf[i+1];
			else suf[i]=i;
		}
		for(int i=1;i<s.size();i++){
			pre[i]=max(pre[i],pre[i-1]);
			if(i-pre[i]>k&&suf[i]-i>k){
				ans++;
				pre[i]=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}