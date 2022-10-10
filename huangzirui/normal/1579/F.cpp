#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=2000010;
int i,j,k,n,m,T,a[maxn],vis[maxn],tmp[maxn],cnt;
void check(int x){
	if(vis[x]==T)return;
	vis[x]=T;tmp[++cnt]=a[x];
	check((x+m)%n);
}
int main(){
	cin>>T;
	memset(vis,-1,sizeof(vis));
	while(T--){
		int ans=0;
		cin>>n>>m;
		for(i=0;i<n;i++)a[i]=read();
		for(i=0;i<n;i++)
			if(vis[i]!=T){
				cnt=0;
				check(i);
				int len=0,Max=0;
//				cout<<" len="<<cnt<<endl;
				for(j=1;j<=cnt*2;j++){
					if(tmp[(j>cnt?j-cnt:j)])++len;
					else len=0;
					Max=max(Max,len);
				}
				if(Max==cnt*2)ans=1e9;
				else ans=max(ans,Max);
			}
		if(ans==1000000000)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}