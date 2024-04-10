#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1e9;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<char> used(n, false);
    
    int ans = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int k = -1;
        int minn = inf;
        for (int j = 0; j < n; ++j) {
            if (a[j] > prev && !used[j] && a[j] < minn) {
                minn = a[j];
                k = j;
            }
        }
        if (k != -1) {
            if (prev) {
                ++ans;
            }
            used[k] = true;
            prev = a[k];
        } else {
            int k = -1;
            int minn = inf;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && a[j] < minn) {
                    minn = a[j];
                    k = j;
                }
            }
            used[k] = true;
            prev = minn;
        }
    }
    
    cout << ans << "\n";

}