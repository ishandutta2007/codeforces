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
    reverse(begin(inp), end(inp));
    int out = 0;
    bool seen = false;
    for (int i = 0; i < inp.size()-1; i++) {
        if (i % 2 == 0) out++;
        if (inp[i] == '1') seen = true;
    }
    if (seen && (inp.size()%2)==1) out++;
    cout << out << endl;
}