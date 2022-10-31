#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int i,j,k,n,m,t,a[30][30],c[30],t0,t1,t2;
int f[20005000];ll x,y,res;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		string s;cin>>s;
		for(auto j:s)a[i][j-'a'+1]++;
	}
	for(i=1;i<b(n+1);i++){
		memset(c,1,sizeof(c));
		for(j=1;j<=n;j++){
			if(!(i&b(j)))continue;
			for(k=1;k<=26;k++)c[k]=min(c[k],a[j][k]);
		}
		t0=0;f[i]=1;
		for(j=1;j<=26;j++)f[i]=1ll*f[i]*(c[j]+1)%M;
		if(!(__builtin_popcount(i)&1))f[i]=M-f[i];
	}
	for(i=1;i<=n;i++)for(j=0;j<b(n+1);j++){
		if(j&b(i))f[j]=su(f[j],f[j^b(i)]);
	}
	for(i=1;i<b(n+1);i++){
		x=y=0;
		for(j=1;j<=n;j++){if(b(j)&i){x++;y+=j;}}
		res^=(x*y*f[i]);
	}
	cout<<res;
}