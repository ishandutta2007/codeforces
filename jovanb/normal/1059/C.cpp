#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int res[5000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int oldn=n;
    int tren=0;
    while(n > 1){
        if(n == 3){
            res[tren+2] = 3;
            n = n/3;
        }
        else{
            if(n%2 == 0){
                res[tren+n/2] = 2;
                tren += n/2;
                n = n/2;
            }
            else{
                res[tren+n/2+1] = 2;
                tren += n/2+1;
                n = n/2;
            }
        }
    }
    int tr=1;
    for(int i=1; i<=oldn; i++){
        cout << tr << " ";
        if(res[i] != 0) tr *= res[i];
    }
    return 0;
}