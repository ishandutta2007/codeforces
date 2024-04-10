#include <iostream>
using namespace std;
int main(){
    long long a,b,n,x,y;
    cin>>a>>b>>n;
    if(a%n==0)x=a/n;
    else x=a/n+1;
    if(b%n==0)y=b/n;
    else y=b/n+1;
    cout<<x*y;
    return 0;
}