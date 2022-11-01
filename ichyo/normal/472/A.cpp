#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    const int MAX = 1000010;
    bool bp[MAX] = {};
    REP(i, MAX) bp[i] = true;
    bp[0] = bp[1] = false;
    for(int i = 2; i * i < MAX; i++) {
        if(bp[i]) {
            for(int j = i * i; j < MAX; j += i) {
                bp[j] = false;
            }
        }
    }
    for(int i = 2; i < n; i++) {
        if(!bp[i] && !bp[n - i]) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
    return 0;
}