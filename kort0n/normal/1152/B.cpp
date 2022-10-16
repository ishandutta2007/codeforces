#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    vector<int> operation;
    while(true) {
        int n = 0;
        int val = 1;
        while(val < x) {
            n++;
            val *= 2;
        }
        if(val == x) {
            operation.push_back(n + 1);
            break;
        }
        cerr << x << " " << val << endl;
        x = x ^ (val-1);
        operation.push_back(n);
        if(x == 0) break;
        x++;
    }
    cout << operation.size() * 2 - 1 << endl;
    for(int i = 0; i < operation.size(); i++) cout << operation[i] << " ";
    cout << endl;
    return 0;
}