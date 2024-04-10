#include<bits/stdc++.h>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int Q;  cin >> Q;
    vector<long long> arr;
    vector<long long> pfac;
    while (Q --) {
        int N;  cin >> N;
        arr.clear();
        pfac.clear();
        for (int i = 0; i < N; i ++) {
            long long val;  cin >> val;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());

        long long p = arr[0] * arr[N-1];

        for (long long c = 2; c*c <= p; c ++) {
            if (p %c != 0)
                continue;
            if (c*c == p) {
                pfac.push_back(c);
            }
            else {
                pfac.push_back(c);
                pfac.push_back(p/c);
            }
        }

        sort(pfac.begin(), pfac.end());

        if (arr == pfac) {
            cout << p << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}