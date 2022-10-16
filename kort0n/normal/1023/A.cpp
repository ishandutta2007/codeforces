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
    string s, t;
    cin >> s >> t;
    int k = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            k = i;
        }
    }
    if(k == -1){
        if(s == t){
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    while(s.back() != '*'){
        if(t.empty()){
            cout << "NO" << endl;
            return 0;
        }
        if(t.back() != s.back()){
            cout << "NO" << endl;
            return 0;
        }
        t.pop_back();
        s.pop_back();
        n--;
        m--;
    }
    for(int i = 0; i < n - 1; i++){
        if(i >= m){
            cout << "NO" << endl;
            return 0;
        }
        if(s[i] != t[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}