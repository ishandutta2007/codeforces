#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define pd(x)(x<='Z'?x-'A'+1:x-'a'+1+26)
#define ll long long
#define db double
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,q,x,y,cnt[100];
char a[N];
ll ans,jc[N],ny[N],g,s[100][100];
ll p[N],p2[N];
ll ksm(ll x,int y){
	ll t=1;
	for(;y;y>>=1,x=x*x%mo)if(y&1)t=t*x%mo;
	return t;
}
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	fo(i,1,n)cnt[pd(a[i])]++;
	jc[0]=1;
	fo(i,1,n)jc[i]=jc[i-1]*i%mo;
	ny[n]=ksm(jc[n],mo-2);
	fd(i,0,n-1)ny[i]=ny[i+1]*(i+1)%mo;
	g=jc[n>>1];
	g=g*g%mo;
	fo(i,1,52)g=g*ny[cnt[i]]%mo;
	p[0]=1;
	fo(i,1,52)if(cnt[i]){
		fd(j,cnt[i],n)p[j]=(p[j]+p[j-cnt[i]])%mo;
	}
	int _n=n>>1;
	fo(i,1,52)if(cnt[i]){
		if(cnt[i]>(n>>1))continue;
		fo(j,0,n)p2[j]=p[j];
		fo(j,cnt[i],n)p2[j]=(p2[j]-p2[j-cnt[i]])%mo;
		s[i][i]=p2[_n-cnt[i]]*g*2%mo;
		fo(j,i+1,52)if(cnt[j]){
			if(cnt[i]+cnt[j]>(n>>1))continue;
			ll ct=0;
			int w=_n-cnt[i]-cnt[j];
			for(int k=1,ww=w;ww>=0;ww-=cnt[j],k=-k)
				ct+=p2[ww]*k;
			s[i][j]=ct%mo*g*2%mo;
		}
	}
	for(scanf("%d",&q);q--;){
		scanf("%d%d",&x,&y);
		x=pd(a[x]);y=pd(a[y]);
		if(x>y)swap(x,y);
		printf("%I64d\n",(s[x][y]+mo)%mo);
	}
}