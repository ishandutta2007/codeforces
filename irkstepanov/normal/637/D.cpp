#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

struct step
{
    int type;
    int len;
};

int main()
{

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    int curr = 0;
    int bar = 0;

    vector<step> ans;
    while (curr != m) {
        if (bar == n) {
            ans.pb({1, m - curr});
            curr = m;
            break;
        }
        if (a[bar] - curr - 1 < s) {
            break;
        }
        ans.pb({1, a[bar] - curr - 1});
        curr = a[bar] - 1;
        int finish;
        for (finish = bar; finish < n; ++finish) { //after whcih
            if (finish == n - 1 || a[finish + 1] - a[finish] >= s + 2) {
                break;
            }
        }
        if (a[finish] + 1 - curr > d) {
            break;
        }
        ans.pb({2, a[finish] + 1 - curr});
        curr = a[finish] + 1;
        bar = finish + 1;
    }

    if (curr != m) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (step& s : ans) {
        if (s.type == 1) {
            cout << "RUN ";
        } else {
            cout << "JUMP ";
        }
        cout << s.len << "\n";
    }

}