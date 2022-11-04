#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define mx 7001



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<bitset<mx>> to_get(mx);
    vector<bitset<mx>> curr(mx);
    for(int i = mx - 1; i >= 1; i--) {
        to_get[i][i] = true;
        for(int j = i + i; j < mx; j+=i) {
            to_get[i] = to_get[i] ^ to_get[j];
        }
    }
    for(int i = 1; i < mx; i++) {
        for(int j = i; j < mx; j+=i) {
            curr[j][i] = true;
        }
    }
    vector<bitset<mx>> a(n);
    for(int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if(c == '1') {
            int x, v;
            cin >> x >> v;
            --x;
            a[x] = curr[v];
        } else if(c == '2'){
            int x, y, z;
            cin >> x >> y >> z;
            --x;
            --y;
            --z;
            a[x] = a[y] ^ a[z];
        } else if(c == '3') {
            int x, y, z;
            cin >> x >> y >> z;
            --x;
            --y;
            --z;
            a[x] = a[y] & a[z];
        } else {
            int x, v;
            cin >> x >> v;
            --x;
            cout << (a[x] & to_get[v]).count() % 2;
        }
    }
}