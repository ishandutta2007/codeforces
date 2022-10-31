#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int LOG = 20;
const int INF = 1e9;
const int N = 1<<LOG;
int cnt[N],po[LOG];
struct tnode{
    int lval,rval,dif;
    int cld[2];
    tnode (int cnt = 0){
        if (cnt>0){
            lval = rval = 0;
            if (cnt<2)
                dif = INF;
            else dif = 0;
        }
        else{
            lval = rval = -1;
            dif = INF;
        }
    }
    tnode (tnode l,tnode r,int bit,int i1,int i2){
        if (l.lval==-1 || r.lval==-1){
            if (l.lval==-1 && r.lval==-1){
                lval = rval = -1;
                dif = INF;
            }
            else if (l.lval==-1){
                lval = r.lval+po[bit];
                rval = r.rval+po[bit];
                dif = r.dif;
            }
            else{
                lval = l.lval;
                rval = l.lval;
                dif = l.dif;
            }
            cld[0] = i1;
            cld[1] = i2;
            return;
        }
        lval = l.lval,rval = r.rval+po[bit],dif = min({l.dif,r.dif,r.lval+po[bit]-l.rval});
        cld[0] = i1,cld[1] = i2;
    }
};
tnode T[N*4];
int ans[N];
void build(int t,int bit,int num){
    if (bit==0){
        T[t] = tnode(cnt[num]);
        return;
    }
    build(t*2+1,bit-1,num);
    build(t*2+2,bit-1,num+po[bit-1]);
    T[t] = tnode(T[t*2+1],T[t*2+2],bit-1,t*2+1,t*2+2);
}
void swap_level(int t,int bit,int need){
    if (bit-1==need){
        swap(T[t].cld[0],T[t].cld[1]);
        T[t] = tnode(T[T[t].cld[0]],T[T[t].cld[1]],bit-1,T[t].cld[0],T[t].cld[1]);
        return;
    }
    swap_level(T[t].cld[0],bit-1,need);
    swap_level(T[t].cld[1],bit-1,need);
    T[t] = tnode(T[T[t].cld[0]],T[T[t].cld[1]],bit-1,T[t].cld[0],T[t].cld[1]);
}
int cur = 0;
int n,k;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(int i = 1;i<LOG;++i)
        po[i] = po[i-1]*2;

    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        ++cnt[x];
    }
    build(0,k,0);
    int prev = 0;
    ans[0] = T[0].dif;
    int real = 0;
    for(int i = (1<<k)-1;i>0;--i){
        int cur = i^(i>>1);
        int pr = prev^cur;
        int bit = 0;
        while(po[bit]!=pr)
            ++bit;
        real^=po[k-1-bit];
        swap_level(0,k,k-1-bit);
        ans[real] = T[0].dif;
        prev = cur;
    }
    for(int i = 0;i<(1<<k);++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}