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
    int n;
    cin>>n;
    int odd = 0;
    for(int i = 1;i<=n;++i){
        int len; cin>>len;
        odd^=(len-1)%2;
    }
    if (odd){
        cout<<"errorgorn\n";
    }
    else{
        cout<<"maomao90\n";
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