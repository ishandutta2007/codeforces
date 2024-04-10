/*
Death and suffering all around me, no escape so why go on
When no one cares, no one's there, you die inside before you're gone
I've tried to reach the highest point of vision and my dreams appear fulfilled
But held before my eyes is a vision that now lies
Forever searching for the purpose are we running out of time

Waiting while the acid words are feeding
Watching as your will's deteriorating

When I'm dead will you remember all the things I've tried to say?
This cancer inside of me destroying my life, when I rot in the ground will you care?
The sands of time are pointless in a useless ugly world
Nothing brings peace of mind, I leave nothing behind if my words are left unheard

Waiting while the acid words are feeding
Watching as your will's deteriorating

And I've learned to watch the downgrade
And I've learned to follow the eyes behind me
Through the twisting hollow strange roads
To the apex of our fate, so cold

And I hate the way you look at me with your frozen soulless eyes
Deny it, ignore it and cover it in shame in your arrogant nameless void

Waiting while the acid words are feeding
Watching as your will's deteriorating
It's a one way ride and there's nothing you can do
Not even suicide or my acid words can teach you anything useful
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,arp[200][200];
char ar[200][200];
string st;
long flag;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=st.size();j++)
    ar[i][j]=st[j-1];
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 if (ar[i][j]=='#'&&arp[i][j]==0)
 {
  arp[i][j]++;
  arp[i+1][j]++;
  arp[i+2][j]++;
  arp[i+1][j-1]++;
  arp[i+1][j+1]++;
 }
/*
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n;j++)
    cout<<arp[i][j];
    cout<<endl;
}*/

flag=0;
for (int i=1;i<=n+2;i++) 
for (int j=1;j<=n+2;j++)
{
    if (ar[i][j]!='#'&&arp[i][j]>0)flag=1;
    if (arp[i][j]>1)flag=1;
    if (ar[i][j]=='#'&&arp[i][j]==0)flag=1;
}
if (flag)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}