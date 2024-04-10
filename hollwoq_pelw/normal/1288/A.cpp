#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long long n,d;
        cin >> n >> d;
        if (d*4 > (n+1)*(n+1)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}