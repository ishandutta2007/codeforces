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

    int t;
    cin >> t;
    while (t--) {
        set<pair<pair<int, int>, pair<int, int>>> visited;

        string inp;
        cin >> inp;
        pair<int, int> pos = mp(0, 0);
        int out = 0;
        for (char c : inp) {
            pair<int, int> newpos = pos;
            if (c == 'N') newpos.first++;
            else if (c == 'S') newpos.first--;
            else if (c == 'E') newpos.second++;
            else newpos.second--;
            if (visited.find(mp(pos, newpos)) == visited.end()) out += 5;
            else out++;
            visited.insert(mp(pos, newpos));
            visited.insert(mp(newpos, pos));
            pos = newpos;
        }
        
        cout << out << endl;
    }
    
}