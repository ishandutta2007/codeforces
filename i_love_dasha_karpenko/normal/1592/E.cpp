#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e6+7;
const int LOG = 21;
int A[N],last[LOG],po[LOG],child[2][N*5],ptr = 1;
vector<int> T[N*8];
int add(int v,int bit,int num,int pos){
    if (v==0 ){
        v = ++ptr;
    }
    T[v].push_back(pos);
    if (bit>=0) {
        int cur = ((num & po[bit]) != 0);
        child[cur][v] = add(child[cur][v], bit - 1, num, pos);
    }
    return v;
}
const int INF = 1e9;
int get(int v,int bit,int num,int mx_bit,int mi_pos){
    if (v==-1 || bit+1<0)
        return INF;
    if (bit+1==mx_bit){
        int pos = lower_bound(all(T[v]),mi_pos)-T[v].begin();
        if (pos==T[v].size())
            return INF;
        return T[v][pos];
    }
    int cur = ((num&po[bit])!=0);
    return get(child[cur][v],bit-1,num,mx_bit,mi_pos);
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 0;i<LOG;++i)
        last[i] = 1;
    int pref = 0,res = 0;
    add(1,LOG-1,0,0);
    for(int i = 1;i<=n;++i){
        pref^=A[i];
        for(int bit = 0;bit<LOG;++bit){
            if (!(po[bit]&A[i]))
                last[bit] = i+1;
        }

        for(int bit = 0;bit<LOG;++bit){
            res = max(res,i-get(1,LOG-1,pref,bit,last[bit]-1));
        }
        add(1,LOG-1,pref,i);
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    po[0] = 1;
    for(int i = 1;i<LOG;++i)
        po[i] = po[i-1]*2;
    int t = 1;
    while(t--)
        solve();
}