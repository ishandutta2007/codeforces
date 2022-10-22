#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, a, b;
    cin >> n >> a >> b;
    if(a > b) swap(a,b);
    int br = 0;
    int x = n;
    while(x>2){
        br++;
        if(b == a+1 && b%2 == 0){cout << br; return 0;}
        a = (a+1)/2;
        b = (b+1)/2;
        x /= 2;
    }
    cout << "Final!";
    return 0;
}