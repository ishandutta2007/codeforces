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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int ans = -96 * k;
    int checker = 0;
    for(int i = 0; i < n; i++){
        if((int)s[i] - checker >= 2){
            ans += (int)s[i];
            checker = (int)s[i];
            k--;
            if(k == 0){
                break;
            }
        }
    }
    if(k != 0){
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}