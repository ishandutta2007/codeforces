//#pragma comment(linker, "/STACK:16777216")
//#include <fstream>
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
#define eps 1e-9
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

long ar[100][100],s[10],ts,ans;

int main(){
//freopen("horse.in","r",stdin);
//freopen("horse.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
{
    cin>>ar[i][j];
    s[i]+=ar[i][j];
}

ans=-1;
for (int i=1;i<=100000;i++)
{
    ts=s[1]+i;
    if (ts-s[2]<=100000&&ts-s[2]>0)
    if (ts-s[3]<=100000&&ts-s[3]>0)
    if (i+ts-s[3]==ar[3][1]+ar[1][3])
    ans=ts;
}

ar[1][1]=ans-s[1];
ar[2][2]=ans-s[2];
ar[3][3]=ans-s[3];
for (int i=1;i<=3;i++)
{
    for (int j=1;j<=3;j++)
    {
        if (j>1)cout<<" ";
        cout<<ar[i][j];
    }cout<<endl;
}
cin.get();cin.get();
return 0;}