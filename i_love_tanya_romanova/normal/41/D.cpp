/*
Lobet den Herrn
Lobet den Herrn
We take the church by storm

Wake up the servants of Christ
Here comes the holy deceiver
Take on the horror alive
Nathan, the prophet, the seer

Now it's the time to recite
Words from the Ave Maria
The power of Judas denied
Ride in the storm with no fear

Pay to pray
Inquisition day
Betray no religion
Break the chain
Sanctify your soul

Lobet den Herrn
Lobet den Herrn
We take the church by storm

Open the bible at night
Look up the book Nehemia
Are you prepared for the rite?
When Armageddon is near

Wait for the omen, the sign
Soldiers to follow the leader
Call for salvation divine
Enter the night of the healer

Pay to pray
Inquisition day
Betray no religion
Break the chain
Sanctify your soul

Sanctus horus, Pilatus, bringer of destiny
Sanctus horus, Pilatus, bringer of destiny
Sanctus codes, Herodes, keeper of sacristy
Sanctus horus, Pilatus, beware the see

Oh, we take the church by storm
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define double long double

using namespace std;

long n,m,k,bst[200][200][13];
long t;
long par[200][200][13];
long answ,ap;
vector<string> av;
long vall[200][200];
long ar;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=0;i<=n+1;i++)
 for (int j=0;j<=m+1;j++)
  for (int p=0;p<=k;p++)
   bst[i][j][p]=-1e9;

for (int j=0;j<=m+1;j++)
bst[0][j][0]=0;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  {
    char t;
     cin>>t;
     t-=48;
     vall[i][j]=t%(k+1);
     
  for (int p=0;p<=k;p++)
  {   bst[i][j][(p+t)%(k+1)]=bst[i-1][j-1][p];
     par[i][j][(p+t)%(k+1)]=1;
     if (bst[i-1][j+1][p]>bst[i-1][j-1][p])
     {
      bst[i][j][(p+t)%(k+1)]=bst[i-1][j+1][p];
      par[i][j][(p+t)%(k+1)]=2;
     }
     bst[i][j][(p+t)%(k+1)]+=t;
  }
 }

answ=-1e9;
ap=0;
for (int i=1;i<=m;i++)
if (bst[n][i][0]>answ)
{answ=bst[n][i][0];ap=i;}

if (answ<0){cout<<-1<<endl;return 0;}

cout<<answ<<endl;
cout<<ap<<endl;

for (int i=n;i-1;--i)
{
    if (par[i][ap][ar]==1){ar=(ar+k+1-vall[i][ap])%(k+1);
    av.push_back("L");--ap;}
    else
    {ar=(ar+k+1-vall[i][ap])%(k+1);
        ++ap;av.push_back("R");
    }
}
for (int i=0;i<av.size();i++)
cout<<av[i];
cout<<endl;

cin.get();cin.get();
return 0;}