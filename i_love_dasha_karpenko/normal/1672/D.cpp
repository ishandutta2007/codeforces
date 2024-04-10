#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int N = 2e5+7;
int A[N],B[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(int i = 1;i<=n;++i){
        cin>>B[i];
    }
    map<int,int> ph;
    int ptr = n;
    for(int i = n;i>=1;--i){
        if (i>1 && B[i]==B[i-1]){
            ph[B[i]]++;
            continue;
        }
        while ( B[i]!=A[ptr]){
            if (ph[A[ptr]]==0){
                cout<<"NO\n";
                return;
            }
            ph[A[ptr]]--;
            --ptr;
        }
        if (B[i]!=A[ptr]) {
            cout << "NO\n";
            return;
        }
        --ptr;
    }
    while(ptr>0){
        if (ph[A[ptr]]==0){
            cout<<"NO\n";
            return;
        }
        ph[A[ptr]]--;
        --ptr;
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