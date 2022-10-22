#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int q, n, m, ans, mx1, mx2;
vector<int> arr[404040];
vector<int> brr[404040];
vector<int> a, b;
char c;

int main() {
    cin >> q;
    while (q--) {
        cin >> n >> m;

        mx1 = INT_MAX;

        for (int i=0; i<n; i++) {
            getchar();
            for (int j=0; j<m; j++) {
                cin >> c;
                if (c=='*') {
                    arr[i].push_back(j);
                    brr[j].push_back(i);
                }
            }
        }

        int tmp;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                tmp = (int)(n+m-arr[i].size()-brr[j].size()-1);

                if (tmp<=mx1) {
                    for (int k=0; k<arr[i].size(); k++) if (arr[i][k] == j) tmp++;
                }

                mx1 = min(mx1, tmp);
            }
        }

        for (int i=0; i<n; i++) arr[i].clear();
        for (int j=0; j<m; j++) brr[j].clear();

        cout << mx1 << '\n';
    }
}