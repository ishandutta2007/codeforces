/*
They came for him one winter's night.
Arrested, he was bound.
They said there'd been a robbery,
his pistol had been found.

They marched him to the station house,
he waited for the dawn.
And as they led him to the dock,
he knew that he'd been wronged.
"You stand accused of robbery,"
he heard the bailiff say.
He knew without an alibi,
tomorrow's light would mourn his freedom.

Over the hills and far away,
for ten long years he'll count the days.
Over the mountains, and the seas,
a prisoner's life for him there'll be.

He knew that it would cost him dear,
but yet he dare not say.
Where he had been that fateful night,
a secret it must stay.
He had to fight back tears of rage.
His heart beat like a drum.
For with the wife of his best friend,
he spent his final night of freedom.

Over the hills and far away,
he swears he will return one day.
Far from the mountains and the seas,
back in her arms he swear he'll be.
Over the hills and far away.

Over the hills and, over the hills and,
over the hills and far away.

Each night within his prison cell,
he looks out through the bars.
He reads the letters that she wrote.
One day he'll know the taste of freedom.

Over the hills and far away,
she prays he will return one day.
As sure as the rivers reach the seas,
back in his arms he swears she'll be.

Over the hills and far away,
he swears he will return one day.
far from the mountains and the seas,
back in her arms is where he'll be.

Over the hills and far away,
she prays he will return one day.
As sure as the rivers reach the seas,
back in his arms is where she'll be.

Over the hills,
over the hills and far away.

Over the hills,
over the hills and far away.
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
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

using namespace std;

long n,ar[200],g[200][200],t,fl;
void add_edge(long a,long b)
{
     g[a][b]=1;g[b][a]=1;
}

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n;i++)
{
    cin>>t;for (int j=1;j<=n;j++)
    if (abs(i-j)==t)add_edge(i,j);
}

for (int i=1;i<=n;i++)
g[i][i]=1;

fl=0;
for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
    g[i][j]=(g[i][j]|(g[i][k]&g[k][j]));

for (int i=1;i<=n;i++)
if (g[i][ar[i]]==0)fl=1;
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
cin.get();cin.get();
return 0;}