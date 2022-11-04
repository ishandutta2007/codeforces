#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, a, b;
    cin >> n >> a >> b;
    vi mass(n, 1);
    for(int i = 0; i < a; i++) {
        int b;
        cin >> b;
    }
    for(int i = 0; i < b; i++) {
        int b;
        cin >> b;
        --b;
        mass[b] = 2;
    }
    for(const auto& el : mass) {
        cout << el << ' ';
    }
}