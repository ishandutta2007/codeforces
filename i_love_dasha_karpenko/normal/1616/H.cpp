#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)
#define bt(mask,x) ( (mask & (1<<x) ) >> x )
const int MOD = 998244353;
const int N = 15e4+7;
ll po[N];
void split(vector<int> &vec,vector<int> *spl,int mx_bit){
    for(int to:vec){
        spl[bt(to,mx_bit)].push_back(to);
    }
}
int calc(vector<int> &A,vector<int> &B,int x,int mx_bit){
    if (A.size()==0 || B.size()==0)
        return 0;
    if (mx_bit<0)
        return (po[A.size()]-1)*(po[B.size()]-1);
    vector<int> a[2],b[2];
    split(A,a,mx_bit);
    split(B,b,mx_bit);
    ll ret = 0;
    if (bt(x,mx_bit)){
        ll m1 = calc(a[1],b[0],x,mx_bit-1);
        ll m2  = calc(a[0],b[1],x,mx_bit-1);
        ret+=(m1+po[a[1].size()]+po[b[0].size()]-2+1)*(m2+po[a[0].size()]+po[b[1].size()]-2+1)-1-po[A.size()]-po[B.size()]+2;
        ret%=MOD;
        if (ret<0)
            ret+=MOD;
    }
    else{
        ret += calc(a[0],b[0],x,mx_bit-1)+calc(a[1],b[1],x,mx_bit-1);
        ret%=MOD;
    }
    return ret;
}

void solve() {
    int n, x;
    cin >> n >> x;
    int mx_bit = 0;
    while((1<<(mx_bit+1))<=x)
        ++mx_bit;
    int pref_mask = (1<<30)-(1<<(mx_bit+1));
    map<int,vector<int> > M;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        M[val&pref_mask].push_back(val);
    }
    ll res = 0;
    for(auto [pref,vec]:M){
        vector<int> a,b;
        for(int to:vec)
            if (bt(to,mx_bit))
                b.push_back(to);
            else a.push_back(to);
        res+=calc(a,b,x,mx_bit)+(po[a.size()]-1)+(po[b.size()]-1);
        res%=MOD;
    }
    cout<<res<<endl;
}
int main(){
    po[0] = 1;
    for(int i = 1;i<N;++i){
        po[i] = po[i-1]<<1;
        if (po[i]>=MOD)
            po[i]-=MOD;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;

    while(t--)
        solve();
}