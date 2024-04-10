//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define endl '\n'
const int N = 1e5+7;
const int INF = 2e9;
struct robot{
    int x,r,q;
} A[N];
map<int,int> dots;
bool mc(const robot &a,const robot &b){
    return a.x<b.x;
}
const int K = 20;
map<int,super_set> M;
int in_pos[N*3];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> V;
    for(int i = 1;i<=n;++i){
        cin>>A[i].x>>A[i].r>>A[i].q;
        V.push_back(A[i].x-A[i].r);
        V.push_back(A[i].x);
        V.push_back(A[i].x+A[i].r);
    }
    sort(V.begin(),V.end());
    int p = 0;
    for(auto to:V){
        if (dots.count(to)==0){
            dots[to] = ++p;
            in_pos[p] = to;
        }
    }
    sort(A+1,A+1+n,mc);
    ll res = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > Q;
    for(int i = 1;i<=n;++i){
        while(!Q.empty() && A[i].x>in_pos[Q.top().first]){
            int pos = Q.top().second;
            Q.pop();
            M[A[pos].q].erase({dots[A[pos].x],pos});
        }
        int lb = dots[A[i].x-A[i].r],rb = dots[A[i].x+A[i].r];
        for(int h = A[i].q-k;h<=A[i].q+k;++h){
            if (M.count(h)==0 || M[h].empty())
                continue;
            res+=M[h].size()-M[h].order_of_key({lb,-INF});
        }
        M[A[i].q].insert({dots[A[i].x],i});
        Q.push({rb,i});
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}