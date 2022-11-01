#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int A, B;
    while(cin >> A >> B){
        int ans = A;
        int down = A;
        while(true){
            int next = down / B;
            if(next == 0) break;
            down -= next * B;
            ans += next;
            down += next;
        }
        cout << ans << endl;
    }
    return 0;
}