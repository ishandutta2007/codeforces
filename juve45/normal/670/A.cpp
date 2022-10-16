#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
cin>>n;

cout<<2*(n/7)+max(0, n%7-5)<<' ';
cout<<2*(n/7)+min(2, n%7);

    return 0;
}