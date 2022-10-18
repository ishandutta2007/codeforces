#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> classy;
    vector<long long> powers(19, 1);
    for (int i = 1; i < 19; i++)
        powers[i] = powers[i-1] * 10;

    for (int a = 0; a < 18; a++) {
        for (int d = 1; d < 10; d++) {
            long long n1 = powers[a] * d;
            classy.push_back(n1);
            for (int b = a+1; b < 18; b++) {
                for (int e = 1; e < 10; e++) {
                    long long n2 = n1 + powers[b] * e;
                    classy.push_back(n2);
                    for (int c = b+1; c < 18; c++) {
                        for (int f = 1; f < 10; f++) {
                            long long n3 = n2 + powers[c] * f;
                            classy.push_back(n3);
                        }
                    }
                }
            }
        }
    }
    classy.push_back(powers[18]);
    classy.push_back(powers[18]+1);
    sort(classy.begin(), classy.end());

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long L, R;
        cin >> L >> R;
        cout << (upper_bound(classy.begin(), classy.end(), R) - classy.begin()) - 
            (upper_bound(classy.begin(), classy.end(), L-1) - classy.begin()) << '\n';
    }
}