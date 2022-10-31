#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    for(int st = 0;st<n;++st){
        for(int j = 0;j<st;++j)
            cout<<"()";
        int left = n-st;
        for(int i = 0;i<left;++i)
            cout<<'(';
        for(int i = 0;i<left;++i)
            cout<<')';
        cout<<endl;
    }
    //cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}