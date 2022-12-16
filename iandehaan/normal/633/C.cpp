#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int out[100000];
string inp;
ll base = 37;
ll mod = 1e9 + 7;

unordered_map<ll, int> dict;

int poss(int end) {
    if (end == 0) return 1e9;
    if (out[end] != -2) return out[end];

    ll hsh = 0;
    for (int i = end-1; i >= 0; i--) {
        hsh *= base;
        hsh += inp[i]-'a'+1;
        hsh %= mod;
        //cout << inp[i] << ' ' << hsh << endl;
        if (dict.find(hsh) != dict.end()) {
            if (poss(i) != -1) return out[end] = dict[hsh];
        }
    }
    return out[end] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin >> inp;

    for (int i = 0; i < 100000; i++) {
        out[i] = -2;
    }

    int m;
    cin >> m;
    string strs[m];
    for (int i = 0; i < m; i++) {
        cin >> strs[i];
        ll hsh = 0;
        for (int j = 0; j < strs[i].size(); j++) {
            
            char c = tolower(strs[i][j]);
            //cout << c << endl;
            hsh *= base;
            hsh += c-'a'+1;
            hsh %= mod;
        }
        //cout << hsh << ' ' << strs[i] << endl;
        dict[hsh] = i;
    }

    //cout << "here" << endl;

    stack<string> outp;
    int ind = n;
    while (poss(ind) != 1e9) {
        int blah = poss(ind);
        //cerr << blah << ' ' << ind << endl;
        if (blah != 1e9) {
            outp.push(strs[blah]);
            ind -= strs[blah].size();
        }
        else {
            break;
        }
    }

    while (!outp.empty()) {
        cout << outp.top() << ' ';
        outp.pop();
    }
    cout << endl;
}