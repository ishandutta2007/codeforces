#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long a,b,i;
    cin>>a>>b;
    cout<<a+b-1<<"\n";
    cout<<"1 1\n";
    for(i=2;i<=b;i++)cout<<"1 "<<i<<"\n";
    for(i=2;i<=a;i++)cout<<i<<" 1\n";
    return 0;
}