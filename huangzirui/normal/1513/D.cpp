#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
struct node{
	int x,id;
}e[maxn];
bool cmp(node a,node b){
	return a.x<b.x;
}
int i,j,k,n,m,T,a[maxn],last[maxn],nxt[maxn],Q[maxn],top,F[maxn],is[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)a[i]=read(),F[i]=i,e[i]={a[i],i},is[i]=0;
		is[0]=1;is[n]=1;
		Q[top=1]=1;
		for(i=2;i<=n;i++){
			while(top && a[Q[top]]>a[i])--top;
			last[i]=Q[top];Q[++top]=i;
		}
		Q[top=1]=n;
		for(i=n-1;i>=1;i--){
			while(top && a[Q[top]]>a[i])--top;
			nxt[i]=Q[top];Q[++top]=i;
		}sort(e+1,e+1+n,cmp);
//		for(i=1;i<=n;i++)cout<<"i="<<i<<' '<<last[i]<<' '<<nxt[i]<<endl;
		int ans=n-1;ll ans2=0;
		for(i=1;i<=n;i++){
			int x=e[i].id;
			if(a[x]>=m)break;
			int l=x,r=x;
//			cout<<"i="<<i<<" x="<<x<<l<<r<<endl;
			while(!is[l-1])
				if(a[l-1]%a[x]==0)is[--l]=1,--ans,ans2+=a[x];
				else break;
//			cout<<"i="<<i<<" x="<<x<<l<<r<<endl;
			while(!is[r])
				if(a[r+1]%a[x]==0)is[r++]=1,--ans,ans2+=a[x];
				else break;
//			cout<<"i="<<i<<" x="<<x<<l<<r<<endl; 
		}printf("%lld\n",ans2+1ll*ans*m);
	}
	return 0;
}