#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m, k;
    while(cin >> n >> m >> k){
        vector<int> a(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int t;
            cin >> t;
            if(t == 1){
                if(m > 0){
                    m--;
                }else{
                    ans++;
                }
            }else{
                if(k > 0){
                    k--;
                }else if(m > 0){
                    m--;
                }else{
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}