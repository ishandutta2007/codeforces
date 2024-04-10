#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;

    list<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (v.empty() or v.back().first != num) {
            v.push_back({num, 1});
        } else {
            v.back().second++;
        }
        if (v.back().second == k)
            v.pop_back();
    }

    if (m == 1) {
        int sum = 0;
        for (auto i : v)
            sum += i.second;
        cout << sum << endl;
    } else {
        auto first = v;
        auto last = v;
        auto middle = v;

        if (v.size()) {
            while (middle.size() > 1 && middle.front().first == middle.back().first &&
                    middle.front().second + middle.back().second >= k) {
                auto x = middle.front();
                x.second += middle.back().second;
                middle.pop_front();
                middle.pop_back();
                first.pop_back();
                last.pop_front();
                x.second -= k;
                if (x.second) {
                    first.push_back(x);
                    middle.push_back(x);
                }
            }
        }
        
        if (m == 2 or middle.size() != 1) {
            int middle_sum = 0;
            for (auto i : middle)
                middle_sum += i.second;
            int first_sum = 0;
            for (auto i : first)
                first_sum += i.second;
            int last_sum = 0;
            for (auto i : last)
                last_sum += i.second;

            cout << first_sum + last_sum + (long long)middle_sum * (m - 2) << endl;
        } else {
            long long middle_sum = 0;
            for (auto i : middle)
                middle_sum += i.second;
            int first_sum = 0;
            for (auto i : first)
                first_sum += i.second;
            int last_sum = 0;
            for (auto i : last)
                last_sum += i.second;
            first_sum -= first.back().second;
            last_sum -= last.front().second;
            
            middle_sum *= m - 2;
            middle_sum += first.back().second + last.front().second;
            first.pop_back();
            last.pop_front();
            middle_sum %= k;
            if (middle_sum) {
                cout << first_sum + last_sum + (middle_sum % k) << endl;
            } else {
                while (first.size() && last.size() && last.front().first == first.back().first &&
                        last.front().second + first.back().second >= k) {
                    auto x = last.front();
                    x.second += first.back().second;
                    first.pop_back();
                    last.pop_front();
                    x.second -= k;
                    if (x.second) {
                        first.push_back(x);
                    }
                }
                int first_sum = 0;
                for (auto i : first)
                    first_sum += i.second;
                int last_sum = 0;
                for (auto i : last)
                    last_sum += i.second;
                cout << first_sum + last_sum << endl;

            }
        }

    }
}