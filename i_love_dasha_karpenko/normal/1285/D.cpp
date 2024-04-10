#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10E4 +7;
const ll INF = 10E17+7;

struct node{
    ll bit,next[2];
};
pp ans;
ll apos = 0,po[40];
node A[DIM*32];
void push(ll pos,stack<ll> &S){
    if (S.empty())return;
    ll to = S.top();
    S.pop();
    if (A[pos].next[to]==-1){
        apos++;
        A[pos].next[to] = apos;
        A[A[pos].next[to]].next[0] = A[A[pos].next[to]].next[1] = -1;
    }
    push(A[pos].next[to],S);
}
void add(ll val){
    stack<ll> S;
    forn(i,30){
        S.push(val%2);
        val/=2;
    }
    push(0,S);
}
void solve(ll pos,ll res,ll bit,ll mask){
    ll can0=0,can1=0;
    if(A[pos].next[0]!=-1)can0 = 1;
    if(A[pos].next[1]!=-1)can1 = 1;
    if (can1==can0 &&can1==1){
        solve(A[pos].next[0],res+po[bit],bit-1,mask*2+1);
        solve(A[pos].next[1],res+po[bit],bit-1,mask*2);
    }
    else if (can1==1){
        solve(A[pos].next[1],res,bit-1,mask*2+1);
    }
    else if (can0==1){
        solve(A[pos].next[0],res,bit-1,mask*2);
    }
    else{
        if (ans.fi>res){
            ans.fi = res;
            ans.sc = mask;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    po[0] = 1;
    ans = {INF,INF};
    forn(i,30)po[i] = po[i-1]*2;
    A[0].next[0]=A[0].next[1] = -1;
    forn(i,n){
        ll x; cin>>x;
        add(x);
    }
    solve(0,0,29,0);
    cout<<ans.fi<<endl;
    return 0;
}