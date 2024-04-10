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