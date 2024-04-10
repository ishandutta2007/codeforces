#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
const int N = 2e5+7;
const int SQRT = 450;

int X[N],Y[N],add[N],cs[N];
int sum[SQRT][SQRT];
int res = 0;
int n,m,mom = 0;
int act(int pos,int t){
    return !((t-cs[pos])%(X[pos]+Y[pos])<X[pos]);
}
void add1(int pos,int delta){
    int start = cs[pos];
    start%=(X[pos]+Y[pos]);
    for(int i = X[pos];i<X[pos]+Y[pos];++i){
        int val = i+start;
        if (val>=X[pos]+Y[pos])
            val-=X[pos]+Y[pos];
        sum[X[pos]+Y[pos]][val]+=delta;
    }
}
void add2(int pos,int delta){
    res+=act(pos,mom)*delta;
    int start = cs[pos];
    for(int i = start+X[pos];i<=m;i+=X[pos]+Y[pos])
        add[i]+=delta;
    for(int i = start+X[pos]+Y[pos];i<=m;i+=X[pos]+Y[pos])
        add[i]-=delta;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>X[i]>>Y[i];
    }
    for(int i = 1;i<=m;++i){
        mom = i;
        res+=add[i];
        int type;
        cin>>type;
        if (type==1)
            type = 1;
        else type = -1;
        int pos;
        cin>>pos;
        if (type==1){
            cs[pos] = i;
        }
        if (X[pos]+Y[pos]<SQRT)
            add1(pos,type);
        else add2(pos,type);
        int r = 0;
        for(int val = 1;val<SQRT;++val){
            r+=sum[val][i%val];
        }
        cout<<r+res<<endl;
    }

    return 0;
}