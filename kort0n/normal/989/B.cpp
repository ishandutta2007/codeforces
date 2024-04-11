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

char rev(char in)
{
    if(in == '1'){
        return '0';
    }
    return '1';
}

int main() {
    //cout.precision(10);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool checker = false;
    for(int i = 0; i < s.size() - p; i++){
        if(s[i] == '.'){
            checker = true;
            break;
        }
        if(s[i] != s[i + p]){
            checker = true;
            break;
        }
    }
    if(checker == false){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < p; i++){
        if(s[i] != '.'){
            continue;
        }
        if(i + p > s.size()){
            s[i] = '0';
            continue;
        }
        if(s[i + p] == '.'){
            s[i] = '0';
            continue;
        }
        s[i] = rev(s[i + p]);
    }
    for(int i = p; i < s.size(); i++){
        if(s[i] != '.'){
            continue;
        }
        s[i] = rev(s[i - p]);
    }
    cout << s << endl;


    return 0;
}