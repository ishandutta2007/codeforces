#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool checker = true;
        for(int j = 0; j < (n / 2); j++){
            if((abs((int)s[j] - (int)s[n - 1 - j]) != 2) && (abs((int)s[j] - (int)s[n - 1 - j]) != 0)){
                checker = false;
            }
        }
        if(checker){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}