#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    vector<pii> b = a;
    sort(all(b));
    vector<pii> events;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(b), a[i]) - b.begin();
        events.pb(mp(min(i, pos), 1));
        events.pb(mp(max(i, pos), -1));
    }
    sort(all(events));
    int balance = 0;
    int ans = 0;
    for (int i = 0; i < sz(events); ++i) {
        balance += events[i].second;
        if (balance == 0) {
            ++ans;
        }
    }
    printf("%d\n", ans);
}