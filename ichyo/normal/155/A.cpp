#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    int first_a;
    cin >> first_a;
    int min_a = first_a;
    int max_a = first_a;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        if(min_a > x){
            ans ++;
            min_a = x;
        }
        if(max_a < x){
            ans ++;
            max_a = x;
        }
    }
    cout << ans << endl;
    return 0;
}