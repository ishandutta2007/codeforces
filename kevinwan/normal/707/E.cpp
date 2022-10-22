#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=2e3+10;
const ll mod=1e9+7;
int bl[mn][mn],o[mn][mn];
ll v[mn][mn];
int aa[mn],bb[mn];
char s[256];
bool on[mn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
    for (;isdigit(ch);ch=getchar()) x=(x+(x<<2)<<1)+(ch^48);
    return x*f;
}
int main(){
    int n,m,k;
    memset(bl,-1,sizeof(bl));
    n=read(),m=read(),k=read();
    int at=2;
    for(int i=0;i<k;i++){
        int l;
        scanf("%d",&l);
        ll s=0;
        for(int j=0;j<l;j++){
            int a,b,c;
            a=read(),b=read(),c=read();
            bl[a][b]=i;
            s+=c;
            v[a][b]=s;
            o[a][b]=at++;
            if(j==l-1)aa[i]=a,bb[i]=b;
        }
        at++;
    }
    fill(on,on+mn,1);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%s",s);
        int a,b,c,d;
        ll ans=0;
        if(s[0]=='A'){
            a=read(),b=read(),c=read(),d=read();
            int e;
            for(int j=a;j<=c;j++){
                if(o[j][b]==o[j][b-1]+1)ans-=v[j][b-1]*on[bl[j][b]];
                else if(o[j][b]==o[j][b-1]-1)ans+=v[j][b]*on[bl[j][b]];
                if(o[j][d]==o[j][d+1]+1)ans-=v[j][d+1]*on[bl[j][d]];
                else if(o[j][d]==o[j][d+1]-1)ans+=v[j][d]*on[bl[j][d]];
            }
            for(int j=b;j<=d;j++){
                if(o[a][j]==o[a-1][j]+1)ans-=v[a-1][j]*on[bl[a][j]];
                else if(o[a][j]==o[a-1][j]-1)ans+=v[a][j]*on[bl[a][j]];
                if(o[c][j]==o[c+1][j]+1)ans-=v[c+1][j]*on[bl[c][j]];
                else if(o[c][j]==o[c+1][j]-1)ans+=v[c][j]*on[bl[c][j]];
            }
            for(int j=0;j<k;j++)if(on[j]){
                if(a<=aa[j]&&aa[j]<=c&&b<=bb[j]&&bb[j]<=d){
                    ans+=v[aa[j]][bb[j]];
                }
            }
            printf("%lld\n",ans);
        }
        else{
            a=read();
            on[a-1]^=1;
        }
    }
}