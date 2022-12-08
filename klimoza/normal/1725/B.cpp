#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <cstring>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ull unsigned long long

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
//const int MAXM = 21;
ll INF = 1e9 + 10;
ll mod = 786433;
ld EPS = 1e-12;

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("/Users/maksimmartynov/Downloads/second_hands_input.txt", "r", stdin);
//    freopen("/Users/maksimmartynov/Downloads/second_hands_validation_output.txt", "w", stdout);
}

int n;
ll d, a[MAXN];

bool check(int num) {
    ll need = 0;
    for (int i = 0; i < num; i++) {
        need += (d + a[i]) / a[i];
    }
    return need <= n;
}

int main() {
    fastIO();
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';


    return 0;
}