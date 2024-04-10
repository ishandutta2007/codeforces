#include <iostream>

using namespace std;
long long n, m, a;
int main()
{
    cin>>m>>n>>a;
    long long a1=(m+a-1)/a;
    long long a2=(n+a-1)/a;
    cout<<a1*a2;
    return 0;
}