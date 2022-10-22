#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,m,q,a[510][1100];
char s[510];
inline void MINUS(int &x,int y){ x-=y; if (x<0) x+=5;}
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
void Gauss(){
	ll ans=0;
    for (int i=1,now=1;now<=n;i++){
		while (now<=n){
            for (int j=i+1;j<=m;j++)
				if (a[j][now]>0) swap(a[i],a[j]);
            if (a[i][now]) break;
        	now++;
		}
        if (now>n){ ans=qpow(5,n-i+1); break;}
		ll inv=1ll*a[i][now]*a[i][now]%5*a[i][now]%5;
        for (int j=i+1;j<=m;j++){
        	int tmp=1ll*a[j][now]*inv%5;
            for (int k=now;k<=n+q;k++) MINUS(a[j][k],1ll*tmp*a[i][k]%5);
        }
    }
    for (int i=n+1;i<=n+q;i++){
        ll tmp=ans;
        for (int j=1;j<=m;j++){
        	int cnt=0;
            for (int k=1;k<=n;k++) cnt+=(a[j][k]>0);
            if (!cnt&&a[j][i]) tmp=0;
        }
		printf("%lld\n",tmp); 
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%s",s+1);
        for (int j=1;j<=m;j++) a[j][i]=s[j]-'a';
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%s",s+1);
        for (int j=1;j<=m;j++) a[j][i+n]=s[j]-'a';
    }
    Gauss();
	return 0;
}