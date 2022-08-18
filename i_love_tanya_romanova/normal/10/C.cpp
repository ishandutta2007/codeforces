//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;  

long long dig1,dig2,td,way[100][100],a,tcalc,n,t,ans,calc[1000];

long gr(long a)
{
     long s=0;
     while(a){s+=a%10;a/=10;}
     return s;
}

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int dig1=1;dig1<=9;dig1++)
for (int dig2=1;dig2<=9;dig2++)
{
    td=dig1*dig2;
    while(td>9)td=gr(td);
    way[dig1][dig2]=td;
}

for (int i=1;i<=n;i++)
{
 a=i;
 while(a>9)a=gr(a);
 calc[a]++;   
}

for (int i=1;i<=n;i++)
{
    for (int j=1;j*i<=n;j++)
    {
        tcalc++;
    }
}

for (int i=1;i<=9;i++)
for (int j=1;j<=9;j++)
{
 t=way[i][j];
 ans+=calc[i]*calc[j]*calc[t];   
}

//cout<<ans<<" "<<tcalc<<endl;
cout<<ans-tcalc<<endl;
cin.get();cin.get();
return 0;}