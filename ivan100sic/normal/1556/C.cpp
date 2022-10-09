// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
ll a[1005];
ll sol = 0;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i+=2) {
        ll balance = 0, low = 1e18;
        for (int j=i+1; j<n; j+=2) {
            balance += a[j-1] - a[j];
            if (balance < 0) {
                ll q = -balance;
                ll atleast = q;
                ll atmost = low + q;
                atmost = min(atmost, a[i] + q - 1);
                atmost = min(atmost, a[j] - 1);
                sol += max(0ll, atmost - atleast + 1);
                break;
            } else {
                ll atleast = balance;
                ll atmost = low;
                atmost = min(atmost, a[i] - 1);
                atmost = min(atmost, a[j] + balance - 1);
                sol += max(0ll, atmost - atleast + 1);
            }
            low = min(low, balance);
        }
    }

    cout << sol << '\n';
}