#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int n;
string inp;

bool works(int dist) {

    int coverUntil = -1;
    int lastUncovered = -1;
    for (int i = 0; i < n; i++) {
        if (inp[i] == '.') continue;

        if (inp[i] == '*') {
            if (i > coverUntil) {
                if (lastUncovered == -1) lastUncovered = i;
            }
        } else if (inp[i] == 'P') {
            if (lastUncovered == -1) {
                coverUntil = i + dist;
            } else {
                int needToMove = i-lastUncovered;
                
                if (needToMove > dist) return false;
                coverUntil = max(i+(dist-needToMove*2), i + (dist-needToMove)/2);
                lastUncovered = -1;
            }
        }
    }

    if (lastUncovered != -1) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> inp;

    //works(26);

    ll lo = 0;
    ll hi = 1000000;
    while (abs(hi-lo) > 5) {
        ll mid = (lo+hi)/2;
        bool works1 = works(mid);
        reverse(begin(inp), end(inp));
        bool works2 = works(mid);
        reverse(begin(inp), end(inp));
        if (works1 || works2) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    for (int i = max((ll)0, lo-1); i < hi+2; i++) {
        if (works(i)) {
            cout << i << endl;
            break;
        }
        reverse(begin(inp), end(inp));
        if (works(i)) {
            cout << i << endl;
            break;
        }
    }
}