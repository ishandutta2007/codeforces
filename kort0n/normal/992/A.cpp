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
    vector<int> in(n);
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    int ans = 0;
    if(in[0] != 0){
        ans++;
    }
    for(int i = 1; i < n; i++){
        if(in[i] == 0){
            continue;
        }
        if(in[i] != in[i - 1]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}