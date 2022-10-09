// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[200005];
int nadesno[200005], nalevo[200005];

bool fpw(int l, int r) {
    if (l == r) return true;

    if (a[l] == a[r]) {
        if (nadesno[l] % 2 == 1) return true;
        if (nalevo[r] % 2 == 1) return true;
        return false;
    }

    if (a[l] > a[r]) {
        // ako uzmemo vece, moramo da nastavimo da uzimamo vece do kraja
        if (nadesno[l] % 2 == 1) return true;

        // nista od toga, moramo da uzmemo manje
        if (a[r-1] > a[r]) {
            // nastavlja se igra uobicajeno
            return !fpw(l, r-1);
        } else {
            // posle r mora da se uzme od l samo
            return nadesno[l] % 2 == 0; // true
        }
    } else {
        if (nalevo[r] % 2 == 1) return true;

        if (a[l+1] > a[l]) {
            return !fpw(l+1, r);
        } else {
            return true;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    nalevo[0] = 1;
    for (int i=1; i<n; i++) {
        nalevo[i] = a[i] < a[i-1] ? nalevo[i-1] + 1 : 1;
    }

    nadesno[n-1] = 1;
    for (int i=n-2; i>=0; i--) {
        nadesno[i] = a[i] < a[i+1] ? nadesno[i+1] + 1 : 1;
    }

    cout << (fpw(0, n-1) ? "Alice\n" : "Bob\n");
}