#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inp;
    cin >> inp;

    int zeros = 0;
    int ones = 0;
    int qs = 0;
    int n = inp.size();
    for (int i = 0; i < n; i++) {
        if (inp[i] == '0') zeros++;
        else if (inp[i] == '1') ones++;
        else qs++;
    }

    vector<string> out;
    if (zeros + qs > ones) out.pb("00");

    // 01
    if (zeros + qs >= ones-1 && ones + qs >= zeros) {
        if (inp[n-1] == '1' || inp[n-1] == '?') {
            if (inp[n-1] == '1') {
                if (qs > 0 || zeros > 0) out.pb("01");
            } else {
                if (zeros + qs - 2 >= ones-1) out.pb("01");
            }
        }
        if (inp[n-1] == '0' || inp[n-1] == '?') {
            if (inp[n-1] == '0') {
                if (qs > 0 || ones > 0) out.pb("10");
            } else {
                if (ones + qs - 2 >= zeros) out.pb("10");
            }
        }
    }

    if (ones + qs > zeros+1) out.pb("11");

    for (string b : out) cout << b << endl;
}