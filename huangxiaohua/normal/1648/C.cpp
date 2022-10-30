#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],b[1005000],sb[1005000],NMSL[1005000];
ll jc[1000500],inv[1000500],res,t1=1;

#define M 998244353
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int f[205][200500];
void add(int x,int y,int z){
	for(;x<=200000;x+=(-x&x)){f[y][x]+=z;}
}
int get(int x,int y,int z=0){
	for(;x;x-=(-x&x)){z+=f[y][x];}return z;
}
set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)cin>>b[i];
	for(i=1;i<=n;i++){
		sb[a[i]]++;
	}
	t1=jc[n-1];
	for(i=1;i<=200000;i++){
		if(!sb[i])continue;
		t1=t1*inv[sb[i]]%M;
		NMSL[sb[i]]++;
		//cout<<t1<<' '<<sb[i]<<endl;
		if(sb[i]<=200)add(i,sb[i],1);
		else s.insert(i);
	}
	for(i=1;i<=max(n,m);i++){
		//cout<<i<<' '<<res<<endl;
		if(!b[i])break;
		if(!a[i]){
			res++;res%=M;break;
		}
		for(j=1;j<=200;j++){
			if(!NMSL[j])continue;
			k=get(b[i]-1,j);
			//if(k)printf("NMSL%d %d %d %d\n",i,j,k,t1*inv[j-1]%M*jc[j]%M*k%M);
			res=su(res,t1*inv[j-1]%M*jc[j]%M*k%M);
		}
		for(auto x:s){
			if(x>=b[i])break;
			res=su(res,t1*inv[sb[x]-1]%M*jc[sb[x]]%M);
		}
		sb[b[i]]--;
		if(sb[b[i]]<0)break;
		NMSL[sb[b[i]]]++;
		NMSL[sb[b[i]]+1]--;
		t1=t1*inv[sb[b[i]]]%M*jc[sb[b[i]]+1]%M;
		t1=t1*ksm(n-i,M-2)%M;
		if(sb[b[i]]==200){
			add(b[i],sb[b[i]],1);
			s.erase(b[i]);
		}
		if(sb[b[i]]<200){
			add(b[i],sb[b[i]],1);
			add(b[i],sb[b[i]]+1,-1);
		}
	}
	cout<<res%M;
}