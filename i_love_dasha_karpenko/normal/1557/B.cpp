//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
int A[N],B[N];
void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int> pos;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        B[i] = A[i];
    }
    sort(B+1,B+1+n);
    for(int i = 1;i<=n;++i)
        pos[B[i]] = i;
    int ptr = 1;
    int cnt = 0;
    while(ptr<=n){
        int cur = pos[A[ptr]];
        while(ptr<n && pos[A[ptr+1]]==cur+1){
            ++ptr;
            cur = pos[A[ptr]];
        }
        ++cnt;
        ++ptr;
    }
    if (cnt>k)
        cout<<"NO\n";
    else cout<<"YES\n";

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}