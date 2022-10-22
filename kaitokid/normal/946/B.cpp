#include <bits/stdc++.h>
 using namespace std;
long long a,b;
int main(){
ios::sync_with_stdio(0);
cin>>a>>b;
while(true)
{
if(a==0||b==0){cout<<a<<" "<<b;return 0;}
if(a>=2*b){a=a%(2*b);continue;}
if(b>=2*a){b=b%(2*a);continue;}
cout<<a<<" "<<b;
return 0;


}
 return 0;}