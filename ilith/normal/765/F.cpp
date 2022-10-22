#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010,B=350,inf=1e9+7;
#define bel(x) ((x-1)/B+1)
int f[N][B+9],s[B+9][B+9],L[B+9],R[B+9],n,m,a[N],cntB,ans[N];
pii b[N];
vector<int>vl,vr;
int l,r;
inline int merge(){
    int l1=0,l2=0,ans=inf;
    for(rgi i=0;i<vl.size()-1;++i)ans=min(ans,vl[i+1]-vl[i]);
    for(rgi i=0;i<vr.size()-1;++i)ans=min(ans,vr[i+1]-vr[i]);
    while(l1<vl.size()&&l2<vr.size()){
        ans=min(ans,abs(vl[l1]-vr[l2]));
        if(vl[l1]<vr[l2])++l1;
		else ++l2;
    }
    return ans;
}
signed main(){
	read(n),cntB=bel(n);
    for(rgi i=1;i<=n;++i)read(a[i]),b[i]={a[i],i};
    for(rgi i=1;i<=cntB;++i)L[i]=R[i-1]+1,R[i]=i*B;
	R[cntB]=n;
    for(rgi i=1;i<=cntB;++i)sort(b+L[i],b+R[i]+1);
    for(rgi i=1;i<=cntB;++i){
        for(rgi j=1;j<=cntB;++j)if(i!=j){
            for(rgi k=L[i],l=L[j];k<=R[i];++k){
                while(l<R[j]&&b[l+1].fi<b[k].fi)++l;
                f[b[k].se][j]=abs(b[k].fi-b[l].fi);
                if(l<R[j])f[b[k].se][j]=min(f[b[k].se][j],abs(b[l+1].fi-b[k].fi));
            }
        }
        for(rgi k=L[i];k<=R[i];++k){
            for(rgi j=i-2;~j;--j)f[k][j]=min(f[k][j],f[k][j+1]);
            for(rgi j=i+2;j<=cntB;++j)f[k][j]=min(f[k][j],f[k][j-1]);
        }
        for(rgi j=1;j<i;++j)
        for(rgi k=L[i]+1;k<=R[i];++k)f[k][j]=min(f[k][j],f[k-1][j]);
        for(rgi j=i+1;j<=cntB;++j)
        for(rgi k=R[i]-1;k>=L[i];--k)f[k][j]=min(f[k][j],f[k+1][j]);
        int&S=s[i][i];S=inf;
        for(rgi j=L[i];j<R[i];++j)S=min(S,b[j+1].fi-b[j].fi);
    }
    for(rgi i=1;i<=cntB;++i)for(rgi j=i+1;j<=cntB;++j)s[i][j]=min(min(s[i][j-1],f[R[j]][i]),s[j][j]);
    read(m);
    while(m--){
        read(l,r);
        int bL=bel(l),bR=bel(r);
        int ans=inf;
        if(bL<bR){
            if(bL+1<=bR-1)ans=s[bL+1][bR-1],ans=min(ans,min(f[r][bL+1],f[l][bR-1]));
            vl.clear(),vr.clear();
            for(rgi i=L[bL];i<=R[bL];++i)if(b[i].se>=l)vl.push_back(b[i].fi);
            for(rgi i=L[bR];i<=R[bR];++i)if(b[i].se<=r)vr.push_back(b[i].fi);
            ans=min(ans,merge());
        }else{
            int pre=-inf;
            for(rgi i=L[bL];i<=R[bL];++i)
            if(l<=b[i].se&&b[i].se<=r)ans=min(ans,b[i].fi-pre),pre=b[i].fi;
        }
        write(ans,'\n');
    }
    return 0;
}