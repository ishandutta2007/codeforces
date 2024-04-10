#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll base = 27;
const ll DIM = 1E6;
ll gi(char &ch){
    if (ch=='_')return 0;
    return ll(ch-'a'+1);
}
ll trans(string &s){
    ll ret = 0;
    for(char to:s)ret = ret*base+gi(to);
    return ret;
}
ll A[DIM],pos[DIM],in_deg[DIM],ans[DIM];
vector<ll> G[DIM];
void NO(){
    cout<<"NO\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i = 1;i<=n;++i){
        string s;
        cin>>s;
        A[i] = trans(s);
        pos[A[i]] = i;
    }
    ll sz = 1<<k;
    for(ll i = 1;i<=m;++i){
        string s;
        cin>>s;
        vector<ll> V;
        for(ll mask = 0;mask<sz;++mask){
            ll nmask = 0;
            for(ll j = 0;j<k;++j){
                nmask*=base;
                if (mask&(1<<j))nmask+=gi(s[j]);
            }
            if (pos[nmask]!=0)
                V.push_back(nmask);
        }
        ll need;
        cin>>need;
        need = A[need];
        //if (pos[need]==0)NO();
        ll flag = 0;
        for(ll to:V){
            if (to!=need){
                G[need].push_back(to);
                in_deg[to]++;

            }
            else flag = 1;
        }
        if (!flag)NO();
    }
    stack<ll > Q;
    for(ll i = 0;i<DIM;++i){
        if (pos[i]!=0 && in_deg[i]==0)
            Q.push(i);
    }
    ll ptr = 0;
    while(!Q.empty()){
        ll v = Q.top();

        ans[++ptr] = pos[Q.top()];
        Q.pop();
        for(ll to:G[v]){
            in_deg[to]--;
            if (in_deg[to]==0)
            Q.push(to);
        }


    }
    if (ptr!=n)NO();
    cout<<"YES\n";
    for(ll i = 1;i<=n;++i)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}