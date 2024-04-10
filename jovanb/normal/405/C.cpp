#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int sum=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        sum ^= mat[i][i];
    }
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        if(a == 3) cout << sum;
        else {cin >> a; sum ^= 1;}
    }
    return 0;
}