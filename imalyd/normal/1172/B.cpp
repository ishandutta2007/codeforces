//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define I inline
//#define R register int
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class IT>void gi(IT &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;
template<class IT>void chkmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>void chkmax(IT &a,IT b){if(a<b)a=b;}

const int N=200005;
const ll p=998244353ll;
int n,v,u;
vector<int>e[N];
ll ans,fac[N];
void dfs(int v,int f){
	int u;
	ans=ans*fac[e[v].size()]%p;
	for(int i=0;i<e[v].size();i++){
		u=e[v][i];
		if(u!=f)dfs(u,v);
	}
}
int main(){
	scanf("%d",&n);
	fac[0]=1ll;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
	for(int i=1;i< n;i++){
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	ans=n;
	dfs(1,0);
	printf("%I64d",ans);
	return 0;
}