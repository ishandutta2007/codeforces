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
    int height = INF;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(min(a, b) > height){
            cout << "NO" << endl;
            return 0;
        }
        if(max(a, b) <= height){
            height = max(a, b);
            continue;
        }
        height = min(a, b);
    }
    cout << "YES" << endl;
    return 0;
}