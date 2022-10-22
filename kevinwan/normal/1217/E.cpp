#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e5+10;
inline pii hail(const pii &a,const pii &b){
    if(b.second<a.first)return b;
    else if(b.first<a.first)return {b.first,a.first};
    else if(b.first<a.second)return {a.first,b.first};
    else return a;
}
struct seg{
    pii seg[mn*2];
    void up(int a,pii b){
        seg[a+=mn]=b;
        for(a>>=1;a;a>>=1)seg[a]=hail(seg[a*2],seg[a*2+1]);
    }
    pii qu(int a,int b){
        pii ans={0x3f3f3f3f,0x3f3f3f3f};
        for(a+=mn,b+=mn;a<=b;a>>=1,b>>=1){
            if(a&1)ans=hail(ans,seg[a++]);
            if(!(b&1))ans=hail(ans,seg[b--]);
        }
        return ans;
    }
};
seg s[10];
int p[10];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(s,0x3f,sizeof(s));
    p[0]=1;
    for(int i=1;i<10;i++)p[i]=p[i-1]*10;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=0;j<=9;j++)if((x/p[j])%10){
                s[j].up(i,{x,0x3f3f3f3f});
            }
    }
    while(m--){
        int a,b;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d",&a,&b);
            for(int i=0;i<=9;i++){
                if(b/p[i]%10)s[i].up(a,{b,0x3f3f3f3f});
                else s[i].up(a,{0x3f3f3f3f,0x3f3f3f3f});
            }
        }
        else{
            scanf("%d%d",&a,&b);
            int ans=INT_MAX;
            for(int i=0;i<=9;i++){
                pii p=s[i].qu(a,b);
                if(p.second==0x3f3f3f3f)continue;
                ans=min(ans,p.first+p.second);
            }
            if(ans==INT_MAX)printf("-1\n");
            else printf("%d\n",ans);
        }
    }
}