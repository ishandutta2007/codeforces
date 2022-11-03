#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int o = max(3, (n + 8) / 9);
    int p = max(3, (n + 8) / 9);
    for(int i = 0; i < o; ++i){
        cout << '9';
    }
    for(int i = 0; i < p - 1; ++i){
        cout << '0';
    }
    cout << "1\n";
    for(int i = 0; i < p; ++i){
        cout << '9';
    }
    cout << endl;

    return 0;
}