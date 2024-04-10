/*
Graze the skin with my finger tips
The brush of dead cold flesh pacifies the means
Provocative images delicate features so smooth
A pleasant fragrance in the light of the moon

[Chorus:]
Dance with the dead in my dreams
Listen to their hallowed screams
The dead have taken my soul
Temptation's lost all control

Simple smiles elude psychotic eyes
Lose all mind control rationale declines
Empty eyes enslave the creations
Of placid faces and lifeless pageants

In the depths of a mind insane
Fantasy and reality are the same

Graze the skin with my finger tips
The brush of dead warm flesh pacifies the means
Incised members ornaments on my being
Adulating the skin before me

Simple smiles elude psychotic eyes
Lose all mind control rationale declines
Empty eyes enslave the creations
Of placid faces and lifeless pageants

[Chorus x2]
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,ar[100][100];
long oki[1000],okj[10000];

long solve()
{
     for (int i=1;i<n;i++)
      if (ar[i][1]||ar[i][m])return 2;
     for (int i=1;i<m;i++)
      if (ar[1][i]||ar[n][i])return 2;
     
/*     for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
     {if (ar[i][j])oki[i]=1;okj[j]=1;}
     
     for (int i=1;i<n;i++)
     if (ar[i][1]||ar[i][m])
     if (oki[i+1])return 3;
     
     for (int i=1;i<m;i++)
     if (ar[1][i]||ar[n][i])
     if (okj[i+1])return 3;*/
     return 4;
}
int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     cin>>ar[i][j];
 }

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}