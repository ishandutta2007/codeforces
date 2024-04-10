#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q--;
        long long m,n;
        cin >> m >> n;
        long long a[10], s=0;
        a[0] = 0;
        for (int i = 1; i < 10; i++) {
            a[i] = a[i-1] + (i*n)%10; 
            s += (i*n)%10;
        }
        long long t = m/n;
        long long res = ((t/10)*s)+a[t%10];
        cout << res << endl;
    }
}