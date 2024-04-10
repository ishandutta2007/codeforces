#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,M=2e5+5,mo=1e9+7;
int n;
int a;
int ps,p[M],mn[M],cmn[M],bi[M],dy[M],cnt[M];
ll ans;
bool b[M];
ll ksm(int x,int y){
	ll t=1;
	fo(i,1,y)t=t*x;
	return t;
}
void cmin(int x,int cs){
	if(cs<mn[x])cmn[x]=mn[x],mn[x]=cs;else
	if(cs<cmn[x])cmn[x]=cs;
}
int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,2,2e5){
		if(!b[i])p[++ps]=i,bi[i]=i,dy[i]=ps;
		for(int j=1,u;(u=i*p[j])<=200000;++j){
			b[u]=1;bi[u]=p[j];
			if(i%p[j]==0)break;
		}
	}
	int B=0;
	for(;p[B+1]*p[B+1]<=2e5;)++B;
	fo(i,1,ps)mn[i]=cmn[i]=1e9;
	fo(i,1,n){
		cin>>a;
		fo(j,1,B){
			int cs=0;
			for(;a%p[j]==0;)++cs,a/=p[j];
			cmin(j,cs);
		}
		if(a!=1){
			cnt[dy[a]]++;
			cmin(dy[a],1);
		}
	}
	ans=1;
	fo(i,B+1,ps){
		fo(j,1,min(n-cnt[i],2))cmin(i,0);
	}
	fo(i,1,ps)ans=ans*ksm(p[i],cmn[i]);
	printf("%lld\n",ans);
}