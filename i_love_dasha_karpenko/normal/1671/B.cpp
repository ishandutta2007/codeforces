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
const int N = 2e5+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    bool flag = 0;    
    for(int dl = -1;dl<=1;++dl){
        int prev = A[1]+dl;
        bool bad = 0;
        for(int i = 1;i<=n;++i){
            if (abs(A[i]-(prev+1))>1){
                bad = 1;
                break;
            }
            ++prev;
        }
        flag = max(flag,!bad);
    }
    cout<<(flag?"YES\n":"NO\n");
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}