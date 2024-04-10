#include <iostream>

using namespace std;

long long n, m, h[101], k, a, b;

int main()
{
    cin>>n>>a>>b;

    for (int i=1;i<=n;i++)
    {
        cin>>k;
        cout<<((k*a)%b)/a<<' ';
    }
}