// Hydro submission #627278167a9e10ef478c27b5@1651669014865
#include <iostream>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    int pay = 0;
    for(int i = 1; i <= w; ++i){
        pay += i * k;
    }
    cout << (pay > n ? (pay - n) : 0) << endl;
    return 0;
}