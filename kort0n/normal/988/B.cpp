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

bool length(string a, string b)
{
    return a.length() < b.length();
}

bool sub(string s, string k)
{
    if(s.size() < k.size()){
        return false;
    }
    for(int i = 0; i <= (s.size() - k.size()); i++){
        bool checker = true;
        for(int j = 0; j < k.size(); j++){
            //cout << "A" << endl;
            if(s[i + j] != k[j]){
                checker = false;
                break;
            }
        }
        if(checker == true){
            //cout << s << " " << k << " " << i << endl;
            return true;
        }
    }
    return false;
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end(), length);
    for(int i = 0; i < n - 1; i++){
        if(!(sub(s[i + 1], s[i]))){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES"<< endl;
    for(int i = 0; i < n; i++){
        cout << s[i] << endl;
    }

    return 0;
}