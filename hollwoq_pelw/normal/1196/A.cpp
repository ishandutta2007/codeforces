#include <iostream>
using namespace std;
int main(){
    long long q,a,b,c;
    cin >> q;
    while(q){
        q--;
        cin >> a >> b >> c;
        cout << (a+b+c)/2 << endl;
    }
    return 0;
}