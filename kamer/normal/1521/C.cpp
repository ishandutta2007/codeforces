#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int ask(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void respond(vector<int>& perm) {
    cout << "!";
    for (auto p : perm) {
        cout << " " << p;
    }
    cout << "\n";
    cout.flush();
}

void solve(void) {
    int n;
    cin >> n;
    vector<int> perm(n);

    for (int q = 0; q < n / 2; q++) {
        int i = 2 * q + 1;
        int j = 2 * q + 2;
        int min_ij = ask(2, i, j, 1);
        int max_ij = ask(1, i, j, n - 1);

        if (max_ij == n && min_ij == 1) {
            // j is n, i is 1
            perm[j - 1] = n;
            perm[i - 1] = 1;
        } else if (max_ij == n && min_ij == 2) {
            // j is n
            // i is 2 && j > 2 OR j = 1 or 2
            perm[j - 1] = n;
            perm[i - 1] = 2;
        } else if (max_ij == n && min_ij > 2) {
            // j is n
            perm[j - 1] = n;
            perm[i - 1] = min_ij;
        } else if (max_ij == n - 1 && min_ij == 1) {
            // i is 1, j = n - 1 && i < n - 1 OR i is n-1 or n and j < i
            perm[i - 1] = 1;
            perm[j - 1] = n - 1;
        } else if (max_ij == n - 1 && min_ij == 2) {
            if (ask(1, j, i, n - 1) == n) {
                perm[i - 1] = n;
                if (ask(2, j, i, 1) == 1) {
                    perm[j - 1] = 1;
                } else {
                    perm[j - 1] = 2;
                }
            } else if (ask(2, j, i, 1) == 1) {
                perm[j - 1] = 1;
                if (ask(1, j, i, n - 1) == n) {
                    perm[i - 1] = n;
                } else {
                    perm[i - 1] = n - 1;
                }
            } else {
                if (ask(1, i, j, 2) == 2) {
                    perm[i - 1] = n - 1;
                    perm[j - 1] = 2;
                } else {
                    perm[i - 1] = 2;
                    perm[j - 1] = n - 1;
                }
            }
        } else if (max_ij == n - 1 && min_ij > 2) {
            // i is n - 1 or n and j < i OR j = n - 1 and i < j
            if (ask(1, j, i, n - 1) == n) {
                perm[i - 1] = n;
                perm[j - 1] = min_ij;
            } else {
                int tent_max_ij = ask(2, i, j, n - 2);
                if (tent_max_ij == n - 1) {
                    perm[i - 1] = n - 1;
                    perm[j - 1] = min_ij;
                } else {
                    perm[j - 1] = n - 1;
                    perm[i - 1] = min_ij;
                }
            }
        } else if (max_ij < n - 1 && min_ij == 1) {
            // i is 1
            perm[i - 1] = 1;
            perm[j - 1] = max_ij;
        } else if (max_ij < n - 1 && min_ij == 2) {
            // i is 2 && j > 2 OR j = 1 OR 2 && i > j
            if (ask(2, j, i, 1) == 1) {
                perm[j - 1] = 1;
                perm[i - 1] = max_ij;
            } else {
                int tent_min_ij = ask(1, i, j, 2);
                if (tent_min_ij == 2) {
                    perm[j - 1] = 2;
                    perm[i - 1] = max_ij;
                } else {
                    perm[i - 1] = 2;
                    perm[j - 1] = max_ij;
                }
            }
        } else if (max_ij < n - 1 && min_ij > 2) {
            // These are actual min & max
            int tent_min_ij = ask(1, i, j, min_ij);
            if (min_ij == tent_min_ij) {
                perm[j - 1] = min_ij;
                perm[i - 1] = max_ij;
            } else {
                perm[i - 1] = min_ij;
                perm[j - 1] = max_ij;
            }
        }
    }

    if (n % 2 == 1) {
        vector<int> count(n, 0);
        for (int i = 0; i < n - 1; i++) {
            count[perm[i] - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (count[i] == 0) {
                perm[n - 1] = i + 1;
            }
        }
    }

    respond(perm);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}