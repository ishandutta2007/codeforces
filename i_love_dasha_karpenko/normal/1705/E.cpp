#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
using namespace std;
const int N = 4e5+7;
const int MAXN = 4e5;
const int INF = 1e9+7;
int mod[N*2],T[N*2][2],A[N];
void push(int t,int tl,int tr){
    if (mod[t]==-1){
        return;
    }
    int tm = (tl+tr)/2;
    mod[t+1] = mod[t+(tm-tl+1)*2] = mod[t];
    T[t+1][mod[t]^1] = T[t+(tm-tl+1)*2][mod[t]^1] = INF;
    T[t+1][mod[t]] = tl;
    T[t+(tm-tl+1)*2][mod[t]] = tm+1;
    mod[t] = -1;
}
int get(int t,int tl,int tr,int l,int r,bool symb){
    if (tl>r || l>tr){
        return INF;
    }
    if (l<=tl && tr<=r){
        return T[t][symb];
    }
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    int ret = get(t+1,tl,tm,l,r,symb);
    if (ret==INF){
        ret = get(t+(tm-tl+1)*2,tm+1,tr,l,r,symb);
    }
    return ret;
}
int gl(int t,int tl,int tr){
    if (T[t][1]==INF){
        return INF;
    }
    if (tl==tr){
        return tl;
    }
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    int ret = gl(t+(tm-tl+1)*2,tm+1,tr);
    if (ret==INF){
        ret = gl(t+1,tl,tm);
    }
    return ret;
}
void update(int t,int tl,int tr,int l,int r,bool symb){
    if (tl>r || l>tr){
        return;
    }
    if (l<=tl && tr<=r){
        T[t][symb^1] = INF;
        T[t][symb] = tl;
        mod[t] = symb;
        return;
    }
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    update(t+1,tl,tm,l,r,symb);
    update(t+(tm-tl+1)*2,tm+1,tr,l,r,symb);
    for(int c = 0;c<2;c+=1){
        T[t][c] = min(T[t+1][c],T[t+(tm-tl+1)*2][c]);
    }
}
void add(int bit,int col){
    int nxt = get(0,1,MAXN,bit,MAXN,col^1);
    update(0,1,MAXN,bit,nxt,col^1);
    update(0,1,MAXN,nxt,nxt,col);
}
void solve(){
    memset(mod,-1,sizeof(mod));
    int n,q;
    cin>>n>>q;
    update(0,1,MAXN,1,MAXN,0);
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        add(A[i],1);
    }
    for(int qe = 1;qe<=q;qe+=1){
        int pos,val;
        cin>>pos>>val;
        add(A[pos],0);
        A[pos] = val;
        add(A[pos],1);
        cout<<gl(0,1,MAXN)<<endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}