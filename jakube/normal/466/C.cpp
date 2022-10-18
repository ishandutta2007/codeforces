#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> psum(n);
    int last = 0;
    for (int i = 0; i < n; ++i) {
        last += v[i];
        psum[i] = last;
    }

    long long cnt = 0;

    vector<int> a(n, 0), b(n, 0);
    int lasta = 0, lastb = 0;
    int A = sum / 3;
    int B = A * 2;

    for (int i = 0; i < n; ++i) {
        if (psum[i] == A) lasta++;
        if (psum[i] == B) lastb++;
        a[i] = lasta;
        b[i] = lastb;
    }

    for (int i = 0; i < n; ++i) {
        if (psum[i] == A) {
            cnt += max(0, b[n-2] - b[i]);
        }
    }

    cout << cnt << endl;

    

    return 0;
}