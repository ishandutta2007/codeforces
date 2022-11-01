#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    while(n%3==0)
        n=n/3;
    cout<<(n/3)+1<<endl;
}