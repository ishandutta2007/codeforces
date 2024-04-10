#include <bits/stdc++.h>
using namespace std;

int main()
{string x;
cin>>x;
int i=0,j=x.size()-1;
while(x[j]=='0')j--;
while(j>i)
{
if(x[i]!=x[j]){cout<<"NO";return 0;}

i++;
j--;
}
cout<<"YES";
return 0;}