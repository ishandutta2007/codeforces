#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if ((i + j) & 1) {
                ++x;
            } else {
                ++y;
            }
        }
    }

    if (x >= n / 2 && y >= n - n / 2) {
        int even = 2, odd = 1;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if ((i + j) & 1) {
                    if (even <= n) {
                        cout << even << " ";
                        even += 2;
                    } else {
                        cout << "0 ";
                    }
                } else {
                    if (odd <= n) {
                        cout << odd << " ";
                        odd += 2;
                    } else {
                        cout << "0 ";
                    }
                }
            }
            cout << "\n";
        }
    } else if (x >= n - n / 2 && y >= n / 2) {
        int even = 2, odd = 1;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if ((i + j) & 1) {
                    if (odd <= n) {
                        cout << odd << " ";
                        odd += 2;
                    } else {
                        cout << "0 ";
                    }
                } else {
                    if (even <= 2) {
                        cout << even << " ";
                        even += 2;
                    } else {
                        cout << "0 ";
                    }
                }
            }
            cout << "\n";
        }
    } else {
        cout << "-1\n";
    }

}