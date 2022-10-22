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

int find_k(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, vector<tuple<int, int>>& c) {
    int l = 1;
    int r = a.size() + 1;

    sort(a.begin(), a.end());

    while (r - l > 1) {
        int mid = (l + r) / 2;

        vector<int> new_b;
        vector<int> new_c;

        for (int i = 0; i < b.size(); i++) {
            auto [b_x_el, b_y_el] = b[i];
            auto [c_x_el, c_y_el] = c[i];

            if (b_x_el > get<0>(a[mid - 1])) {
                new_b.emplace_back(b_y_el);
            }

            if (c_x_el > get<0>(a[mid - 1])) {
                new_c.emplace_back(c_y_el);
            }
        }

        if (new_b.size() < mid || new_c.size() < mid) {
            r = mid;
            continue;
        }

        sort(new_b.begin(), new_b.end());
        sort(new_c.begin(), new_c.end());

        if (new_c[mid - 1] < new_b[new_b.size() - mid] || new_c[new_c.size() - mid] > new_b[mid - 1]) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l;
}

int find_k_simple(vector<tuple<int, int>>& a, vector<tuple<int, int>>& b, vector<tuple<int, int>>& c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int b_first_index = 0, b_last_index = b.size() - 1;
    int k = 1;
    int n = a.size();
    
    while (true) {
        while (b_first_index < n && get<0>(b[b_first_index]) <= get<0>(a[k - 1])) b_first_index++;
        while (b_last_index >= 0 && get<0>(b[b_last_index]) >= get<0>(c[n - k])) b_last_index--;

        if (b_last_index - b_first_index < k - 1) {
            return k - 1;
        }

        k++;
    }
}

void rotate(vector<tuple<int, int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        a[i] = { -y, x };
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n;
    cin >> n;

    vector<tuple<int, int>> a(n / 3);
    vector<tuple<int, int>> b(n / 3);
    vector<tuple<int, int>> c(n / 3);

    int a_index = 0, b_index = 0, c_index = 0;
    for (int i = 0; i < n; i++) {
        int x, y, col;
        cin >> x >> y >> col;
        if (col == 1) a[a_index++] = { x, y };
        if (col == 2) b[b_index++] = { x, y };
        if (col == 3) c[c_index++] = { x, y };
    }

    int k = 1;
    for (int i = 0; i < 4; i++) {
        k = max(k, find_k(a, b, c));
        swap(a, b);
        k = max(k, find_k(a, b, c));
        swap(a, c);
        k = max(k, find_k(a, b, c));

        if (i < 2) {
            k = max(k, find_k_simple(a, b, c));
            swap(a, b);
            k = max(k, find_k_simple(a, b, c));
            swap(a, c);
            k = max(k, find_k_simple(a, b, c));
            swap(a, b);
            k = max(k, find_k_simple(a, b, c));
            swap(a, c);
            k = max(k, find_k_simple(a, b, c));
            swap(a, b);
            k = max(k, find_k_simple(a, b, c));
        }

        if (i < 3) {
            rotate(a);
            rotate(b);
            rotate(c);
        }
    }

    cout << 3 * k << "\n";


}