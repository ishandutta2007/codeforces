#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

vector<int> out = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 189, 289, 389, 489, 589, 689, 789, 1789, 2789, 3789, 4789, 5789, 6789, 16789, 26789, 36789, 46789, 56789, 156789, 256789, 356789, 456789, 1456789, 2456789, 3456789, 13456789, 23456789, 123456789};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << out[n-1] << '\n';
    }
}