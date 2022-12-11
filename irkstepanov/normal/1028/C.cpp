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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

struct rect {
    int x1, y1;
    int x2, y2;
};

int smallest(vector<int>& a, int val) {
    int pos = lower_bound(all(a), val) - a.begin();
    if (pos == 0) {
        return a[1];
    } else {
        return a[0];
    }
}

int biggest(vector<int>& a, int val) {
    int pos = lower_bound(all(a), val) - a.begin();
    if (pos == sz(a) - 1) {
        return a[sz(a) - 2];
    } else {
        return a.back();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<int> xmin, xmax, ymin, ymax;
    int n;
    cin >> n;

    vector<rect> vct;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xmin.pb(x1), xmax.pb(x2);
        ymin.pb(y1), ymax.pb(y2);
        vct.pb({x1, y1, x2, y2});
    }

    sort(all(xmin));
    sort(all(xmax));
    sort(all(ymin));
    sort(all(ymax));

    for (int i = 0; i < n; ++i) {
        int x1 = biggest(xmin, vct[i].x1);
        int y1 = biggest(ymin, vct[i].y1);
        int x2 = smallest(xmax, vct[i].x2);
        int y2 = smallest(ymax, vct[i].y2);
        if (x1 <= x2 && y1 <= y2) {
            cout << x1 << " " << y1 << endl;
            return 0;
        }
    }

}