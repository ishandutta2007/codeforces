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
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<int> a(m + 1);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    a[m] = 0;
    int checker = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(c[i] <= a[checker]){
            ans++;
            checker++;
        }
    }
    cout << ans << endl;
    return 0;
}