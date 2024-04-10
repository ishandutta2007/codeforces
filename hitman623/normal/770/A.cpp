#include <iostream>

using namespace std;

int main()
{
    long n,k,i;
    char a='a';
    cin>>n>>k;
    for(i=0;i<n;++i)
    cout<<(char)(a+i%k);
    return 0;
}