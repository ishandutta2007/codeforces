#include <iostream>
using namespace std;
#define ll unsigned long long

ll a,b;
int main(){
    cin >> a >> b;
    ll ret = 1LL;
    for( ll i = a+1 ; i <= b ; i++ ){
        ret *= i;
        ret %= 10;
        if( ret == 0 ) break;
    }
    cout << ret << endl;
    return 0;
}