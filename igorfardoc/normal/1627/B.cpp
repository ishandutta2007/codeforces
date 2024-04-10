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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        multiset<int> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                s.insert(max(max(i + j, abs(i - (n - 1)) + j), max(abs(i - (n - 1)) + abs(j - (m - 1)), i + abs(j - (m - 1)))));
            }
        }
        for(int i = 0; i < n * m; i++) {
            cout << *(s.begin()) << ' ';
            s.erase(s.begin());
        }
        cout << '\n';
    }
}