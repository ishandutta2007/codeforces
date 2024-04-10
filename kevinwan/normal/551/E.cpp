#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int siz=500;
const int mn=5e5+siz*10;
ll so[mn],k[mn],ad[mn/siz+10];
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    memset(k,0x3f,sizeof(k));
    for(int i=1;i<=n;i++)scanf("%lld",k+i),so[i]=k[i];
    for(int i=0;i<=n/siz;i++)sort(so+i*siz,so+(i+1)*siz);
    while(q--){
        int a,b,c;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d%d",&a,&b,&c);
             if(a/siz==b/siz){
                 for(int i=a;i<=b;i++)k[i]+=c;
                 for(int i=a/siz*siz;i/siz==a/siz;i++)so[i]=k[i];
                 sort(so+a/siz*siz,so+(a/siz+1)*siz);
             }else{
                 for(int i=a/siz+1;i<b/siz;i++)ad[i]+=c;
                 for(int i=a;i/siz==a/siz;i++)k[i]+=c;
                 for(int i=b/siz*siz;i<=b;i++)k[i]+=c;
                 for(int i=a/siz*siz;i/siz==a/siz;i++)so[i]=k[i];
                 sort(so+a/siz*siz,so+(a/siz+1)*siz);
                 for(int i=b/siz*siz;i/siz==b/siz;i++)so[i]=k[i];
                 sort(so+b/siz*siz,so+(b/siz+1)*siz);
             }
        }
        else{
            scanf("%d",&a);
            int i=0;
            for (; i<=n/siz&&!binary_search(so + i * siz, so + (i + 1) * siz, a - ad[i]); i++);
            if(i>n/siz){printf("-1\n");continue;}
            for (i *= siz; k[i] != a - ad[i / siz]; i++);
            int l = i;
            for (i = n / siz; !binary_search(so + i * siz, so + (i + 1) * siz, a - ad[i]); i--);
            for (i *= siz, i += siz - 1; k[i] != a - ad[i / siz]; i--);
            printf("%d\n", (i - l) >= 0 ? (i - l) : -1);
        }
    }
}