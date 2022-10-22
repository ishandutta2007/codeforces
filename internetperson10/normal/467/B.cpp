#include <bits/stdc++.h>

using namespace std;

vector<int> players;

int main() {
    int m, n, k, s=0, c, u;
    cin >> n >> m >> k;
    while(m--) {
        cin >> c;
        players.push_back(c);
    }
    cin >> c;
    for(int a=0; a<players.size(); a++) {
        u=0;
        players[a]^=c;
        for(int x=0; x<n; x++) {
            if(players[a] & (1 << x))
                u++;
        }
        if(u<=k) s++;
    }
    cout << s;
}