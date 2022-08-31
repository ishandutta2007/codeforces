#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#pragma comment(linker, "/STACK:20000000")
#define M_PI		3.14159265358979323846
using namespace std;
string st,st1;long i,j,l,answ,t,ans[10000],d,ar[100000];
int main(){
   // freopen("C:/input.txt","r",stdin);freopen("C:/output.txt","w",stdout);
   while (getline(cin,st)){st1=st1+st;
    }//cout<<st1<<endl;
    l=st1.length();
    
    for (i=0;i<l-2;++i){//cout<<d<<ar[d]<<endl;
    if 
    (st1[i]=='<'&&st1[i+1]=='t'&&st1[i+2]=='a')
    {d++;ar[d]=0;}
    if (st1[i]=='/'&&st1[i+1]=='t'&&st1[i+2]=='a'){answ++;ans[answ]=ar[d];d--;}
    if (st1[i]=='<'&&st1[i+2]=='d')ar[d]++;}
    
    for (i=1;i<=answ;i++)for (j=i+1;j<=answ;j++){if (ans[i]>ans[j]){t=ans[i];ans[i]=ans[j];ans[j]=t;};}
    for (i=1;i<=answ;i++){if (i>1)cout<<" ";cout<<ans[i];}cout<<endl;
cin.get();cin.get();cin.get();
return 0;}