#include<bits/stdc++.h>
using namespace std;

bool sum(int n){
    int res = 0;
    while( n ){
        res += n % 10;
        n /= 10;
    }
    return ( res % 4 == 0 );
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while( !sum(n) )
        n++;

    cout << n << '\n';

    return 0;
}