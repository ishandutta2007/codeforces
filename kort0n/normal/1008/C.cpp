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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cost[105000];
    for(int i = 0; i < n; i++){
        cost[i] = n - distance(v.begin(), upper_bound(v.begin(), v.end(), v[i]));
        //cout << cost[i] << endl;
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(cost[i] > ans){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}