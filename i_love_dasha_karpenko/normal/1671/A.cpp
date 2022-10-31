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
void solve(){
    string s;
    cin>>s;
    char prev = s[0];
    int cnt = 0;
    for(auto to:s){
        if (to==prev)
            ++cnt;
        else{
            if (cnt<2){
                cout<<"NO\n";
                return;
            }
            cnt = 1;
            prev = to;
        }    
    }
    if (cnt<2){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}