#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long d,s,a[200000],b[200000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>d>>s;
for (int i=1;i<=d;i++)
{
    cin>>a[i]>>b[i];s-=a[i];
}
for (int i=1;i<=d;i++)
{
    while (a[i]<b[i]&&s>0){--s;++a[i];}
}
if (s)cout<<"NO"<<endl;
else{cout<<"YES"<<endl;
for (int i=1;i<=d;i++)
{if (i>1)cout<<" ";cout<<a[i];}
cout<<endl;
}
cin.get();cin.get();
return 0;}