#include <iostream>
using namespace std;
int main(){
    long long a,m,n;
    cin >> m >> n >> a;
    cout << ((m+a-1)/a)*((n+a-1)/a);
    return 0;
}