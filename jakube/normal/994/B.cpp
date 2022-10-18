#include <bits/stdc++.h>
using namespace std;

struct Knight
{
    long long p, c, idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<Knight> knights(n);
    for (int i = 0; i < n; i++)
        cin >> knights[i].p;
    for (int i = 0; i < n; i++)
        cin >> knights[i].c;
    for (int i = 0; i < n; i++)
        knights[i].idx = i;
    
    sort(knights.begin(), knights.end(), [](auto p, auto q) {
        return p.p < q.p;
    });

    if (k) {
        long long sum = 0;
        multiset<int> largest;
        for (auto & p : knights) {
            int old = p.c;
            p.c += sum;

            if ((int)largest.size() < k || *largest.begin() < old) {
                if ((int)largest.size() == k) {
                    sum -= *largest.begin();
                    largest.erase(largest.begin());
                }
                sum += old;
                largest.insert(old);
            }
        }
    }

    sort(knights.begin(), knights.end(), [](auto p, auto q) {
        return p.idx < q.idx;
    });

    for (auto k : knights) {
        cout << k.c << ' ';
    }
    cout << endl;
}