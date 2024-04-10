#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define f first
#define s second
#define maxn 1010
#define mod 1000000007
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    int tc, n;
    stack<int> p;
    cin >> tc;
    while( tc-- ){
        cin >> n;
        if( n & 1 ){ cout << 7; n -= 3; }
        while( n ){ cout << 1; n -= 2; }
        cout << '\n';
    }

    return 0;
}