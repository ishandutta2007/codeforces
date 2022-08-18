#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
long long n,i,ar[10000];
int main()
{//freopen("C://input.txt","r",stdin);freopen("C://output.txt","w",stdout);
cin>>n;
ar[1]=10;
ar[2]=15;
ar[3]=6;
for (i=4;i<=50;i++){ar[i]=ar[i-1]*2;//cout<<ar[i]<<endl;
}
if(n==2)cout<<-1<<endl; else {
for (i=1;i<=n;i++)cout<<ar[i]<<endl;}
cin.get();cin.get();
return 0;}