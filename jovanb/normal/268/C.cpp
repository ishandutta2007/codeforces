#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n,m,i;
    cin>>n>>m;
    cout<<min(n,m)+1<<"\n";
    for(i=min(n,m); i>=0; i--){
        cout<<i<<" "<<min(n,m)-i<<"\n";
    }
    return 0;
}