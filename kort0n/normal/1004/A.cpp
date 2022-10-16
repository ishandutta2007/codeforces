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
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    set<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 1; j++){
            int sgn = j * 2 - 1;
            int pos = x[i] + d * sgn;
            int mindis = INF;
            for(int k = 0; k < n; k++){
                mindis = min(mindis, abs(x[k] - pos));
            }
            if(mindis == d){
                ans.insert(pos);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}