#include <iostream>

using namespace std;

int main() {
    
    long long n,x=0;
    cin>>n;
    x+=n/2;
    if(n%2!=0)x-=n;
    cout<<x;
    return 0;
}