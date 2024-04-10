#include <bits/stdc++.h>
using namespace std;
int main(){
    long long k, n = 1, d = 1;
    cin >> k;
    while(k > 9*n*d){
        k -= 9*n*d;
        n*=10;
        d++;
    }
    stringstream ss;
    string x;
    ss << n+(k-1)/d;
    ss >> x;
    cout << x[(k-1)%d];
}