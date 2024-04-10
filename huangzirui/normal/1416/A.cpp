#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=300010;
int i,j,k,n,m,T,nxt[maxn],a[maxn],S[maxn],Max[maxn],ans[maxn];
int main(){
	cin>>T;
	while(T--){
		n=read();
		for(i=1;i<=n;i++)nxt[i]=S[i]=Max[i]=0,ans[i]=maxn;
		for(i=1;i<=n;i++){
			a[i]=read();
			nxt[S[a[i]]]=i;
			Max[a[i]]=max(Max[a[i]],i-S[a[i]]);
			S[a[i]]=i;
		}for(i=1;i<=n;i++)Max[a[i]]=max(Max[a[i]],n+1-S[a[i]]);
		for(i=1;i<=n;i++)ans[Max[i]]=min(ans[Max[i]],i);
		for(i=2;i<=n;i++)ans[i]=min(ans[i],ans[i-1]);
		for(i=1;i<=n;i++)printf("%d ",(ans[i]==maxn?-1:ans[i]));puts("");
	}
	return 0;
}