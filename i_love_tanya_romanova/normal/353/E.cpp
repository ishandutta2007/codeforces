/*
From the sky it came to bring
The seeds of slavery
For a mind insane an armageddon fantasy
Cure religion for the weak foundtion of all laws
Redefines philosophy a tyranny from above

Soul Eraser - penetrates your dying mind
Soul Eraser - takes your empty soul tonight

Immortal imperator from a planet far away
A comsiousless dictator hirarchy in mortal planes
A universal tyrant no emotions no regrets
Phantasmagoric dream disguise for a silent death

The sacred shrine is poisoned
A treasure for the dead
For thousend years a secret
In the dark great pyramid
See the gods descending
See our people die
Mighty kings of shadows
Cannot be destroyed

Mighty god-king save us from this scorn under the sun
Lead us to salvation as you say things will be done
All those years of suffering starvation and demise
End with the enthronement of the savior from the skies

Soul Eraser - penetrates your dying mind
Soul Eraser - takes your empty soul tonight

Immortal imperator from a planet far away
A comsiousless dictator hirarchy in mortal planes
A universal tyrant no emotions no regrets
Phantasmagoric dream disguise for a silent death
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

long n;
string st;
long inc[2000000],outc[2000000];
vector<long> g[2000000],gr[2000000];
long usd[2000000];
long ans;

void dfs(long v)
{
 usd[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];dfs(q);
 }
}
void rdfs(long v)
{
 usd[v]=1;
 for (int i=0;i<gr[v].size();i++)
 {long q=gr[v][i];rdfs(q);}
 
}
int main(){
//freopen("unionday.in","r",stdin);
//freopen("unionday.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
n=st.size();

for (int i=0;i<st.size();i++)
{
    if (st[i]=='0'){inc[(i+1)%n]++;outc[i%n]++;g[i].push_back((i+1)%n);gr[(i+1)%n].push_back(i);}
    else {inc[i%n]++;outc[(i+1)%n]++;g[(i+1)%n].push_back(i);gr[i].push_back((i+1)%n);}
}

for (int i=0;i<n;i++)
{
    if (usd[i]==0&&inc[i]>0&&outc[i]>0)
    {
     ++ans;
     dfs(i);rdfs(i);
    }
}

for (int i=0;i<n;i++)
{
    if (usd[i]==0)
    {++ans;dfs(i);rdfs(i);}
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}