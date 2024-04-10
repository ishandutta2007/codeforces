#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long x,z=0;
    cin>>x;
    while(x>0){
        if(x&1)z++;
        x=x>>1;
    }
    cout<<z;
    return 0;
}