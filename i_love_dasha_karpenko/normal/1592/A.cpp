#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
void solve(){
    int n,H;
    cin>>n>>H;
    pair<int,int> mx = {0,0};
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        mx.second = max(mx.second,val);
        if (mx.first<mx.second)
            swap(mx.first,mx.second);
    }
    int cnt = H/(mx.first+mx.second);
    int moves = cnt*2;//
    H-=cnt*(mx.first+mx.second);
    if (H>0){
        H-=mx.first;
        ++moves;
    }
    if (H>0){
        H-=mx.first;
        ++moves;
    }
    cout<<moves<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}