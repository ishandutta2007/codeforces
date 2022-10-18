#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    vector<int> neg, pos;
    for (int x : v) {
        if (x < 0)
            neg.push_back(x);
        else
            pos.push_back(x);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    
    auto pos_pos = [](vector<int> v) {
        for (int& x : v)
            x = abs(x);
        sort(v.begin(), v.end());
        
        long long result = 0;
        for (int x : v) {
            // y in pos
            // |x - y| < x + y

            // case 1: x < y
            // y - x <= x < y <= x + y
            // x < y <= 2 * x
            result += upper_bound(v.begin(), v.end(), 2*x) -
                      upper_bound(v.begin(), v.end(), x);

            // case 2: x > y
            // x - y <= x < y <= x + y
            // - y <= 0
            // result += upper_bound(v.begin(), v.end(), x) - v.begin();
            // result--;
        }
        return result;
    };
    auto pos_neg = [](vector<int> pos, vector<int> neg, bool doub) {
        for (int& x : pos)
            x = abs(x);
        sort(pos.begin(), pos.end());
        for (int& x : neg)
            x = -abs(x);
        sort(neg.begin(), neg.end());
        
        long long result = 0;
        for (int x : pos) {
            // y in neg
            // |x + y| < |x - y|

            // case 1: |x| < |y|
            // |x + y| <= x < |y| <= |x - y|
            // -y - x <= x < -y <= x - y
            // -y <= 2x
            // y >= -2x
            // y < -x
            // -2x <= y < -x
            result += lower_bound(neg.begin(), neg.end(), -x) -
                      lower_bound(neg.begin(), neg.end(), -2*x);


            // case 2: |x| == |y|
            // 0 <= x <= 2x
            auto it = lower_bound(neg.begin(), neg.end(), -x);
            if (doub && it != neg.end() && *it == -x)
                result++;
        }
        return result;
    };

    long long result = 0;
    result += pos_pos(pos);
    result += pos_pos(neg);
    result += pos_neg(pos, neg, true);
    result += pos_neg(neg, pos, false);
    cout << result << '\n';
}