#include<bits/stdc++.h>
using namespace std;
long long plusdani(long long y){
    if (y % 400==0 || y % 100 != 0 && y % 4==0){
        return 2;
    }
    return 1;
}
long long sledgod(long long  y){
    long long  days = plusdani(y);
    long long  x = y + 1;
    for (long long sum = 0; ; x++){
        sum = (sum + plusdani(x)) % 7;
        if ( sum==0 && (plusdani(x) == days)){
            return x;
        }
    }
    return x;
}
int main(){
    long long y;
    cin >> y;
    cout << sledgod(y) << endl;
    return 0;
}