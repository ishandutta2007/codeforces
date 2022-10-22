#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
ll bit[2][mn];
void up(int c,int a,ll b){for(;a<mn;a+=a&-a)bit[c][a]+=b;}
ll qu(int c,int a){ll b=0;for(;a;a-=a&-a)b+=bit[c][a];return b;}
void update(int a,int b,ll c){
    up(1,a,c);
    up(1,b+1,-c);
    up(0,a,-c*(a-1));
    up(0,b+1,c*b);
}
ll query(int a){
    return a*qu(1,a)+qu(0,a);
}
multiset<pii>s;
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n+1;i++)s.insert({i,i});
    while(m--){
        int a,b,c,d;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d%d",&b,&c,&d);
            set<pii>::iterator it=--s.upper_bound({b,0x3f3f3f3f});
            while(it->first<=c){
                set<pii>::iterator nxt=it;
                nxt++;
                update(max(b,it->first),min(c,nxt->first-1),abs(d-it->second));
                if(nxt->first>c+1)s.insert({c+1,it->second});
                if(it->first<b)it++;
                else it=s.erase(it);
            }
            s.insert({b,d});
        }
        else{
            scanf("%d%d",&b,&c);
            printf("%lld\n",query(c)-query(b-1));
        }
    }
}