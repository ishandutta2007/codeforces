#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string s;
    cin >> s;
    char last = s[1];
    int n = s.size();
    s = "a" + s;
    int a[1020];
    a[1] = 0;
    for(int i = 2; i < n; i++){
        if(last != s[i + 1]){
            a[i] = 1;
        } else {
            a[i] = 0;
        }
        last = s[i + 1];
    }
    if(s[n] == 'a'){
        a[n] = 1;
    } else {
        a[n] = 0;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i];
        if(i < n){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}