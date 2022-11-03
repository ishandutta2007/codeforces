#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007

int main()
{
    int n,m;
    cin >> n >> m;
    vector<char> v(n,0),w(n,0);
    ll ans1 = n,ans2 = n;
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        x--;
        y--;
        if(!v[x]){
            ans1--;
        }
        if(!w[y]){
            ans2--;
        }
        v[x] = 1;
        w[y] = 1;
        cout << ans1*ans2 << " ";
    }
}