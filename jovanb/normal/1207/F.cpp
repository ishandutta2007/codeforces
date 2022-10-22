#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
 
int niz[500005];
int ima[705][705];
 
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;
 
    int q;
    cin >> q;
    int k = 700;
    while(q--){
        int a, x, y;
        cin >> a >> x >> y;
        if(a == 1){
            niz[x] += y;
            for(int i=1; i<=k; i++){
                int ind = x%i;
                ima[i][ind] += y;
            }
        }
        else{
            if(x > k){
                int sum = 0;
                for(int r=y; r<=500000; r+=x){
                    sum += niz[r];
                }
                cout << sum << "\n";
            }
            else{
                cout << ima[x][y] << "\n";
            }
        }
    }
    return 0;
}