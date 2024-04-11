#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    long long n, k;
    cin >> n >> k;
    if(n + n - 1 < k){
        cout << 0 << endl;
        return 0;
    }
    if(k <= 2){
        cout << 0 << endl;
        return 0;
    }
    k = min(k, 2 * (n + 1) - k) - 1;
    cout << k / 2 << endl;
    return 0;
}