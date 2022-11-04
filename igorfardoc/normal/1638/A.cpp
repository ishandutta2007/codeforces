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
        }
        bool ok = false;
        for(int i = 0; i < n; i++) {
            if(a[i] != i + 1) {
                ok = true;
                for(int j = 0; j < i; j++) {
                    cout << a[j] << ' ';
                }
                int pos;
                for(int j = i + 1; j < n; j++) {
                    if(a[j] == i + 1) {
                        pos = j;
                        break;
                    }
                }
                for(int j = pos; j >= i; j--) {
                    cout << a[j] << ' ';
                }
                for(int j = pos + 1; j < n; j++) {
                    cout << a[j] << ' ';
                }
                break;
            }
        }
        if(!ok) {
            for(const auto& el : a) {
                cout << el << ' ';
            }
        }
        cout << '\n';
    }
}