#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=1e3+10;
ll bit[4][mn][mn];
void upd(int a,int b,int c,ll d){for(int i=b;i<mn;i+=i&-i)for(int j=c;j<mn;j+=j&-j)bit[a][i][j]^=d;}
ll qu(int a,int b,int c){ll d=0;for(int i=b;i;i-=i&-i)for(int j=c;j;j-=j&-j)d^=bit[a][i][j];return d;}
void ad(int a,int b,ll c){
    upd(3,a,b,c);
    if(a&1^1)upd(2,a,b,c);
    if(b&1^1)upd(1,a,b,c);
    if((a&1^1)&(b&1^1))upd(0,a,b,c);
}
ll ge(int a,int b){
    ll c=0;
    if(a&b&1)c^=qu(3,a,b);
    if(b&1)c^=qu(2,a,b);
    if(a&1)c^=qu(1,a,b);
    c^=qu(0,a,b);
    return c;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c,d;
        ll e;
        scanf("%d",&a);
        if(a==2){
            scanf("%d%d%d%d%lld",&a,&b,&c,&d,&e);
            c++,d++;
            ad(a,b,e);
            ad(a,d,e);
            ad(c,d,e);
            ad(c,b,e);
        }else{
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a--,b--;
            e=ge(a,b)^ge(a,d)^ge(c,d)^ge(c,b);
            printf("%lld\n",e);
        }
    }
}