#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int a;
    cin >> a;

    string s;
    cin >> s;
    int n = s.size();
    
    long long cnt = 0;
    vector<int> se(36001, 0);
    for (int i = 0; i < n; i++) {
        int last = 0;
        for (int j = i; j < n; j++) {
            last += s[j]-'0';
            if (last > 36000) break;
            se[last]++;
        }
    }

    if (a == 0) {
        cout << ((long long)n*(long long)(n+1))/2*se[0]*2-(long long)se[0]*se[0] << endl;
        return 0;
    }

    for (int i = 1; i < min(36001, a+1); i++) {
        if (a % i == 0 && a/i < 36001) {
            cnt += (long long)(se[i])*se[a/i];
        }
    }

    cout << cnt << endl;

    return 0;
}