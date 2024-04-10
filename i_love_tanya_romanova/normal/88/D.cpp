/*
I'm gonna make you, shake you, take you 
I'm gonna be the one who breaks you 
Put the screws to ya my way 
Yeah, come on come on, come and make my day, make my day 

Got some hell to pay, I steal your thunder 
The joy of violent movements pulls you under 
Bite the bullet well hard 
Yeah, but I die harder, so go too far, too far 
Friction, fusion, retribution 
I can't hear ya, talk ta me (Friction, fusion) 
I can't hear ya so talk ta me (Retribution) 
I can't here ya, are you talkin' ta me? (Friction, fusion) 
I can't year ya, are you talkin' ta me? (Retribution) 
I can't hear ya, time ta meet my lord 
I can't hear ya, talk ta 2 by 4 

I'm gonna make you, shake you, take you 
I'm gonna be the one who breaks you 
Put the screws to ya my way 
Hey, come on come on, come and make my day, make my day 
Friction, fusion, retribution 
I can't hear ya, talk ta me (Friction, fusion) 
I can't hear ya, come talk ta me (Retribution) 
I can't here ya, are you talkin' ta me? (Friction, fusion) 
I can't year ya, are you talkin' ta me? (Retribution) 
I can't hear ya, time ta meet my lord 
I can't hear ya, talk ta 2 by 4 

Hey talk ta 2 by 4 
It don't take no more 
C'mon yeah 
C'mon 

C'mon, c'mon, talk to 2 by 4 
Talk to 2 by 4 

Friction, fusion, retribution 
I'm gonna make you talk to me (Friction, fusion) 
I'm gonna take you through, so talk to me (Retribution) 
I can't year ya, are you talkin' ta me? (Friction, fusion) 
I can't year ya, are you talkin' ta me? (Retribution) 
I can't hear ya, time ta meet my lord 
I can't hear ya, talk to, talk to 2 by 4 
She don't take no more
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
long d[10000],i,s,sz,n,ps;
string types[1000],st1,st2;
int main(){
cin>>n;
types[0]="errtype";
types[1]="void";
d[0]=0;
d[1]=1;
sz=1;
for (int i=1;i<=n;i++)
{cin>>st1;
 if (st1.length()==7)
 {cin>>st1;
  s=0;
 for (int i=0;i<st1.length();++i)
 {if (st1[i]=='*')s++;
  if (st1[i]=='&')s--;}
  while (st1[0]=='&')st1.erase(st1.begin(),st1.begin()+1);
  while (st1[st1.length()-1]=='*')st1.erase(st1.end()-1,st1.end());
 // cout<<st1<<endl;
 ps=-1;
  for(int i=0;i<=sz;i++)
  if (types[i]==st1){if (d[i]==0)s=0; else s+=d[i];ps=i;}
  if (s<0)s=0;if (ps==-1)s=0;
  cin>>st2;ps=-1;
  for (int i=0;i<=sz;i++)
  if (types[i]==st2){d[i]=s;ps=i;}
  if (ps==-1){sz++;d[sz]=s;types[sz]=st2;}
 }
 else {cin>>st1;  s=0;
 for (int i=0;i<st1.length();++i)
 {if (st1[i]=='*')s++;
  if (st1[i]=='&')s--;}
  while (st1[0]=='&')st1.erase(st1.begin(),st1.begin()+1);
  while (st1[st1.length()-1]=='*')st1.erase(st1.end()-1,st1.end());
  ps=-1;
//  cout<<st1<<endl;
 // cout<<sz<<endl;
 // for (int i=0;i<=sz;i++)cout<<types[i]<<endl;
  for(int i=0;i<=sz;i++)
  if (types[i]==st1){if (d[i]==0)s=0; else s+=d[i];ps=i;}
  if (s<0)s=0;if (ps==-1)s=0;
//  cout<<s<<endl;
  if (s==0)cout<<"errtype"<<endl;
  else {cout<<"void";for (int i=1;i<s;i++)cout<<"*";cout<<endl;}}
}
cin.get();cin.get();
return 0;
}