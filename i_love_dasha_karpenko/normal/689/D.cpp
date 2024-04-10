#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E18;
ll A[DIM],B[DIM],lb[DIM],rb[DIM],res = 0,L[DIM],R[DIM];
struct node{
    ll time,l,ind,type;
};
vector<node > V[DIM];
bool mc(node a,node b){
    if (a.time==b.time)return a.type>b.type;
    return a.time<b.time;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    stack<ll> S;
    set<ll> s1;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        s1.insert(A[i]);
    }
    set<ll> renum;
    for(ll i = 1;i<=n;++i){
        cin>>B[i];
        if (s1.count(B[i]))renum.insert(B[i]);
    }
    ll ptr = 0;
    map<ll,ll> M;
    for(ll to:renum)M[to] = ++ptr;

    for(ll i = 1;i<=n;++i){
        while(!S.empty() && A[S.top()]<=A[i])S.pop();
        if (S.empty())lb[i] = 1;
        else lb[i] = S.top()+1;
        S.push(i);
    }
    while(!S.empty())S.pop();
    for(ll i = n;i>=1;--i){
        while(!S.empty() && A[S.top()]<A[i])S.pop();
        if (S.empty())rb[i] = n;
        else rb[i] = S.top()-1;
        S.push(i);
    }
    while(!S.empty())S.pop();
    for(ll i = 1;i<=n;++i){
        while(!S.empty() && B[S.top()]>=B[i])S.pop();
        if (S.empty())L[i] = 1;
        else L[i] = S.top()+1;
        S.push(i);
    }
    while(!S.empty())S.pop();
    for(ll i = n;i>=1;--i){
        while(!S.empty() && B[S.top()]>B[i])S.pop();
        if (S.empty())R[i] = n;
        else R[i] = S.top()-1;
        S.push(i);
    }
    for(ll i = 1;i<=n;++i){
        if (renum.count(A[i])){
            V[M[A[i]]].push_back({i,lb[i],0,0});
            V[M[A[i]]].push_back({rb[i]+1,lb[i],0,1});
        }
        if (renum.count(B[i])){
            V[M[B[i]]].push_back({i,L[i],1,0});
            V[M[B[i]]].push_back({R[i]+1,L[i],1,1});
        }
    }
    map<ll,ll> m[2];
    for(ll i = 1;i<=ptr;++i){
        ll last1 = 0,last2 = 0;
        sort(V[i].begin(),V[i].end(),mc);

        for(ll j = 0;j<V[i].size();++j){
            auto to = V[i][j];
            ll next = n+1;
            if (j!=V[i].size()-1)
            next = V[i][j+1].time;
            if (to.type==0){
                m[to.ind][to.l]++;
                if (to.ind==0)last1 = to.time;
                else last2 = to.time;
            }
            else{
                m[to.ind][to.l]--;
                if (m[to.ind][to.l]==0)m[to.ind].erase(to.l);
            }
            if (!m[0].empty() && !m[1].empty()){
                ll g = max((*m[0].begin()).first,(*m[1].begin()).first);
                res+=max(0ll,(next-to.time)*(min(last1,last2)-g+1));
            }
        }

    }
    cout<<res<<endl;

    return 0;
}