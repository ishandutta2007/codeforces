#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
 
int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a;

    string s;
    cin >> s;
    if (s == "R") {
        b = -1;
    } else {
        b = stoi(s);
    }

    ll val = 0;
    cin >> s;
    ll deg = 1;
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (isdigit(s[i])) {
            val += (s[i] - '0') * deg;
        } else {
            val += (s[i] - 'A' + 10) * deg;
        }
        deg *= a;
    }

    if (val == 0) {
        cout << "0\n";
        return 0;
    }

    if (b != -1) {
        vector<int> vct;
        while (val) {
            vct.pb(val % b);
            val /= b;
        }
        for (int i = sz(vct) - 1; i >= 0; --i) {
            if (vct[i] >= 10) {
                cout << char(vct[i] - 10 + 'A');
            } else {
                cout << vct[i];
            }
        }
        cout << "\n";
        return 0;
    }


    while (val >= 1000) {
        cout << 'M';
        val -= 1000;
    }
    if (val >= 900) {
        cout << "CM";
        val -= 900;
    }
    if (val >= 500) {
        cout << 'D';
        val -= 500;
    }
    if (val >= 400) {
        cout << "CD";
        val -= 400;
    }
    while (val >= 100) {
        cout << 'C';
        val -= 100;
    }

    if (val >= 90) {
        cout << "XC";
        val -= 90;
    }
    while (val >= 50) {
        cout << 'L';
        val -= 50;
    }
    if (val >= 40) {
        cout << "XL";
        val -= 50;
    }
    while (val >= 10) {
        cout << 'X';
        val -= 10;
    }

    if (val >= 9) {
        cout << "IX";
        val -= 9;
    }
    if (val >= 5) {
        cout << 'V';
        val -= 5;
    }
    if (val >= 4) {
        cout << "IV";
        val -= 4;
    }
    while (val >= 1) {
        cout << 'I';
        val -= 1;
    }
    cout << "\n";

}