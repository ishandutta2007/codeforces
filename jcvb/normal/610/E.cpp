#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int cnt[15][15];
int n,m,k;
char str[222222];
int a[222222];// start of a interval
set<int>se;

char ss[15];

int lis[222222];

set<int>::iterator brea(int i){//i-1 and i
    if(se.count(i))return se.find(i);
    set<int>::iterator it=se.insert(i).first,it2=it;
    it2--;
    a[i]=a[*it2];
    return it;
}
int main()
{
    gn(n);gn(m);gn(k);
    scanf("%s",str+1);
    for (int i=1;i<=n;i++)a[i]=str[i]-'a'+1;
    for (int i=1;i<=n;i++)se.insert(i);
    a[0]=a[n+1]=k+1;
    se.insert(0);se.insert(n+1);
    for (int i=1;i<=n;i++)cnt[a[i]][a[i+1]]++;
    while(m--){
        int opt;
        gn(opt);
        if(opt==1){
            int l,r;char cc;
            gn(l);gn(r);
            while((cc=getchar())<'a' || cc>'z');
            int c=cc-'a'+1;

            set<int>::iterator it1=brea(l),it3=it1;it3--;
            set<int>::iterator it2=brea(r+1);

            int tot=0;
            while(1){
                lis[++tot]=*it3;
                if(lis[tot]==r+1)break;
                it3++;
            }

            for (int i=1;i<tot;i++)cnt[a[lis[i]]][a[lis[i+1]]]--;
            it1++;se.erase(it1,it2);
            a[l]=c;
            cnt[a[lis[1]]][c]++;
            cnt[c][a[lis[tot]]]++;
        }else{
            scanf("%s",ss+1);
            int an=0;
            for (int i=1;i<=k;i++)
                for (int j=i+1;j<=k;j++)an+=cnt[ss[i]-'a'+1][ss[j]-'a'+1];
            printf("%d\n",n-an);
        }
    }
    return 0;
}