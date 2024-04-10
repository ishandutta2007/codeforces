#include<cstdio>
#include<algorithm>
#include<set>
#define pii pair<int,int>
#define SZ 524288
using namespace std;
int n, K, m;
set<pii>Set;
set<int>SS;
int O[SZ];
struct Tree{
    int K[SZ+SZ], M[SZ+SZ];
    void UDT(int nd){
        M[nd]=max(M[nd*2],M[nd*2+1]);
    }
    void init(int nd, int b, int e){
        K[nd]=0;
        if(b==e){
            M[nd] = b;
            return;
        }
        int m = (b+e)>>1;
        init(nd*2,b,m);
        init(nd*2+1,m+1,e);
        UDT(nd);
    }
    void Add2(int nd, int x){
        M[nd]+=x;
        K[nd]+=x;
    }
    void Spread(int nd){
        Add2(nd*2,K[nd]);
        Add2(nd*2+1,K[nd]);
        K[nd]=0;
    }
    void Add(int nd, int b, int e, int s, int l, int x){
        if(s>l)return;
        if(s<=b&&e<=l){
            Add2(nd,x);
            return;
        }
        Spread(nd);
        int m = (b+e)>>1;
        if(s<=m)Add(nd*2,b,m,s,l,x);
        if(l>m)Add(nd*2+1,m+1,e,s,l,x);
        UDT(nd);
    }
    int Max(int nd, int b, int e, int s, int l){
        if(s>l)return -99999999;
        if(s<=b&&e<=l)return M[nd];
        Spread(nd);
        int m = (b+e)>>1, r=-99999999;
        if(s<=m)r=max(r,Max(nd*2,b,m,s,l));
        if(l>m)r=max(r,Max(nd*2+1,m+1,e,s,l));
        return r;
    }
}T;
void Solve(){
    int i;
    for(i=1;i<SZ;i++)O[i]=1;
    T.init(1,0,SZ-1);
    scanf("%d%d%d",&n,&K,&m);
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        int t = abs(x-K)+y;
        if(Set.find(pii(x,y))!=Set.end()){
            Set.erase(pii(x,y));
            O[t]++;
            if(O[t]==1)SS.erase(t);
            T.Add(1,0,SZ-1,t,SZ-1,1);
        }
        else{
            Set.insert(pii(x,y));
            O[t]--;
            if(O[t]==0)SS.insert(t);
            T.Add(1,0,SZ-1,t,SZ-1,-1);
        }
        if(SS.empty()){
            puts("0");
            continue;
        }
        t = *SS.rbegin();
        int t1 = T.Max(1,0,SZ-1,0,t);
        int t2 = T.Max(1,0,SZ-1,t,t);
        printf("%d\n",max(t + (t1-t2) - n,0));
    }
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}