#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int pos=0;
    
    if(n%4==0) pos=1;
    if(n%7==0) pos=1;
    if(n%47==0) pos=1;
    if(n%74==0) pos=1;
    if(n%474==0) pos=1;
    if(n%447==0) pos=1;
    if(n%477==0) pos=1;
    if(n%747==0) pos=1;
    if(n%774==0) pos=1;
    
    if(pos==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}