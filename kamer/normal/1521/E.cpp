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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int m, k;
        cin >> m >> k;
        vector<tuple<int, int>> a(k);
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            a[i] = { val, i + 1 };
        }

        sort(a.rbegin(), a.rend());

        int n = 1;
        auto [largest_value, largest_index] = a[0];
        while (true) {
            if (n % 2 == 0) {
                if (n * n / 2 >= largest_value && 3 * n * n / 4 >= m) {
                    break;
                }
            } else {
                if (n * n - (n - 1) * (n - 1) / 4 >= m && n * (n + 1) / 2 >= largest_value) {
                    break;
                }
            }

            n++;
        }

        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                if (largest_value > 0) {
                    largest_value--;
                    result[i][j] = largest_index;
                }
            }
        }

        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                if (largest_value > 0) {
                    largest_value--;
                    result[i][j] = largest_index;
                }
            }
        }

        int curr_a_index = 1;
        int curr_val = 0;
        int curr_index = 0;
        if (k >= 2) {
           curr_val = get<0>(a[1]);
           curr_index = get<1>(a[1]);
        }

        for (int i = 1; i < n; i += 2) {
            if (k <= curr_a_index || curr_val == 0) {
                break;
            }

            for (int j = 0; j < n; j += 2) {

                if (k <= curr_a_index || curr_val == 0) {
                    break;
                }

                if (result[i][j] == 0) {
                    result[i][j] = curr_index;
                    curr_val--;
                    if (curr_val == 0) {
                        curr_a_index++;
                        if (k > curr_a_index) {
                            curr_val = get<0>(a[curr_a_index]);
                            curr_index = get<1>(a[curr_a_index]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i += 2) {
            if (k <= curr_a_index || curr_val == 0) {
                break;
            }

            for (int j = 0; j < n; j += 2) {

                if (k <= curr_a_index || curr_val == 0) {
                    break;
                }

                if (result[i][j] == 0) {
                    result[i][j] = curr_index;
                    curr_val--;
                    if (curr_val == 0) {
                        curr_a_index++;
                        if (k > curr_a_index) {
                            curr_val = get<0>(a[curr_a_index]);
                            curr_index = get<1>(a[curr_a_index]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i += 2) {
            if (k <= curr_a_index || curr_val == 0) {
                break;
            }

            for (int j = 1; j < n; j += 2) {

                if (k <= curr_a_index || curr_val == 0) {
                    break;
                }

                if (result[i][j] == 0) {
                    result[i][j] = curr_index;
                    curr_val--;
                    if (curr_val == 0) {
                        curr_a_index++;
                        if (k > curr_a_index) {
                            curr_val = get<0>(a[curr_a_index]);
                            curr_index = get<1>(a[curr_a_index]);
                        }
                    }
                }
            }
        }

        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }



    }
}