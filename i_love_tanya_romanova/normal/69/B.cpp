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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,l[2000],r[2000],b[2000],c[2000],t[2000],ans[2000],answ;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
b[i]=1000000;

for (int i=1;i<=m;i++)
{
    cin>>l[i]>>r[i]>>t[i]>>c[i];
    for (int j=l[i];j<=r[i];j++)
    {
        if(t[i]<b[j]){b[j]=t[i];ans[j]=c[i];}
    }
}

for (int i=1;i<=n;i++)
answ+=ans[i];
cout<<answ<<endl;

cin.get();cin.get();
return 0;}