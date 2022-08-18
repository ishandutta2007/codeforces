#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define M_PI        3.14159265358979323846
#define eps 1e-9
using namespace std;
long n,i,j,q;
int main(){  
 //freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n;
if (n==1){cout<<"a"<<endl<<"a"<<endl<<"b"<<endl<<"b"<<endl;} else
if (n%2==0){
for (int i=1;i*2<=n;i++){if (i%2==0)cout<<"aa"; else cout<<"bb";}
cout<<endl;            
cout<<"c";
for (int i=1;i*2<n;i++){if (i%2==0){cout<<"dd";} else cout<<"ee";}
cout<<"q";
cout<<endl;
cout<<"c";
for (int i=1;i*2<n;i++){if (i%2==0){cout<<"ff";} else cout<<"gg";}
cout<<"q";
cout<<endl;
for (int i=1;i*2<=n;i++){if (i%2==0)cout<<"aa"; else cout<<"bb";}
cout<<endl;            
}
else if (n==3)
{
     n-=3;
cout<<"ppr";for (int i=1;i*2<=n;i++){if (i%2==0)cout<<"aa"; else cout<<"bb";}
cout<<endl;            
cout<<"wwr";if (n)cout<<"c";     

for (int i=1;i*2<n;i++){if (i%2==0){cout<<"dd";} else cout<<"ee";}
if (n)cout<<"q";
cout<<endl;
cout<<"mll";if (n)cout<<"c";   
for (int i=1;i*2<n;i++){if (i%2==0){cout<<"ff";} else cout<<"gg";}
if (n)cout<<"q";
cout<<endl;
cout<<"mtt";
for (int i=1;i*2<=n;i++){if (i%2==0)cout<<"aa"; else cout<<"bb";}
cout<<endl;          
 }
 else
 {
     for (int i=1;i*2<=n;i++)if (i%2==0)cout<<"aa";else cout<<"bb";
     cout<<"c"<<endl;
     for (int i=1;i*2<=n;i++)if (i%2==0)cout<<"ee";else cout<<"dd";
     cout<<"c"<<endl;
     cout<<"t";
     for (int i=1;i*2<=n;i++)if (i%2==0)cout<<"pp"; else cout<<"qq";
     cout<<endl;
     cout<<"t";
     for (int i=1;i*2<=n;i++)if (i%2==0)cout<<"ll"; else cout<<"vv";
     }
cin.get();cin.get();
return 0;}