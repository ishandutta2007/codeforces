#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n; long long s = 1; long long t = 1;
    for(int i = 2; i <= n; i++){
        s = s * i;
        s = s % 1000000007;
    }
    n = n - 1;
    for(int i = 0; i < n; i++){
        t = t * 2; t = t % 1000000007;
    }
    s = s - t;
    if(s < 0){
        s = s + 1000000007;
    }
    cout << s;
}

// anyone wanna hack noob's code? assume that it's wrong, pls hack for me