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
void solve(){
    int n;
    cin>>n;
    int l = n,r = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(int i = 1;i<n;i+=1){
        if (A[i]==A[i+1]){
            l = min(l,i);
            r = max(r,i);
        }
    }
    if (l>=r){
        cout<<"0\n";
        return;
    }
    cout<<max(1,r-l-1)<<endl;

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}