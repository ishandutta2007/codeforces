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
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        int start = 0;
        while(start < n && a[start] == start) {
            ++start;
        }
        int end = n - 1;
        while(end >= 0 && a[end] == end) {
            --end;
        }
        if(start > end) {
            cout << 0 << '\n';
            continue;
        }
        bool ok = true;
        for(int i = start; i <= end; i++) {
            if(a[i] == i) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}