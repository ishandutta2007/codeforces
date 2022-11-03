#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=6e5+10;
const int MOD=1e9+7;


int xa,ya,xb,yb;
ll solve(){
    if (xb==0){
        if (xa==0) return 0;
        return -1;
    }
    if (xb==yb){
        if (xa==ya) return 0;
        return -1;
    }
    ll L=max((ya+yb-1)/yb,(xa+xb-1)/xb),R=1e10;
    while (L<=R){
        ll mid=(L+R)/2;
        ll add=mid*yb-ya;
        if (mid*xb-xa<=add) R=mid-1;
        else L=mid+1;
    }
    return L*yb-ya;
}
int main(){
    int test;
    cin>>test;
    while (test--){
        cin>>xa>>ya>>xb>>yb;
        cout<<solve()<<'\n';
    }
}