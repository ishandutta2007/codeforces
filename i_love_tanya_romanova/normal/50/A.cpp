#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#define M_PI        3.14159265358979323846
using namespace std;
long i,n,m,ans[100][100],j,t;
int main(){
//freopen("length.in","r",stdin);freopen("length.out","w",stdout);
cin>>n>>m;
cout<<(n*m-((n*m)%2))/2<<endl;
cin.get();cin.get();cin.get();
return 0;}