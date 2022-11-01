#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        int curr = 0;
        int sum = 0;
        REP(i, N) sum += a[i];
        while(true){
            if(a[curr] > 0){
                putchar('P');
                a[curr]--;
                sum--;
            }
            if(sum == 0) break;
            if((curr - 1 >= 0 && a[curr - 1] > 0) || curr + 1 >= N){
                putchar('L');
                curr--;
            }else{
                putchar('R');
                curr++;
            }
        }
        putchar('\n');
    }
    return 0;
}