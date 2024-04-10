/*
The altar covered
in lifegiving cum
the smell of
forever running wet cunts

Flesh and sweat
dancing bare limbs around the fire
the sound of clashing
wet bodies and sighs

Dry throats and warm blood
the rite, the collecting of sperm
and milk from young breasts

Lust instead of Gods
on the altar of masturbating
fuckin' human flesh

Wet limbs lie down
to dry in the wind
sumbols painted with blood
on bare skin

Earth now nourished
with milk and with cum
celebration of nature
is done

Come sun and gentle rain
our gift is made
so that the soil can give birth

The sead and milk remains
in the domains of the deep womb
of mother Earth
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

long n,a,b,deg[200000],temp,fl,ans[200000];
vector<long> g[200000];
long used[200000];
long done[10][10];
bool good(long a,long b)
{
     for (int i=0;i<g[a].size();i++)
     if (g[a][i]==b)return true;
     return false;
}

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n*2;i++)
{
    cin>>a>>b;
    deg[a]++;
    deg[b]++;
    if (deg[a]>4||deg[b]>4){fl=1;break;}
    g[a].push_back(b);
    g[b].push_back(a);   
}

if (fl){cout<<-1<<endl;return 0;}

ans[1]=1;
used[1]=1;

for (int i=0;i<g[1].size();i++)
 for (int j=0;j<g[1].size();j++)
  if (good(g[1][i],g[1][j])&&done[i][j]==0)
  {ans[2]=g[1][i];ans[n]=g[1][j];done[i][j]=1;
  
  for (int q=3;q<n;q++)
  ans[q]=0;
  for (int q=1;q<=n;q++)
  used[q]=0;
  used[1]=1;
  used[ans[2]]=1;used[ans[n]]=1;

//cout<<ans[2]<<" "<<ans[n]<<endl;

for (int ii=2;ii<=n-2;ii++)
{
    temp=ans[ii];
    for (int jj=0;jj<g[temp].size();jj++)
    {
     if (good(g[temp][jj],ans[ii-1])&&used[g[temp][jj]]==0)
        {ans[ii+1]=g[temp][jj];used[ans[ii+1]]=1;break;}
    }
}

long fl=0;
for (int ii=1;ii<=n;ii++)
if (ans[ii]==0)fl=1;
if (fl==0)
{
for (int ii=1;ii<=n;ii++)
{if (ii-1)cout<<" ";
cout<<ans[ii];}
cout<<endl;cin.get();cin.get();
return 0;}

}
cout<<-1<<endl;

cin.get();cin.get();
return 0;}