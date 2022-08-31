/*
Build a fire a thousand miles away to light my long way home
I ride a comet
My trail is long to stay
Silence is a heavy stone...
I fight the world and take all they can give
There are times my heart hangs low
Born to walk against the wind
Born to hear my name
No matter where I stand I'm alone

Stand and fight
Live by your heart
Always one more try
I'm not afraid to die
Stand and fight
say what you feel
Born with a heart of steel

Burn the bridge behind you
Leave no retreat
There's only one way home
Those who laugh and crowd the path
And cut each other's throats
Will fall like melting snow
They'll watch us rise with fire in our eyes
They'll bow their heads
Their hearts will hang low
Then we'll laugh and they will kneel
And know this heart of steel was
Too hard to break
Too hard to hold

Stand and fight
Live by your heart
Always one more try
I'm not afraid to die
Stand and fight
Say what you feel
born with a heart of steel
*/


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
#define div iryiwrydsfhkljfbhvbS
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std; 

long arp[250000][5],ar[250000],n,end[250000][5];
long long div[250000][5];

void dfs(long v,long move)
{
  //   cout<<v<<" "<<move<<endl;
     
 arp[v][move]=1;
     
 long long q,t;
 
 t=ar[v];
 if (move==2)q=v+ar[v]; 
 else q=v-ar[v];
 
          if (q>n||q<=0)
          {
           end[v][move]=1;
           div[v][move]=ar[v];
           return;                 
          }   
          else if (q==1)
          {
           return;
          }
          
          else
          {
            if (arp[q][5-move]==0)
           dfs(q,5-move);
           
           
            if (end[q][5-move]){end[v][move]=1;div[v][move]=div[q][5-move]+t;}
            else
            {return;}
            }
     
}

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=2;i<=n;i++)
cin>>ar[i];

dfs(4,3);

for (int i=2;i<=n;i++){
if (arp[i][2]==0)
{
                 dfs(i,2);
}
if (arp[i][3]==0)
dfs(i,3);
}

for (int i=2;i<=n;i++)
{
    if (end[i][3]==0)
    cout<<-1<<endl;
    else cout<<div[i][3]+i-1<<endl;
}

/*for (int i=1;i<=n;i++)
cout<<end[i][2]<<" "<<div[i][2]<<"   "<<end[i][3]<<" "<<div[i][3]<<endl;
*/

cin.get();cin.get();
return 0;}