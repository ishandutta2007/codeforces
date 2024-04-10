#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int query(int i) {
    cout << "? " << i << "\n";
    cout.flush();
    int v;
    cin >> v;
    return v;
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed << setprecision(14);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "! 1\n";
        cout.flush();
        return 0;
    } else if (n == 2) {
        cout << "? 1\n";
        cout.flush();
        int v1;
        cin >> v1;
        cout << "? 2\n";
        cout.flush();
        int v2;
        cin >> v2;
        if (v1 < v2) {
            cout << "! 1\n";
        } else {
            cout << "! 2\n";
        }
        cout.flush();
        return 0;
    }

    int l = 1;
    int r = n;
    
    int lval = query(l);
    int rval = query(r);
    
    int mid = (l + r) / 2;
    int midval = query(mid);

    bool mid_mode = false;
    bool l_mode = false;
    bool r_mode = false;
    if (midval < lval && midval < rval) {
        mid_mode = true;
    } else if (lval < midval) {
        l_mode = true;
        r = mid;
        rval = midval;
    } else {
        r_mode = true;
        l = mid;
        lval = midval;
    }

    while (r - l > 3) {
        if (mid_mode) {
            if (mid - l >= r - mid) {
                int lmid = (l + mid) / 2;
                int lmidval = query(lmid);
                if (lmidval < midval) {
                    r = mid;
                    rval = midval;
                    mid = lmid;
                    midval = lmidval;
                } else {
                    l = lmid;
                    lval = lmidval;
                }
            } else {
                
                int rmid = (r + mid) / 2;
                int rmidval = query(rmid);
                if (rmidval < midval) {
                    l = mid;
                    lval = midval;
                    mid = rmid;
                    midval = rmidval;
                } else {
                    r = rmid;
                    rval = rmidval;
                }
            }
        } else if (l_mode) {
            mid = (l + r) / 2;
            midval = query(mid);
            if (midval > lval) {
                r = mid;
                rval = midval;
            } else {
                l_mode = false;
                mid_mode = true;
            }
        } else {
            mid = (l + r) / 2;
            midval = query(mid);
            if (midval > rval) {
                l = mid;
                lval = midval;
            } else {
                r_mode = false;
                mid_mode = true;
            }
        }
    }

    int min_ind = l;
    int min_val = lval;
    if (rval < lval) {
        min_ind = r;
        min_val = rval;
    }
    for (int i = l + 1; i < r; i++) {
        int new_val = query(i);
        if (new_val < min_val) {
            min_ind = i;
            min_val = new_val;
        }
    }

    cout << "! " << min_ind << "\n";
    cout.flush();

    
}