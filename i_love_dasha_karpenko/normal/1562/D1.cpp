#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;

int A[N],pref[N];

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch=='-')
            A[i] = -1;
        else A[i] = 1;
        pref[i] = pref[i-1]+(i%2==0?-A[i]:A[i]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int df = abs(pref[r]-pref[l-1]);
        if (df==0)
            cout<<"0\n";
        else if (df%2)
            cout<<"1\n";
        else cout<<"2\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}