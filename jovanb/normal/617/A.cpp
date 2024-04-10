#include <iostream>

using namespace std;

int main() {
    
    long long n,x=0;
    cin>>n;
    x+=n/5;
    if(n%5!=0)x+=1;
    cout<<x;
    return 0;
}