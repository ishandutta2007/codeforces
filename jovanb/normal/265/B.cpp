#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,br,h,oldh,i;
    cin>>n;
    br=2*n-1;
    cin>>h;
    br+=h;
    oldh=h;
    for(i=1;i<n;i++){
        cin>>h;
        br+=abs(oldh-h);
        oldh=h;
    }
    cout<<br;
    return 0;
}