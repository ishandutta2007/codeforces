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
long n;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;++n;
for (int i=0;i<n;i++)
{
    for (int j=i-n+1;j<=i;j++)
    {if (j!=i-n+1)cout<<" ";
     if (j<0)cout<<" "; else cout<<j;
    }
    for (int j=i-1;j>=0;--j)
    {cout<<" ";
     cout<<j;
}     cout<<endl;
}

for (int i=n-2;i>-1;i--)
{
    for (int j=i-n+1;j<=i;j++)
    {if (j!=i-n+1)cout<<" ";
     if (j<0)cout<<" "; else cout<<j;
    }
    for (int j=i-1;j>=0;--j)
    {cout<<" ";
     cout<<j;
}     cout<<endl;
}
cin.get();cin.get();
return 0;}