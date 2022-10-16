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
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;
    int left = 0, right = 0;
    int i = 0;
    while(left < (k / 2)){
        if(s[i] == '('){
            cout << "(";
            left++;
            i++;
            continue;
        }
        if(right < left){
            cout << ")";
            right++;
        }
        i++;
    }
    for(int i = right; i < left; i++){
        cout << ")";
    }
    cout << endl;
    return 0;
}