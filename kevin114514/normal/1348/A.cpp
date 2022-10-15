#include<bits/stdc++.h>
using namespace std;
int main()
{
int T;
cin>>T;
while(T--)
{
int X;
cin>>X;
int Y=1;
X/=2;
while(X--)
{
Y*=2;
}
Y*=2;
Y-=2;
cout<<Y<<endl;
}
return 0;
}