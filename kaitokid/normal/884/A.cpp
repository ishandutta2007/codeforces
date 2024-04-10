#include <bits/stdc++.h>
using namespace std ; 

int main() 
{

int n,t;
cin>>n>>t;
int x;
for(int i=0;i<n;i++)
{

cin>>x;
t-=86400-x;
if(t<=0){cout<<i+1;return 0;}

}
return 0;
}