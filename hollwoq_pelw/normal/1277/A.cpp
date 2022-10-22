#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long n;
        cin >> n;
        long x=n;
        int k = 1,res = 0;
        while(x >= 10){
            x/=10;
            res += 9;
            k = k*10+1;
        }
        res += x;
        if (x*k > n) res --;
        cout << res << endl;
        
    }
    return 0;
}