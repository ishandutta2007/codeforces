#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int N = 307;
int dist[N][N];
void solve() {
    int x,y;
    cin>>x>>y;
    int sq = sqrt(x*x+y*y);
    if (x==0 && y==0)
        cout<<"0\n";
    else if (sq*sq==x*x+y*y)
        cout<<"1\n";
    else cout<<"2\n";
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}