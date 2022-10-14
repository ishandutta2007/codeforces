#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint p[4], ind[4], done = 0;
vector <llint> v;

llint play (llint y) {
    if (done) return 0;
    cout << y << endl;
    int pos; cin >> pos;
    if (pos == 0) {
        done = 1;
        return 0;
    } else {
        v[ind[pos]] += y;
        return ind[pos];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 3; i++) {
        cin >> p[i];
        v.push_back(p[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= 3; i++) {
        ind[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
    }
    cout << "First" << endl;
    if (play(v[1] - v[0]) == 1) play(v[1] - v[0]);
    if (play(2*v[2] - v[0] - v[1]) == 1) {
        play(v[2] - v[0]);
    } else {
        play(v[2] - v[1]);
    }
    return 0;
}