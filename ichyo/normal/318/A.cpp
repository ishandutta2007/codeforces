#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;

int main(){
    LL n, k;
    cin >> n >> k;
    k--;
    if(n % 2 == 0){
        if(k < n / 2){
            cout << k * 2 + 1 << endl;
        }else{
            cout << (k - n / 2) * 2 + 2 << endl;
        }
    }else{
        if(k < n / 2 + 1){
            cout << k * 2 + 1 << endl;
        }else{
            cout << (k - n / 2 - 1) * 2 + 2 << endl;
        }
    }
    return 0;
}