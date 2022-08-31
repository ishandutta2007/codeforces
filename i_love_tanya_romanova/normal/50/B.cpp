#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#define M_PI        3.14159265358979323846
using namespace std;
char ch;
long long i,ar[1000],ans;
int main(){
//freopen("length.in","r",stdin);freopen("length.out","w",stdout);

while (cin>>ch)ar[ch]++;
for (i=1;i<=255;i++){ans+=ar[i]*ar[i];}
cout<<ans<<endl;
cin.get();cin.get();cin.get();
return 0;}