#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> a;
        int cnt = 0;
        int ccnt = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] == '1')
                cnt++;
            else
                ccnt++;
        cnt = min(cnt, ccnt);
        if (cnt & 1)
            cout << "DA" << endl;
        else
            cout << "NET" << endl;
    }
}