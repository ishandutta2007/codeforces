#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    
    int best = 100;
    for (string end : {"00", "25", "50", "75"}) {
        auto x = n;
        int l = (int)x.size();

        if (x == end) {
            cout << 0 << '\n';
            return 0;
        }

        int idx1 = -1;
        int idx2 = -1;

        for (int i = l-1; i >= 0; i--) {
            if (idx2 == -1 && x[i] == end[1]) {
                idx2 = i;
            } else if (idx1 == -1 && x[i] == end[0]) {
                idx1 = i;
            }
        }

        // if (idx1 < 0 || idx2 < 0)
        //     continue;

        // int cnt = 0;
        // if (idx1 > idx2) {
        //     swap(idx1, idx2);
        //     cnt++;
        // }

        // auto my_swap = [](string& x, int i, int j) {
        //     if (i == j)
        //         return 0;

        //     if (i == 0 && x[1] == 0) {

        //     }
        //     return 0;
        // };

        // cnt += my_swap(x, idx2, l-1);
        // cnt += my_swap(x, idx1, l-1);

        int cur = 100;
        for (int i = l-1; i >= 0; i--) {
            if (x[i] == end[1]) {
                cur = 0;
                if (i == 0 && x[1] == '0') {
                    for (int k = 1; k < l; k++) {
                        if (x[k] != '0') {
                            for (int j = k-1; j >= 1; j--) {
                                swap(x[j], x[j+1]);
                                cur++;
                            }
                            break;
                        }
                    }
                    if (x[1] == '0') {
                        cur = 100;
                        break;
                    }

                }
                for (int j = i; j < l-1; j++) {
                    swap(x[j], x[j+1]);
                    cur++;
                }
                // cout << x << '\n';
                // cout << cur << '\n';
                break;
            }
        }

        if (x[l-1] != end[1])
            continue;

        // cout << 222222 << '\n';
        
        int cur2 = 100;
        for (int i = l-2; i >= 0; i--) {
            if (x[i] == end[0]) {
                cur2 = 0;
                if (i == 0 && x[1] == '0') {
                    for (int k = 1; k < l; k++) {
                        if (x[k] != '0') {
                            for (int j = k-1; j >= 1; j--) {
                                swap(x[j], x[j+1]);
                                cur2++;
                            }
                            break;
                        }
                    }
                    if (x[1] == '0') {
                        cur2 = 100;
                        break;
                    }

                }
                for (int j = i; j < l-2; j++) {
                    swap(x[j], x[j+1]);
                    cur2++;
                }
                // cout << "!" << '\n';
                
                // cout << x << '\n';
                // cout << cur2 << '\n';
                break;
            }
        }

        if (x[l-2] == end[0] && x[l-1] == end[1])
            best = min(best, cur + cur2);
    }
    if (best < 100)
        cout << best << '\n';
    else
        cout << -1 << '\n';
}