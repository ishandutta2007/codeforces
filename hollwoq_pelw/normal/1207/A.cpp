#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t){
        t--;
        int b,p,f,h,c,res = 0;
        cin >> b >> p >> f >> h >> c;
        int n = b/2;
        if (h > c){
            if (n > p){
                n -= p;
                res += p*h;
            }else {
                res += n*h;
                n = 0;
            }
            if (n > f){
                n -= f;
                res += f*c;
            }else {
                res += n*c;
                n = 0;
            }
            cout << res << endl;
        }else {
            if (n > f){
                n -= f;
                res += f*c;
            }else {
                res += n*c;
                n = 0;
            }
            if (n > p){
                n -= p;
                res += p*h;
            }else {
                res += n*h;
                n = 0;
            }
            cout << res << endl;
        }
    }
}