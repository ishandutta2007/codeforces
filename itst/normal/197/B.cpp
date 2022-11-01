#include<bits/stdc++.h>
using namespace std;

int n , m , a[107] , b[107];

inline int gcd(int a , int b){
    int r = a % b;
    while(r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    cin >> n >> m;
    for(int i = n ; i >= 0 ; --i)
        cin >> a[i];
    for(int i = m ; i >= 0 ; --i)
        cin >> b[i];
    if(n > m){
        if((a[n] < 0) ^ (b[m] < 0))
            putchar('-');
        puts("Infinity");
    }
    else
        if(n < m)
            puts("0/1");
        else{
            if((a[n] < 0) ^ (b[m] < 0))
                putchar('-');
            if(a[n] < 0)    a[n] = -a[n];
            if(b[m] < 0)    b[m] = -b[m];
            int t = gcd(a[n] , b[m]);
            cout << a[n] / t << '/' << b[m] / t << endl;
        }
    return 0;
}