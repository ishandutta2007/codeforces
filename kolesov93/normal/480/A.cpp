#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 5555;
bool done[N];


int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > a;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }

    sort(a.begin(), a.end());
    int last = -1;

    int cur = 0;
    while (cur < a.size()) {
        int nxt = cur + 1;
        while (nxt < a.size() && a[nxt].first == a[cur].first) ++nxt;

        for (int i = cur; i < nxt; ++i)
            if (a[i].second >= last) {
                last = a[i].second;
                done[i] = true;
            }

        for (int i = cur; i < nxt; ++i)
            if (!done[i]) {
                done[i] = true;
                last = a[i].first;
            }

        cur = nxt;
    }

    cout << last << endl;

    return 0;
}