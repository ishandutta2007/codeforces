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
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        sum1 += in;
    }
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        sum2 += in;
    }
    if(sum1 >= sum2){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}