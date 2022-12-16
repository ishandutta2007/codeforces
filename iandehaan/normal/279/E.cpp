#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

string inp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool run = false;
    int lastrun = -1000;
    cin >> inp;
    int n = inp.size();
    ll out = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == '1') {
            if (run) {
                // still on a run lol
                
                lastrun = i;
            } else {
                //cout << i << ' ' << inp[i] << endl;
                out++;

                if (lastrun == i-2 && i < n && inp[i+1] == '0') lastrun = i;
                
                if (i > 0 && inp[i-1] == '1') {
                    if (lastrun == i-3) {
                        //cout << i << endl;
                        out--;
                    }
                    run = true;
                    lastrun = i;
                }
            }
        } else {
            run = false;
            //if (lastrun != -1000 && i > 0 && inp[i-1] == '1') lastrun = i-1;
        }
    }
    cout << out << endl;
}