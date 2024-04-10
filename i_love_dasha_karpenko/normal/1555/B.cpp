//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void solve(){
    int W,H;
    cin>>W>>H;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int w,h;
    cin>>w>>h;
    int res = 1E9;
    if (x1>=w || y1>=h){
        res = 0;
    }
    else{
        if (x2-x1+w<=W)
            res = min({res,max(0,w-x1),max(0,x2-W+w)});
        if (y2-y1+h<=H)
            res = min({res,max(0,h-y1),max(0,y2-H+h)});
    }
    if (res==1E9)
        cout<<-1<<endl;
    else cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}