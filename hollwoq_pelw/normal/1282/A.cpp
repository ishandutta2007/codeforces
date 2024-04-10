#include <bits/stdc++.h>
using namespace std;
int main(){
    long t,a,b,c,r,max,min;
    cin >> t;
    while(t){
        t--;
        cin >> a >> b >> c >> r;
        if (a > b){
            int k = a;
            a=b;
            b=k;
        }
        if (a > c-r) max = a ;
        else max = c-r;
        if (b < c+r) min = b;
        else min = c+r;
        int m = max-min;
        if (m > 0) m = 0; 
        cout << b-a+m << endl;
    }
    return 0;
}