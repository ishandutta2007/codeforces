#include <bits/stdc++.h>

using namespace std;
 long long a[3];
int main()
{
  string s;
   long long nb,nc,ns,pb,ps,pc,r;
  cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>r;
  for( long long i=0;i<s.size();i++)
  {if(s[i]=='B'){a[0]++;}
   if(s[i]=='S'){a[1]++;}
   if(s[i]=='C'){a[2]++;}
  }
  if(a[0]==0){a[0]=1;pb=0;}
    if(a[1]==0){a[1]=1;ps=0;}
      if(a[2]==0){a[2]=1;pc=0;}
 long long ans =min(nb/a[0],min(ns/a[1],nc/a[2]));
nb-=ans*a[0];
ns-=ans*a[1];
nc-=ans*a[2];
//cout<<nb<<" "<<ns<<" "<<nc<<endl;
while(r>0&&(nb!=0||ns!=0||nc!=0))
{ long long x=a[0]-nb;
//cout<<x<<endl;
if(x>0){r-=pb*x;nb=0;}else{nb-=a[0];}
x=a[1]-ns;
//cout<<x<<endl;
if(x>0){r-=ps*x;ns=0;}else{ns-=a[1];}
x=a[2]-nc;
//cout<<x<<endl;
if(x>0){r-=pc*x;nc=0;}else{nc-=a[2];}
if(r>=0){ans++;}
//cout<<r<<" "<<nb<<" "<<ns<<" "<<nc<<endl;
}
//cout<<r<<endl;
if(r<=0){cout<<ans;return 0;}
ans+= r/(pb*a[0]+ps*a[1]+pc*a[2]);
cout<<ans;
       return 0;
}