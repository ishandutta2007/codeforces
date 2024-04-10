#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    multiset<long long> ms;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ms.insert(val);
    }

    if (ms.size() % 2 == 0) {
        ms.insert(0);
    }

    long long total = 0;
    while(ms.size() > 1) {
        long long sum = 0;
        sum += *ms.begin();
        ms.erase(ms.begin());
        sum += *ms.begin();
        ms.erase(ms.begin());
        sum += *ms.begin();
        ms.erase(ms.begin());
        ms.insert(sum);
        total += sum;
    }

    cout << total << endl;
}