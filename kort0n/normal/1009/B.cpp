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
    //cout.precision(10)
    string s;
    cin >> s;
    int one = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            one++;
        }
    }
    bool checker = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            continue;
        }
        if(s[i] == '2' && checker){
            for(int j = 0; j < one; j++){
                cout << "1";
            }
            checker = false;
        }
        cout << s[i];
    }
    if(checker){
        for(int j = 0; j < one; j++){
            cout << "1";
        }
    }
    cout << endl;
    return 0;
}