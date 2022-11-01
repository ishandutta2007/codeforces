#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

void solve(){   
    int n;
    cin>>n;
    multiset<int> G;
    int base_slope = 0;
    ll sum = 0;
    ll conrol = 0;
    ll start = -1e9;
    for(int i = 1;i<=n;i+=1){
        int cur;
        cin>>cur;
        cur -= i;
        base_slope -= 1;
        G.insert(cur);
        G.insert(cur);
        while(!G.empty() && G.size()+base_slope>0){
            G.erase(prev(G.end()));
        }
        sum += abs(cur-start);
    }
    ll final = 1e9;
    sum += base_slope*(final-start);
    for(int to:G){
        sum += final-to;
    }
    cout<<sum<<endl;

}
signed main() {	
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}