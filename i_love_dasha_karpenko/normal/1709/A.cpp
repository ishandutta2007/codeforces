//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll

void solve(){
    int x;
    cin>>x;
    set<int> S = {x};
    bool flag = 0;
    map<int,int> M;
    for(int i = 1;i<=3;i+=1){
        int val;
        cin>>val;
        M[i] = val;
    }
    while(!M.empty()){
        bool it = 0;
        for(int to:S){
            if (M.count(to)==1){
                S.insert(M[to]);
                M.erase(to);
                it = 1;
                break;
            }
        }
        if (!it){
            break;
        }
    }

    cout<<(S.size()!=4?"NO\n":"YES\n");
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}