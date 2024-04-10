#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q --;
        long long a,b,s;
        cin >> a>>b;
        s = b+1;
        long long n = -a;
        while(s){
            s/=10;
            n+=a;
        }
        cout << n << endl;
    }
}