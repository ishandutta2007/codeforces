#include <iostream>
using namespace std;
long long d;
int n,m,a;
long long int del(int a, int b)
{
    if (a%b==0)
        return a/b;
    else
        return a/b+1;
}
int main()
{
    cin >> n >> m >> a;
    d=del(n,a)*del(m,a);
    cout << d;
    return 0;
}