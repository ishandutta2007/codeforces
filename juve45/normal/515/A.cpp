#include <bits/stdc++.h>

using namespace std;

int a, b, n;

int main()
{
cin>>a>>b>>n;

a=abs(a);
b=abs(b);
if(n>=a+b && (n-(a+b))%2==0)
    cout<<"YES\n";
else cout<<"NO\n";

    return 0;
}