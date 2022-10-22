#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long long n,m,x=1,i;
    cin>>n>>m;
    for(i=0;i<n;i++){
        x*=2;
        if(x>m){cout<<m;return 0;}
    }
    cout<<m%x;
    return 0;
}