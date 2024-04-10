#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=4000010;
int i,j,k,n,m,T,a[maxn],c[maxn],b[maxn];
vector<int>V[maxn];
int main(){
	cin>>T;
	while(T--){
		n=read();
		int ans=0;
		for(i=1;i<=n;i++)a[i]=read(),b[i]=c[i]=0,V[a[i]].push_back(i);
		cerr<<"OK!"<<endl;
		for(i=1;i<=n;i++)if(V[i].size())ans++;
		if(ans!=n-1){
			printf("%d\n",ans);
			for(i=1;i<=n;i++)if(V[i].size())c[V[i][0]]=i,b[i]=1;
			//for(i=1;i<=n;i++)cout<<c[i]<<' ';cout<<endl;
			int u=1,t=1;bool B=true;
			for(i=1;i<=n;i++)
				if(b[i]==0 && c[i]==0){
					if(B){int last=t;while((b[t]!=0 || c[t]!=0) || t==i){t=t%n+1;if(last==t)break;}if(last==t)B=false;}
					if(!B)while(b[u]!=0 || u==i)u=u%n+1;
					if(B)c[i]=t,b[t]=i;
					else c[i]=u,b[u]=i;
					//cout<<B<<' '<<t<<"   123132"<<endl;
				}
			//for(i=1;i<=n;i++)cout<<c[i]<<' ';cout<<endl;
			for(i=1;i<=n;i++)
				if(!c[i]){
					while(b[u]!=0)u=u%n+1;
					c[i]=u;b[u]=i;
				}
		}else{
			int flag=0,D=0,E=0;
			for(i=1;i<=n;i++)if(V[i].size()==1)c[V[i][0]]=i,b[i]=1;else if(V[i].size()==2)D=i;
			for(i=1;i<=n;i++)if(b[i]==0 && c[i]==0){c[i]=D;b[D]=i;E=1;}
			if(!E)for(i=1;i<=n;i++)if(c[i]==0){c[i]=D,b[D]=i;break;}
			for(i=1;i<=n;i++)if(c[i]==0){for(j=1;j<=n;j++)if(b[j]==0)c[i]=j,b[j]=i;break;}
			printf("%d\n",ans-flag);
		}
		for(i=1;i<=n;i++)if(i!=c[i])printf("%d ",c[i]),V[i].clear();else exit(1);puts("");
	}
}