#include <bits/stdc++.h> 
using namespace std;
int x,y,n,m,f;
int main() {
cin>>f>>n>>m;
int i=0;
x=n,y=m;
while(x%10!=7&&x%100!=7&&y%10!=7&&y%100!=7)
{
y-=f;
if(y<0){y+=60;x--;}
if(x<0)x+=24;
i++;


}

cout<<i;
 return 0; }