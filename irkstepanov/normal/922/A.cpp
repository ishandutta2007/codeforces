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
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int x, y;
    cin >> x >> y;
    swap(x, y);
    if (x < 1) {
        cout << "No\n";
        return 0;
    }

    if (x == 1) {
        if (y == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }
    
    y -= (x - 1);
    if (y < 0 || y % 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

}