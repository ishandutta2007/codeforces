#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int a;
        cin >> a;
        if(360 % (180 - a) == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}