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
int i,j,k,n,m,a[maxn],b[maxn];
ll ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		n=read();m=read();
		ans=0;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=m;i++)b[i]=read();
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+m);
		for(i=1;i<=m;i++)ans+=a[i];
		int now=m;
		for(i=1;i<=m;i++){
			now+=b[i]-1;
			if(b[i]==1)ans+=a[i];
			else ans+=a[now];
		}printf("%lld\n",ans);
	}
	return 0;
}