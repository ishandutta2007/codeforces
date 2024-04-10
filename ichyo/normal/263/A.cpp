#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            int t;
            cin >> t;
            if(t == 1){
                printf("%d\n", abs(x - 2) + abs(y - 2));
            }
        }
    }
    return 0;
}