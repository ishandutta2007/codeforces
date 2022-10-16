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
    int n = s.size();
    string boin ="aiueo";
    string last = "aiueon";
    bool checker = false;
    for(int i = 0; i <= 5; i++){
        if(s[n - 1] == last[i]){
            checker = true;
        }
    }
    if(!checker){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = n - 1; i >= 0; i--){
        checker = false;
        for(int j = 0; j <= 5; j++){
            if(s[i] == last[j]){
                checker = true;
            }
        }
        if(checker){
            continue;
        }
        for(int j = 0; j <= 4; j++){
            if(s[i + 1] == boin[j]){
                checker = true;
            }
        }
        if(!checker){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}