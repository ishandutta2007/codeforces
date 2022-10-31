#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
int mx = 0;
void solve(){
    int x,y;
    cin>>x>>y;
    //x = rand()*2,y = rand()*2;
    if (x==y){
        cout<<x<<endl;
        return;
    }
    if (x>y){
        cout<<x+y<<endl;
        return;
    }
    int v = (y%x)>>1;
    int kx = y-(v<<1);
    int val = v+kx;

    assert(val%x==y%val);
    cout<<val<<endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();

}