#include <bits/stdc++.h>3c
using namespace std;

int main(){
    int a,b,c,d;
    char s;
    cin >> a >> s >> b >> c >> s >>d;
    int k=60*a+b;
    int k1=60*c+d;
    int mx=(k+k1)/2;
    int h=mx/60;
    int sec=mx%60;
    if (h<10){
        cout << 0;
    }
    cout << h << ":";
    if (sec<10){
        cout << 0;
    }
    cout << sec;
}