#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int N = 2e5+7;
int A[N];
vector<int> V[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        V[A[i]].push_back(i);
    }
    set<int> act;
    for(int i = 1;i<=n;++i){
        if (!V[i].empty()){
            act.insert(i);
        }
    }
    while(!act.empty()){
        vector<int> pos,el;
        vector<int> er;
        for(auto to:act){
            pos.push_back(V[to].back());
            el.push_back(A[V[to].back()]);
            V[to].pop_back();
            if (V[to].empty()){
                er.push_back(to);
            }

        }
        for(int to:er){
            act.erase(to);
        }
        int sz = pos.size();
        for(int i = 0;i<sz;++i){
            A[pos[i]] = el[(i+1)%sz];
        }
    }
    for(int i = 1;i<=n;++i){
        V[i].clear();
    }
    for(int i = 1 ;i<=n;++i)
        cout<<A[i]<<' ';
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}