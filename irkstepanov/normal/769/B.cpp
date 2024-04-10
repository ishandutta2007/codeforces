#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

struct data
{
    int a;
    int id;
    bool operator<(const data& other) const 
    {
        if (id == 0 || other.id == 0) {
            return id == 0;
        }
        return a > other.a;
    }
};

int main() 
{
    
    int n;
    cin >> n;
    
    vector<data> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a;
        a[i].id = i;
    }
    sort(all(a));
    
    vector<pii> ans;
    int ptr = 1;
    for (int i = 0; i < n; ++i) {
        if (i == ptr) {
            break;
        }
        while (ptr < n && a[i].a) {
            ans.pb({a[i].id, a[ptr].id});
            --a[i].a;
            ++ptr;
        }
    }
    
    if (ptr != n) {
        cout << "-1\n";
    } else {
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
        }
    }
    
}