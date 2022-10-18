#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, L;
    cin >> n >> L;
    
    vector<int> A(n);
    for (int idx = 0; idx < n; idx++)
        cin >> A[idx];
    vector<int> B(n);
    for (int idx = 0; idx < n; idx++)
        cin >> B[idx];
    for (int j = n-1; j >= 0; j--) {
        A[j] -= A[0];
        B[j] -= B[0];
    }
    // A[0] += (L - A.back());
    // B[0] += (L - B.back());

    for (int i = 0; i < n; i++) {
        if (A == B) {
            cout << "YES" << endl;
            return 0;
        }

        A.push_back(L);
        A.erase(A.begin());
        for (int j = n-1; j >= 0; j--) {
            A[j] -= A[0];
        }
    }

    cout << "NO" << endl;
    return 0;
}