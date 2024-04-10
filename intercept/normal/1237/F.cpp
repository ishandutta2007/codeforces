#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=3609;
int n,m,q,na,nb;
int va[M],vb[M],da[M][M],db[M][M];
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>n>>m>>q;
	for(int i=1;i<=q;++i){
		int lx,ly,rx,ry;
		cin>>lx>>ly>>rx>>ry;
		va[lx]=va[rx]=1;
		vb[ly]=vb[ry]=1;
	}
	for(int i=1;i<=n;++i){
		na+=va[i]==0;
	}
	for(int i=1;i<=m;++i){
		nb+=vb[i]==0;
	}
	da[0][0]=db[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			da[i][j]=da[i-1][j];
			if(!va[i]&&!va[i-1]&&i>1&&j){
				da[i][j]=(da[i][j]+da[i-2][j-1])%mod;
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<=m;++j){
			db[i][j]=db[i-1][j];
			if(!vb[i]&&!vb[i-1]&&i>1&&j){
				db[i][j]=(db[i][j]+db[i-2][j-1])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			ans=(ans+1ll*da[n][i]*db[m][j]%mod*c(nb-j*2,i)%mod*c(na-i*2,j)%mod)%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

/*
3 4 0
*/