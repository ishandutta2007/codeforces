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
    cout.precision(30);
    long long n, m;
    cin >> n >> m;
    long long a[1050];
    long long b[1050];
    long double checker = 1.0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1){
            cout << -1 << endl;
            return 0;
        }
        checker = checker * ((long double)a[i] / (long double)(a[i] - 1));
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(b[i] == 1){
            cout << -1 << endl;
            return 0;
        }
        checker = checker * ((long double)b[i] / (long double)(b[i] - 1));
    }
    const long double inf = 1000000000.0;
    long double ans = (long double)m * checker - m;
    /*if(ans > inf){
        cout << -1 << endl;
        return 0;
    }*/
    cout << ans << endl;
    return 0;
}