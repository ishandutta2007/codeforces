#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> notes(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> notes[i+1];
    }
    vector<int> last(n, -1), room(n);
    last[0] = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        int l = room[notes[i]];
        if (last[l] == notes[i]) {
            room[i] = l;
            last[l] = i;
        } else {
            r++;
            room[i] = r;
            last[r] = i;
        }
        // cout << room[i] << endl;
    }
    cout << r + 1 << endl;
    
}