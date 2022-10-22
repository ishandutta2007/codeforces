#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << "Division ";
        if(n <= 1399) cout << "4\n";
        else if(n <= 1599) cout << "3\n";
        else if(n <= 1899) cout << "2\n";
        else cout << "1\n";
    }
}