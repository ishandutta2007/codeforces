#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;

const unsigned long long p = (1LL << 61) - 1;
inline uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & p) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & p) + (ret >> 61);
    ret = (ret & p) + (ret >> 61);
    return ret - 1;
}
inline uint64_t add(uint64_t a,uint64_t b){
    uint64_t c=a+b;
    return c>=p?c-p:c;
}
inline uint64_t sub(uint64_t a,uint64_t b){
    return a>=b?a-b:a-b+p;
}
inline uint64_t po(uint64_t a,uint64_t b=p-2){
    uint64_t ans=1;
    for(;b;b>>=1,a=mul(a,a))if(b&1)ans=mul(ans,a);
    return ans;
}
uint64_t m=rng()+581;
uint64_t tran[mn][2];
int v[mn],ans[mn];
vector<int>g[mn];
set<uint64_t>*h[mn];
string s;
void dfs(int x,int p){
    int mo=0;
    tran[x][0]=1;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        if(h[y]->size()>h[mo]->size())mo=y;
    }
    if(mo)h[x]=h[mo],swap(tran[x],tran[mo]);
    uint64_t rp=po(tran[x][0]);
    for(int y:g[x])if(y!=p&&y!=mo){
        for(uint64_t z:*h[y]){
            h[x]->insert(mul(sub(add(mul(z,tran[y][0]),tran[y][1]),tran[x][1]),rp));
        }
    }
    tran[x][0]=mul(tran[x][0],m),tran[x][1]=mul(tran[x][1],m);
    tran[x][1]=add(tran[x][1],s[x]);
    h[x]->insert(mul(sub(s[x],tran[x][1]),po(tran[x][0])));
    ans[x]=h[x]->size();
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",v+i);
    cin>>s;
    s=" "+s;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<=n;i++)h[i]=new set<uint64_t>();
    dfs(1,0);
    int pr=0,num=0;
    for(int i=1;i<=n;i++){
        if(ans[i]+v[i]>pr)pr=ans[i]+v[i],num=1;
        else if(ans[i]+v[i]==pr)num++;
    }
    printf("%d\n%d",pr,num);
}