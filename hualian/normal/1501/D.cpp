#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int a[N],b[N],c[N],vis[N],k;
int Dep[N];
int ep[N],idx,cnt,pa[N];
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	int n=read(),m=read();k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	if(n>m)swap(n,m),swap(a,b);
	for(int i=1;i<=n;i++)
		pa[a[i]]=i;
	for(int i=1;i<=m;i++){
		if(!c[i]){
			++cnt;
			int now=i,dep=0;
			while(!vis[now]){
				vis[now]=++dep;
				c[now]=cnt;
				now=(now+n-1)%m+1;
			}
			Dep[cnt]=dep;
		}
	}
	for(int i=1;i<=m;i++){
		int x=b[i];
		if(pa[x]&&c[pa[x]]==c[i]){
			int day=((vis[i]+Dep[c[i]]-vis[pa[x]])%Dep[c[i]])*n+pa[x];
			ep[++idx]=day;
		}
	}
	sort(ep+1,ep+1+idx);
	int len=n*m/gcd(n,m);
	int ans=(k/(len-idx))*len;
	k%=(len-idx);
	if(!k)k+=len-idx,ans-=len;
	for(int i=1;i<=idx;i++){
		if(k<=ep[i]-ep[i-1]-1){
			ans+=ep[i-1]+k;
			k=0;
			break;
		}
		else
			k-=ep[i]-ep[i-1]-1;
	}
	if(k)ans+=ep[idx]+k;
	cout<<ans<<endl;
	return 0;
}