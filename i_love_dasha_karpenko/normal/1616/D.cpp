#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 5e4+7;
const int MXN = 200;
int A[N];
ll pref[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    int x;
    cin>>x;
    for(int i = 1;i<=n;++i){
        A[i]-=x;
        pref[i] = pref[i-1]+A[i];
    }
    int res = 0;
    int ptr = 1;
    while(ptr<=n){
        ll mi = -pref[ptr-1];
        ++res;
        while(ptr+1<=n && mi+pref[ptr+1]>=0){
            ++ptr;
            mi = min(mi,-pref[ptr-1]);
            ++res;
        }
        ptr+=2;
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}