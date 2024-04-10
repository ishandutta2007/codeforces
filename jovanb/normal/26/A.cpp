#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int res=0;
    for(int i=6; i<=n; i++){
        int cnt=0;
        int x = i;
        for(int j=2; j<=x; j++){
            if(x%j == 0){
                cnt++;
                while(x%j == 0){
                    x /= j;
                }
            }
        }
        if(cnt == 2) res++;
    }
    cout << res;
    return 0;
}