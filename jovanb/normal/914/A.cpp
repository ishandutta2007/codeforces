#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long long n,x,y,maxx=-1000005,i;
    cin>>n;
    for(i=0; i<n; i++){
        cin >> x;
        if(x<0){
            maxx=max(maxx,x);
        }
        else{
            y = sqrt(x);
            if(y*y != x)maxx=max(maxx,x);
        }
    }
    cout<<maxx;
    return 0;
}