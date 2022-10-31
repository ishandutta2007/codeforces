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

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    if (s[n-1]=='A'){
        cout<<"NO\n";
        return;
    }
    int sum = 0;
    for(int i = 0;i<n;++i){
        sum += s[i]=='A'?1:-1;
        if (sum<0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}