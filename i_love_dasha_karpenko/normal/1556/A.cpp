#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int c,d;
    cin>>c>>d;
    if (c==d && c==0){
        cout<<"0\n";
        return;
    }
    int dif = c-d;
    if (dif%2){
        cout<<"-1\n";
        return;
    }
    if (dif==0){
        cout<<"1\n";
        return;
    }
    int a = dif/2,b = -dif/2;
    if (a!=c || b!=d)
        cout<<"2\n";
    else cout<<"1\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    //t = 1;
    while(t--)
        solve();
    return 0;
}