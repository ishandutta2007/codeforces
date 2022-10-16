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
    int x[10];
    int y[10];
    for(int i = 0; i < 8; i++){
        cin >> x[i];
    }
    for(int i = 0; i < 8; i++){
        cin >> y[i];
    }
    x[8] = x[0];
    x[9] = x[1];
    y[8] = y[0];
    y[9] = y[1];
    /*int a[4];
    int b[4];
    for(int i = 0; i < 4; i++){
        a[i] = (y[i * 2 + 3] - y[i * 2 + 1]) / (x[i * 2 + 2] - x[i * 2]);
        b[i] = y[i * 2 + 1] - a[i] * x[i * 2];
    }*/
    int xcenter = (y[0] + y[2] + y[4] + y[6]) / 4;
    int ycenter = (y[1] + y[3] + y[5] + y[7]) / 4;
    y[8] = xcenter;
    y[9] = ycenter;
    int dist = abs(xcenter - y[0]) + abs(ycenter - y[1]);
    for(int i = 0; i < 4; i++){
        if(abs(x[i * 2] - xcenter) + abs(x[i * 2 + 1] - ycenter) <= dist){
            cout << "YES" << endl;
            return 0;
        }
    }
    int xupper = max(x[0], max(x[2], max(x[4], x[6])));
    int xunder = min(x[0], min(x[2], min(x[4], x[6])));
    int yupper = max(x[1], max(x[3], max(x[5], x[7])));
    int yunder = min(x[1], min(x[3], min(x[5], x[7])));
    for(int i = 0; i < 5; i++){
        if(y[i * 2] > xupper){
            continue;
        }
        if(y[i * 2] < xunder){
            continue;
        }
        if(y[i * 2 + 1] > yupper){
            continue;
        }
        if(y[i * 2 + 1] < yunder){
            continue;
        }
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}