#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int cnt = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] == '0') cnt++;
        int mmin = cnt;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '0')
                cnt--;
            else
                cnt++;
            mmin = min(mmin, cnt);
        }
        cnt = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] == '1') cnt++;
        mmin = min(mmin, cnt);
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '1')
                cnt--;
            else
                cnt++;
            mmin = min(mmin, cnt);
        }
        cout << mmin << endl;
    }
}