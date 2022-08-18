#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#pragma comment(linker, "/STACK:20000000")
#define M_PI		3.14159265358979323846
using namespace std;
long i,j,n,ar[10000][10],un[10000],ans,p,e;string st;
int main(){
cin>>n;getline(cin,st);

for (i=1;i<=n;i++){getline(cin,st);ar[i][1]=st[0];ar[i][2]=st[1];
getline(cin,st);ar[i][3]=st[1];ar[i][4]=st[0];
for (j=5;j<=8;j++)ar[i][j]=ar[i][j-4];
getline(cin,st);}
for (i=1;i<=n;i++){un[i]=0;p=0;
for (j=i+1;j<=n;j++){for (e=0;e<=4;e++)if (ar[i][1]==ar[j][1+e]&&ar[i][2]==ar[j][2+e]&&ar[i][3]==ar[j][3+e]&&ar[i][4]==ar[j][4+e])
p++;}if (p==0)un[i]++;;}
for (i=1;i<=n;i++)if (un[i])ans++;
cout<<ans<<endl;
cin.get();cin.get();cin.get();
return 0;}