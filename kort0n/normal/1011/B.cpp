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
    int b[101];
    int c[101];
    for(int i = 0; i < 101; i++){
        b[i] = 0;
        c[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int in;
        cin >> in;
        b[in]++;
    }
    for(int i = 0; i < 101; i++){
        c[b[i]]++;
    }
    for(int i = 1; i < 102; i++){
        int number = 0;
        for(int k = 1; k < 101; k++){
            number += (k / i) * c[k];
        }
        if(number < n){
            cout << i - 1 << endl;
            return 0;
        }
    }
    return 0;
}