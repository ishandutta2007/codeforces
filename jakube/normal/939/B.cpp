#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    int K;
    cin >> K;
    vector<long long> a(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    
    int best = 0;
    for (int i = 1; i < K; i++) {
        if (n / a[i] * a[i] > n / a[best] * a[best])
            best = i;
    }
    cout << best + 1 << " " << n / a[best] << endl;
}