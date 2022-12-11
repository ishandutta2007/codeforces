#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

void print(int len, int s) {
    for (int i = s + 1; i < s + len; ++i) {
        cout << i + 1 << " ";
    }
    cout << s + 1 << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a, b;
    cin >> n >> a >> b;

    for (int cnt = 0; a * cnt <= n; ++cnt) {
        int k = n - a * cnt;
        if (k % b == 0) {
            //cout << "!" << cnt << " " << k / b << endl;
            for (int i = 0; i < cnt; ++i) {
                print(a, i * a);
            }
            for (int i = 0; i < k / b; ++i) {
                print(b, i * b + cnt * a);
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "-1\n";

}