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
    string s;
    cin >> s;
    for(int i = 1; i < s.size() - 1; i++){
        set<char> in;
        for(int k = -1; k <= 1; k++){
            if(s[i + k] == '.'){
                break;
            }
            in.insert(s[i + k]);
        }
        if(in.size() == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}