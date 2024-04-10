#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = sz(s);
        int total0 = 0;
        for (char c : s) if (c == '0') total0++;

        int ptr2 = 1;
        int remzeroes = 0;
        
        int numones = n-total0;
        if (s[0] == '0') remzeroes = 1;
        else numones--;
        int out = total0;
        out = min(out, max(remzeroes, numones));
        while (ptr2 < n && remzeroes < numones) {
            ptr2++;
            if (s[ptr2-1] == '0') remzeroes++;
            else numones--;
            out = min(out, max(remzeroes, numones));
        }
        
        for (int ptr1 = 0; ptr1 < n; ptr1++) {
            if (s[ptr1] == '0') remzeroes--;
            else numones++;
            // eat [0, ptr1]
            // eat [ptr2, n]
            out = min(out, max(remzeroes, numones));
            while (ptr2 < n && remzeroes < numones) {
                // move ptr2 back
                ptr2++;
                if (s[ptr2-1] == '0') remzeroes++;
                else numones--;
                out = min(out, max(remzeroes, numones));
                //cout << out << ' ' << ptr1 << ' ' << ptr2 << ' ' << remzeroes << ' ' << numones << endl;
            }
        }
        cout << out << '\n';

        // cost to remove certain amount of zeroes
        /*int costs[n+1];
        rep(i, 0, n+1) costs[i] = 200'010;
        costs[0] = 0;
        int numones = 0;
        int numzeroes = 0;
        rep(i, 0, n) {
            if (s[i] == '1') numones++;
            else numzeroes++;
            costs[numzeroes] = min(costs[numzeroes], numones);
        }
        int totcosts[n+1];
        rep(i, 0, n+1) totcosts[i] = 200'010;
        totcosts[0] = 0;
        numones = 0;
        numzeroes = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') numones++;
            else numzeroes++;
            totcosts[numzeroes] = min(totcosts[numzeroes], numones);
        }
        rep(i, 0, n) {
            if (i == 0) costs[i] = 0;
            else costs[i] = costs[i-1];
            if (s[i] == '1') costs[i]++;
            else costs[i]--;
        }
        int pref[n];
        pref[0] = min(0, costs[0]);
        rep(i, 1, n) {
            pref[i] = min(pref[i-1], costs[i]);
        }
        int out = pref[n-1];
        int currcost = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') currcost++;
            else currcost--;
            cout << i << ' ' << currcost << endl;
            if (i == 0) out = min(out, currcost);
            else out = min(out, currcost+pref[i-1]);
        }
        cout << out << ' ' << total0 << endl;
        cout << out+total0 << '\n';*/
    }
}