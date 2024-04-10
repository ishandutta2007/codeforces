//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM],h[DIM],w[DIM];
void NO(){
    cout<<"-1\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll cur = 1;
    vector<pair<ll,ll> > V[4];
    vector<pair<ll,ll> > ans;
    for(ll i = n;i>=1;--i){
        if (A[i]==1){
            if (h[cur])++cur;
            if (cur>n)NO();
            V[1].push_back({i,cur});
            w[i]++;
            h[cur]++;

            ans.push_back({i,cur});
            ++cur;
        }
        if (A[i]==2){
            if (!V[1].empty()){
                auto to = V[1].back();
                V[1].pop_back();
                pair<ll,ll> it = {i,to.second};
                w[i]++;
                h[to.second]++;
                V[2].push_back(it);
                ans.push_back(it);
            }
            else{
                NO();
            }
        }
        else if (A[i]==3){
            if (!V[3].empty()){
                auto to = V[3].back();
                V[3].pop_back();
                if (h[cur])++cur;
                if (cur>n)NO();
                ans.push_back({to.first,cur});
                ans.push_back({i,cur});
                V[3].push_back({i,cur});
                ++cur;
            }
            else if (!V[2].empty()){
                auto to = V[2].back();
                V[2].pop_back();
                if (h[cur])++cur;
                if (cur>n)NO();
                ans.push_back({to.first,cur});
                ans.push_back({i,cur});
                V[3].push_back({i,cur});
                ++cur;
            }
            else if (!V[1].empty()){
                auto to = V[1].back();
                V[1].pop_back();
                if (h[cur])++cur;
                if (cur>n)NO();
                ans.push_back({to.first,cur});
                ans.push_back({i,cur});
                V[3].push_back({i,cur});
                ++cur;
            }
            else NO();
        }
    }
    cout<<ans.size()<<endl;
    for(auto to:ans)cout<<n-to.second+1<<' '<<to.first<<endl;
    return 0;
}