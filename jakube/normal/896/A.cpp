#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v(1e5+1);
    v[0] = 75;
    long long M = 1e18;
    for (int i = 1; i < (int)v.size(); i++) {
        v[i] = min(2*v[i-1] + 68, M + 1);
    }

    string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
    const string a = "What are you doing while sending \"";
    const string b = "\"? Are you busy? Will you send \"";
    const string c = "\"?";
    long long as = a.size();
    long long bs = b.size();
    long long cs = c.size();

    int q;
    cin >> q;
    while (q --> 0) {
        long long n, k;
        cin >> n >> k;
        k--;
        if (k >= v[n]) {
            cout << '.';
            continue;
        }
        if (n == 0) {
            cout << s[k];
            continue;
        }
        bool finished = false;
        while (n) {
            if (k < as) {
                cout << a[k];
                finished = true;
                break;
            }
            k -= as;
            if (k < v[n-1]) {
                n--;
                continue;
            }
            k -= v[n-1];
            if (k < bs) {
                cout << b[k];
                finished = true;
                break;
            }
            k -= bs;
            if (k < v[n-1]) {
                n--;
                continue;
            }
            k -= v[n-1];
            if (k <  cs) {
                cout << c[k];
                finished = true;
                break;
            }
        }
        if (!finished) 
            cout << s[k];
    }
    cout << endl;
}