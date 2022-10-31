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
typedef long long ll;
const int N = 2e5+7;
int A[N];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    int sum = 0;
    ll res = 0;
    for(int i = 1;i<=n;++i){
        sum+=A[i];
        if (sum>x){
            break;
        }
        res += (x-sum)/i+1;
    }
    cout<<res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}