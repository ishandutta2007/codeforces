#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=355,K=320;
struct block{
	ll a[M],b[M],tag,k;
	ll d[M],r[M],n,t,now;
	ll f(int i){return (a[i]+b[i]*k);}
	int check(int i,int j,int k){
		return (a[i]-a[j])*(b[k]-b[j])>=(a[k]-a[j])*(b[i]-b[j]);
	}
	void build(){
		t=0;
		for (int i=1;i<=n;i++){
			if (a[r[i]]<-(1e17))continue;
			while (t&&b[r[i]]==b[d[t]]&&a[r[i]]>a[d[t]])t--;
			if (t&&b[r[i]]==b[d[t]])continue;
			while (t>1&&check(d[t-1],d[t],r[i]))t--;
			d[++t]=r[i];
		}
		now=1;
		while (now<t&&f(d[now])<f(d[now+1]))now++;
	}
	void pushtag(){
		for (int i=1;i<=n;i++)a[i]+=tag+k*b[i];
		tag=k=0;
	}
	void addk(){
		k++;
		while (now<t&&f(d[now])<f(d[now+1]))now++;
	}
	ll max(){return tag+f(d[now]);}
}w[M];
int E;
bool comp(int x,int y){return w[E].b[x]<w[E].b[y];}
int a[N],inq[N],st[M],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		inq[i]=i<=K?1:inq[i-K]+1;
		if (inq[i-1]!=inq[i])st[inq[i]]=i-1;
	}st[inq[n]+1]=n;
	for (int i=1;i<=inq[n];i++){
		for (int j=st[i]+1;j<=st[i+1];j++)
			w[i].a[j-st[i]]=w[i].b[j-st[i]]=a[j];
		w[i].n=st[i+1]-st[i];
		for (int j=1;j<=w[i].n;j++)w[i].r[j]=j;
		E=i;
		sort(w[i].r+1,w[i].r+w[i].n+1,comp);
		w[i].build();
	}
	ll ans=0;
	while (1){
		ll mx=0,k=0;
		for (int i=1;i<=inq[n];i++){
			if (w[i].max()>mx){
				mx=w[i].max();
				k=st[i]+w[i].d[w[i].now];
			}
		}
		if (mx<=0)break;
		ans+=mx;
		int z=inq[k];
		for (int i=1;i<z;i++)w[i].tag+=a[k];
		for (int i=z+1;i<=inq[n];i++)w[i].addk();
		w[z].pushtag();
		for (int i=1;i<=w[z].n;i++){
			if (st[z]+i<k)w[z].a[i]+=a[k];
			if (st[z]+i>k)w[z].a[i]+=a[st[z]+i];
			if (st[z]+i==k)w[z].a[i]=-1e18;
		}
		w[z].build();
	}
	cout<<ans<<endl;
}