#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int inf = 1e9 + 10;
typedef pair<int, int> ii;
#define X first
#define Y second


int n, a[N];

vector<ii> use[N];
ii ans[N];
int main() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i)
            if (i > j / i) {
                int sum = i, sub = j / i;
                int b2 = sum + sub, a2 = sum - sub;
                if (b2 % 2 == 0) {
                    use[j].push_back(ii(a2 / 2, b2 / 2));
                }
            }
    }
    for(int j = 1; j < N; j++) {
        sort(use[j].begin(), use[j].end(), [](ii a, ii b) {
            return a.Y < b.Y;
        });
    }
    cin >> n;
    for(int i = 1; i <= n / 2; i++) cin >> a[i]; 
 
    ans[0] = ii(-1, 0);
    for(int i = 1; i <= n / 2; i++) {
        ans[i] = ii(-1, inf);
        for(auto j : use[a[i]]) {
            if (j.X > ans[i - 1].Y && j.Y < ans[i].Y) 
                ans[i] = j;
        }
        if (ans[i].X == -1) {
            cout << "No";
            return 0;
        }
    }
    //for(int i = 1; i <= n / 2; i++) cout << ans[i].X << " " << ans[i].Y << '\n';
    cout << "Yes\n";
    for(int i = 1; i <= n / 2; i++) {
        cout << 1LL * ans[i].X * ans[i].X - 1LL * ans[i - 1].Y * ans[i - 1].Y << " " << a[i] << " ";
    }
}