#include <bits/stdc++.h>

using namespace std;
typedef long long big;
const int DIM = 4E5+7;

void solve(){
    int xa,ya,xb,yb,xf,yf;
    cin>>xa>>ya>>xb>>yb>>xf>>yf;
    int res = abs(xa-xb)+abs(ya-yb);
    if ( (xa==xb && xa==xf && min(ya,yb)<=yf && yf<=max(ya,yb)) || (ya==yb && ya==yf && min(xa,xb)<=xf && xf<=max(xa,xb))){
        res+=2;
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}