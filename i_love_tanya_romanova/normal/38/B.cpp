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

string st1,st2;
long x1,y1,x2,y2,ans;
long ar[100][100];

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;


x1=st1[0]-'a'+1;
y1=st1[1]-'0';

x2=st2[0]-'a'+1;
y2=st2[1]-'0';

ar[x1][y1]=1;
ar[x2][y2]=1;

for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)
{
    if (i==x1)ar[i][j]=1;
    if (j==y1)ar[i][j]=1;
    
    if (abs((i-x1)*(j-y1))==2)ar[i][j]=1;
    if (abs((i-x2)*(j-y2))==2)ar[i][j]=1;
}

ans=64;
for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)
ans-=ar[i][j];
cout<<ans<<endl;

cin.get();cin.get();
return 0;}