#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>x;
n%=6;
for(int i=n;i>0;i--)
{
if(i%2==1)
{
if(x==0)x=1;
else
if(x==1)x=0;

}
else
{

if(x==2)x=1;
else 
if(x==1)x=2;


}
}
cout<<x;
return 0;}