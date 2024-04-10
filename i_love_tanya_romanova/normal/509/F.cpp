/*
Form the day you saw his face
You knew that he was yours
You saw your life in his blue eyes

No he sleeps the endless dream
Death always comes too soon
You linger your days counting out time

Wasting away crying in vain
Colours have turned to white and gray
You wait for your love to take you across again

Wasting away crying in vain
Colours have turned to white and gray
You wait for your love to take you across again
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long long n,ar[1<<10],ans[1<<10][1<<10],part[1<<10][1<<10];

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int l=n;l>=1;--l)
{
 for (int r=l;r<=n;r++)
 {
  if (l==r)
  {
   ans[l][r]=1;
  }
  else
  {
   ans[l][r]=part[l+1][r];
  }
  part[l][r]=ans[l][r];
  for (int j=l+1;j<=r;j++)
   if (ar[j]>ar[l])
   part[l][r]+=ans[l][j-1]*part[j][r]%bs;
  part[l][r]%=bs;
  ans[l][r]%=bs;
 }
}

cout<<ans[1][n]<<endl;

cin.get();cin.get();
return 0;}