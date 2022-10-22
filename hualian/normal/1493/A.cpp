#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int vis[N],ans,cnt[N];
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int main(){
	int t=read();
	while(t--){
		memset(vis,0,sizeof vis);vis[0]=1;
		memset(cnt,0,sizeof cnt);ans=0;
		int n=read(),k=read();
		for(int i=k-k/2;i<=n;i++){if(i==k)continue;ans++;}
		cout<<ans<<endl;
		for(int i=k-k/2;i<=n;i++){if(i==k)continue;cout<<i<<" ";}puts("");
	}
	return 0;
}