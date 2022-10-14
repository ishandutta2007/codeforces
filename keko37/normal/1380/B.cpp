#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n;
string s;
int cnt[100];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        cnt['R'] = cnt['P'] = cnt['S'] = 0;
        for (auto c : s) cnt[c]++;
        char w;
        if (cnt['R'] >= cnt['P'] && cnt['R'] >= cnt['S']) w = 'P';
        if (cnt['P'] >= cnt['S'] && cnt['P'] >= cnt['R']) w = 'S';
        if (cnt['S'] >= cnt['P'] && cnt['S'] >= cnt['R']) w = 'R';
        for (int i = 0; i < n; i++) cout << w; cout << '\n';
    }
    return 0;
}