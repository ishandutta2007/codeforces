#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
const int MAXN = 1e5;
#define set fdgfd
int A[N];
int T[2][N*4],mod[2][N*4],sign[2][N],put[2][N*4];
void push(int t,int type){
    if (put[type][t]!=-1){
        for(auto c:{t*2+1,t*2+2}){
            put[type][c] = put[type][t];

            T[type][c] = put[type][t];
            mod[type][c] = 0;
        }
        put[type][t] = -1;
    }
    if (mod[type][t]){
        for(auto c:{t*2+1,t*2+2}){
            T[type][c] ^= 1;
            mod[type][c] ^= 1;
            if (put[type][c]!=-1){
                put[type][c]^=1;
                mod[type][c] = 0;
            }
        }
        mod[type][t] = 0;
    }
}
void update(int t,int tl,int tr,int l,int r,int type){
    if (l>tr || tl>r || l>r)
        return;
    if (l<=tl && tr<=r){
        if (put[type][t]!=-1){
            put[type][t]^=1;
        }
        else{
            mod[type][t]^=1;
        }
        T[type][t]^=1;
        return;
    }
    push(t,type);
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,l,r,type);
    update(t*2+2,tm+1,tr,l,r,type);
}
void set(int t,int tl,int tr,int l,int r,int val,int type){
    if (l>tr || tl>r || l>r)
        return;
    if (l<=tl && tr<=r){
        T[type][t] = put[type][t] = val;
        mod[type][t] = 0;
        return;
    }
    push(t,type);
    int tm = (tl+tr)>>1;
    set(t*2+1,tl,tm,l,r,val,type);
    set(t*2+2,tm+1,tr,l,r,val,type);
}
void getvals(int t,int tl,int tr){
    if (tl==tr){
        sign[0][tl] = T[0][t];
        sign[1][tl] = T[1][t];
        return;
    }
    push(t,0);
    push(t,1);
    int tm = (tl+tr)>>1;
    getvals(t*2+1,tl,tm);
    getvals(t*2+2,tm+1,tr);
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    memset(put,-1,sizeof(put));
    while(q--){

        char sign;
        int num;
        cin>>sign>>num;
        if (num<0){
            num = -num;
            if (sign=='<') {
                set(0,1,MAXN,num+1,MAXN,1,0);
                set(0,1,MAXN,num+1,MAXN,0,1);
            }
            else{
                update(0,1,MAXN,1,num-1,0);
                update(0,1,MAXN,1,num-1,1);
                set(0,1,MAXN,num,MAXN,0,0),set(0,1,MAXN,num,MAXN,1,1);
            }
        }
        else if (num>0){
            if (sign=='>') {
                set(0,1,MAXN,num+1,MAXN,1,1);
                set(0,1,MAXN,num+1,MAXN,0,0);
            }
            else{
                update(0,1,MAXN,1,num-1,1);
                update(0,1,MAXN,1,num-1,0);
                set(0,1,MAXN,num,MAXN,0,1),set(0,1,MAXN,num,MAXN,1,0);
            }
        }
        else{
            if (sign=='>'){
                set(0,1,MAXN,1,MAXN,1,1);
                set(0,1,MAXN,1,MAXN,0,0);
            }
            else{
                set(0,1,MAXN,1,MAXN,0,1);
                set(0,1,MAXN,1,MAXN,1,0);
            }
        }

    }
    getvals(0,1,MAXN);
    for(int i = 1;i<=n;++i){
        if (A[i]<0){
            if (sign[0][-A[i]])
                cout<<-A[i]<<' ';
            else cout<<A[i]<<' ';
        }
        else{
            if (sign[1][A[i]])
                cout<<-A[i]<<' ';
            else cout<<A[i]<<' ';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}