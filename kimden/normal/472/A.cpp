// 472 A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin >> n;
    if(n%2){
        x = n-9;
        y = 9;
    }else{
        x = n-4;
        y = 4;
    }
    cout << x << " " << y;
    return 0;
}