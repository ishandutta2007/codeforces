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

int gcd(int a, int b)
{
    if(a < b){
        swap(a, b);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    if(m < n - 1){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<pair<int, int> > ans;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(gcd(i, j) == 1){
                pair<int, int> in;
                in.first = i;
                in.second = j;
                ans.push_back(in);
            }
        }
        if(ans.size() >= m){
            break;
        }
    }
    if(ans.size() < m){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(int i = 0; i < m; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}