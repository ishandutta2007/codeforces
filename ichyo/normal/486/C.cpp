#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
int cost(int a, int b) {
    assert(a >= 0 && a < 26);
    assert(b >= 0 && b < 26);
    if(a > b) swap(a, b);
    return min(b - a, (a + 26) - b);
}

int main(){
    int n, p;
    while(cin >> n >> p){
        string s;
        cin >> s;

        int l = INT_MAX;
        int r = INT_MIN;
        for(int i = 0; i < n - 1 - i; i++) {
            if(s[i] != s[n - 1 - i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }

        if(l == INT_MAX) {
            cout << 0 << endl;
            continue;
        } 

        int ans = 0;
        // [l, n - 1 - l]
        for(int i = l; i < n - 1 - i; i++) {
            ans += cost(s[i]-'a', s[n-1-i]-'a');
        }

        p--;
        // [0, n/2]
        if(p >= n/2) p = (n - 1) - p;
        ans += min(abs(l-p) + abs(r-l), abs(r-p) + abs(l-r));

        cout << ans << endl;
    }
    return 0;
}