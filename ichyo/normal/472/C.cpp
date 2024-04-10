#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> a(n);
        vector<string> b(n);
        vector<int> p(n);
        REP(i, n) cin >> a[i] >> b[i];
        REP(i, n) cin >> p[i];
        REP(i, n) p[i]--;
        string last = "";
        bool ok = true;
        for(int i : p) {
            if(last < min(a[i], b[i])) {
                last = min(a[i], b[i]);
            } else if(last < max(a[i], b[i])) {
                last = max(a[i], b[i]);
            } else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}