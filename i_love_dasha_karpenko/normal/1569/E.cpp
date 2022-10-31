#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 998244353;
const int N = 35;
int po[N],scale[N];
ll PR[N];
struct node{
    ll val,last,mask;
};
vector<node > V[2];
int t = 0;
void solve(vector<int> &cur,ll val,ll msk,ll left){
    int sz = cur.size();
    if (sz==1){
        V[t].push_back({val,cur[0],msk});
        return;
    }

    for(int mask = po[sz>>1]-1;mask>=0;--mask){
        vector<int> win;
        ll subval = val;
        for(int bit = (sz>>1)-1;bit>=0;--bit){
            if (mask&po[bit])
                win.push_back(cur[bit*2]),subval = (subval+PR[sz+1]*cur[bit*2+1])%MOD;
            else win.push_back(cur[bit*2+1]),subval = (subval+PR[sz+1]*cur[bit*2])%MOD;
        }
        ll nmask = msk+po[left]*mask;
        solve(win,subval,nmask,left+(sz>>1));
    }
}
int place[N];
void deconstruct(vector<int> &cur,ll msk,ll left){
    int sz = cur.size();
    if (sz==1){
        place[cur[0]] = 2;
        return;
    }
    ll mask = (msk>>left)&(po[sz>>1]-1);
    vector<int> win;
    for(int bit = (sz>>1)-1;bit>=0;--bit){
        if (mask&po[bit])
            win.push_back(cur[bit*2]),place[cur[bit*2+1]] = sz+1;
        else win.push_back(cur[bit*2+1]),place[cur[bit*2]] = sz+1;
    }
    deconstruct(win,msk,left+(sz>>1));
}
int k,A,h;
void print(){
    for(int i = 1;i<=po[k];++i)
        cout<<place[i]<<' ';
    cout<<endl;
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scale[0] = 1;
    for(int i = 2;i<N;++i){
        scale[i] = scale[i>>1]+1;
    }

    cin>>k>>A>>h;
    po[0] = PR[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]*2, PR[i] = PR[i-1]*A%MOD;
    //////////////////////
    vector<int> H1,H2;
    for(int i = 1;i<=po[k-1];++i)
        H1.push_back(i),H2.push_back(i+po[k-1]);
    solve(H1,0,0,0);
    t^=1;
    solve(H2,0,0,0);
    {
        map<ll,ll> M;
        for(auto to:V[0]){
            M[(to.val+PR[2]*to.last)%MOD] = to.mask;
        }
        for(auto to:V[1]){
            ll cur = (to.val+PR[1]*to.last)%MOD;
            ll need = (h-cur+MOD)%MOD;
            if (M.count(need)){
                deconstruct(H1,M[need],0);
                deconstruct(H2,to.mask,0);
                place[to.last] = 1;
                print();
            }
        }
    }
    {
        map<ll,ll> M;
        for(auto to:V[1]){
            M[(to.val+PR[2]*to.last)%MOD] = to.mask;
        }
        for(auto to:V[0]){
            ll cur = (to.val+PR[1]*to.last)%MOD;
            ll need = (h-cur+MOD)%MOD;
            if (M.count(need)){
                deconstruct(H2,M[need],0);
                deconstruct(H1,to.mask,0);
                place[to.last] = 1;
                print();
            }
        }
    }
    cout<<"-1\n";
    return 0;
}