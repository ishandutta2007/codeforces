#include <bits/stdc++.h>

using namespace std;

int a, b, m, n;

int main()
{
cin>>a>>b;
m=max(a, b);
n=min(a, b);
cout<<n<<' '<<(m-n)/2<<'\n';

    return 0;
}