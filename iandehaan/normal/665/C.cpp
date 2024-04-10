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

    vector<char> inp;
    char c;
    while (cin >> c) {
        inp.pb(c);
    }

    for (int i = 0; i+1 < inp.size(); i++) {
        if (inp[i] == inp[i+1]) {
            if (i+2 < inp.size() && inp[i+1] == inp[i+2]) {
                if (inp[i+1] == 'z') inp[i+1] = 'a';
                else inp[i+1]++;
            } else {
                if (inp[i] == 'z') inp[i] = 'a';
                else inp[i]++;
                if (i > 0 && inp[i] == inp[i-1]) {
                    if (inp[i] == 'z') inp[i] = 'a';
                else inp[i]++;
                }
            }
        }
    }
    for (char blah : inp) {
        cout << blah;
    } cout << endl;
}