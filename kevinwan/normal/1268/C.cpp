#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
ll a[mn],p[mn];
ll bit[mn],num[mn],cum;
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b;}
ll que(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
set<int>::iterator nxt(set<int>::iterator it){return ++it;}
set<int>::iterator pre(set<int>::iterator it){return ++it;}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i),p[a[i]]=i;
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]+i-1-que(p[i]);
        upd(p[i],1);
    }
    set<int>s;
    printf("%lld ",0LL);
    s.insert(p[1]);
    auto it=s.begin();
    int ind=0;
    for(int i=2;i<=n;i++){
        if(p[i]<*it)ind++;
        cum+=abs(p[i]-*it);
        s.insert(p[i]);
        if(ind<i/2){
            ll dif=-*it+*(++it);
            cum+=(ind+1)*dif-(i-ind-1)*dif;
            ++ind;
        }
        if(ind>i/2){
            ll dif=*it-*(--it);
            cum+=-ind*dif+(i-ind)*dif;
            --ind;
        }
        printf("%lld ",cum+num[i]-1LL*ind*(ind+1)/2-1LL*(i-ind-1)*(i-ind)/2);
    }
}