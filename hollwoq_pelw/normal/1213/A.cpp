#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0,b=0,k;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;
        if (k % 2 == 0) a++;
        else b++;
    }
    if (a>b){
        cout << b;
    }
    else{
        cout << a;
    }
    return 0;
}