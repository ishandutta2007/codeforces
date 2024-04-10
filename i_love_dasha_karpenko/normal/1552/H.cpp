#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;
typedef unsigned long long ull;

//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
const int DIM = 200;
int l1,r1,l2,r2;
int ask(int div){
    cout<<"? "<<(DIM/div)*DIM<<endl;
    for(int i = 1;i<=DIM;++i)
        for(int j = 1;j<=DIM;++j)
            if (i%div==0)
                cout<<i<<' '<<j<<' ';
    cout<<endl;

    int ret = 0;

    cin>>ret;
    /*for(int i = 1;i<=DIM;++i)
        for(int j = 1;j<=DIM;++j)
            if (i%div==0)
                if (l1<=i && i<=r1 && l2<=j && j<=r2)
                    ++ret;
*/
    return ret;
}
void solve(){
    int total = ask(1);
    int l = 1,r = 8;
    int val,prev = total;
    while(l!=r){
        int mid = (l+r)>>1;
        int ret = ask(1<<mid);
        if (total==ret*(1<<mid))
            l = mid+1,prev = ret;
        else r = mid,val = ret;
    }
    int height = abs(prev-(val<<1));
    int width = total/height;
    cout<<"! "<<(height+width-2)*2<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}