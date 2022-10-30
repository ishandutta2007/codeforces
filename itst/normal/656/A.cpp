#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    long long ans = 1;
    cin >> x;
    if(x < 13){
        for(int i = 1 ; i <= x ; i++)
            ans <<= 1;
    }
    else{
        ans *= 8092;
        for(int i = 1 ; i <= x - 13 ; i++)
            ans <<= 1;
    }
    cout << ans;
    return 0;
}