#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if (a == b) cout << a << "0 "<< b << "1";
    else if(a+1 == b) cout << a << ' ' << b;
    else if(a+1 == b*10) cout << a << ' ' << b*10;
    else cout << -1;
    
    return 0;
}