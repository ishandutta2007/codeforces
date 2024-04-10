#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1E6+7;
const ll INF = 1E18;

ll gi(char ch){
    if (ch=='(')return 0;
    return 1;
}
ll A[DIM];
struct node{
    ll len,op,cl;
} T[DIM*4];
node F(node a,node b){
    ll nl = min(a.op,b.cl);
    node c = {nl+a.len+b.len,a.op+b.op-nl,a.cl+b.cl-nl};
    return c;
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = {0,0,0};
        if (A[tl]==0)T[t].op++;
        else T[t].cl++;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = F(T[t*2+1],T[t*2+2]);
}
node query(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return node{0,0,0};
    if (l<=tl && tr<=r)return T[t];
    ll tm = (tl+tr)/2;
    return F(query(t*2+1,tl,tm,l,r),query(t*2+2,tm+1,tr,l,r));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    ll n = s.length();
    for(ll i = 0;i<s.length();++i){
       A[i+1] = gi(s[i]);
    }
    buildtree(0,1,n);
    ll m;
    cin>>m;
    while(m--){
        ll l,r;
        cin>>l>>r;
        cout<<query(0,1,n,l,r).len*2<<endl;
    }
    return 0;
}