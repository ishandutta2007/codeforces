#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k == 3) {
            if(n%2) cout << 1 << ' ' << (n-1)/2 << ' ' << (n-1)/2 << '\n';
            else if(n%4) cout << 2 << ' ' << (n-2)/2 << ' ' << (n-2)/2 << '\n';
            else {
                cout << n/4 << ' ' << n/4 << ' ' << n/2 << '\n';
            }
        }
        else if(k == 4) {
            if(n%2) {
                if((n+1)%4) cout << (n-1)/2 << ' ' << (n-1)/4 << ' ' << (n-1)/4 << ' ' << 1 << '\n';
                else cout << (n-3)/2 << ' ' << (n-3)/2 << ' ' << 2 << ' ' << 1 << '\n';
            }
            else {
                cout << 1 << ' ' << 1 << ' ' << (n-2)/2 << ' ' << (n-2)/2 << '\n';
            }
        }
        else {
            if((n-k)%2) {
                if(((n-k+1)%4) == 0) {
                    cout << 2 << ' ';
                    for(int i = 1; i < (k-2); i++) cout << 1 << ' ';
                    cout << (n-k+1)/2 << ' ' << (n-k+1)/2 << '\n';
                }
                else {
                    cout << 2 << ' ' << 2 << ' ' << 2 << ' ';
                    for(int i = 3; i < (k-2); i++) cout << 1 << ' ';
                    cout << (n-k-1)/2 << ' ' << (n-k-1)/2 << '\n';
                }
            }
            else {
                for(int i = 0; i < (k-2); i++) cout << 1 << ' ';
                cout << (n-k+3)/2 << ' ' << (n-k+3)/2 << '\n';
            }
        }
    }
}