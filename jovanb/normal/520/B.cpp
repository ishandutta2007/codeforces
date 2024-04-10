#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n, m, br=0;
    cin >> n >> m;
    while(m > n){
        br++;
        if(m%2 == 0) m/=2;
        else m++;

    }
    cout << br+(n-m) << endl;
    return 0;
}