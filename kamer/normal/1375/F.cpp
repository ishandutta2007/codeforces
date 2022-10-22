#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    vector<ll> b(3);
    for (int i = 0; i < 3; i++) cin >> b[i];
    auto a = b;
    sort(a.begin(), a.end());
    cout << "First\n";
    cout.flush();
    cout << a[2] << "\n";
    cout.flush();
    int index;
    cin >> index;
    if (index == 0) return 0;
    b[index - 1] += a[2];
    a = b;
    sort(a.begin(), a.end());
    cout << 2 * a[2] - a[0] - a[1] << "\n";
    cout.flush();
    cin >> index;
    if (index == 0) return 0;
    b[index - 1] = b[index - 1] + 2 * a[2] - a[0] - a[1];
    a = b;
    sort(a.begin(), a.end());
    cout << a[2] - a[1] << "\n";
    cout.flush();
    cin >> index;
    if (index != 0) return 1;
    return 0;
}