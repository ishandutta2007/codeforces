/*
Fading, falling, lost in forever
Will I find a way to keep it together?
Am I strong enough to last through the weather in the hurricane of my life?
Can it be a conscious decision?
That I look for ways to alter my vision?
Am I speeding towards another collision in the alleyways of my life?

Memories don't lie
You know better than
Memories don't lie
You know better than
Memories don't lie
You know better than
Those who have fallen in
Memories don't lie
You know better than
Memories don't lie
You know better than
Memories don't lie
You know better than
Those who have fallen in

Please believe me
That my eyes deceive me?
Don't stand me up
Just leave me
I have fallen again
This is the end
Pain redefined

Shaking, burning up with the fever
In the realm of pain, I am the deceiver
Now I lie to myself, so I can believe her
As she disassembles my life
I cannot dispel the illusion
All my hopes and dreams are drowned by confusion
Can I find a way to make a solution that will reconfigure my life?

Memories don't lie
You know better than
Memories don't lie
You know better than
Memories don't lie
You know better than
Those who have fallen in
Memories don't lie
You know better than
Memories don't lie
You know better than
Memories don't lie
You know better than
Those who have fallen in

Please believe me
That my ears deceive me
Don't stand me up
Just leave me
I have fallen again
This is the end
Pain redefined

And I know that stillness shatters
We have all been frightened by the
The sound of footsteps on the pavement of our lives
I stand and fight
I'm not afraid to die
Elochai, bury me tonight

Please believe me
That the world deceives me
Don't stand me up
Just leave
I have fallen again
This is the end
Pain redefined
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
#define clone agsdahfaassdg

using namespace std;

long n,m,ar[200][200],si[200],sj[200],calci[200],calcj[200];
vector<long> ans1,ans2;
long temp,inv;

long bi()
{
 for (int i=1;i<=n;i++)
 if (si[i]<0)return i;
 return -1;
}

long bj()
{
 for (int i=1;i<=m;i++)
 if (sj[i]<0)return i;
 return -1;
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    cin>>ar[i][j];
}

for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    {
        si[i]+=ar[i][j];
        sj[j]+=ar[i][j];
    }
}

while (true)
{
 inv=0;
 temp=bi();
 if (temp>0)
 {
  inv=1;
  calci[temp]++;
  si[temp]=-si[temp];
  for (int i=1;i<=m;i++)
  {
      sj[i]=sj[i]-2*ar[temp][i];
      ar[temp][i]=-ar[temp][i];
  }
 }
 temp=bj();
 if (temp>0)
 {
  inv=1;
  calcj[temp]++;
  sj[temp]=-sj[temp];
  for (int i=1;i<=n;i++)
  {
      si[i]=si[i]-2*ar[i][temp];
      ar[i][temp]=-ar[i][temp];
  }
 }
 if (inv==0)break;
}

for (int i=1;i<=n;i++)
if (calci[i]%2)ans1.push_back(i);
for (int i=1;i<=m;i++)
if (calcj[i]%2)ans2.push_back(i);

cout<<ans1.size();
for (int i=0;i<ans1.size();i++)
cout<<" "<<ans1[i];
cout<<endl;
cout<<ans2.size();
for (int i=0;i<ans2.size();i++)
cout<<" "<<ans2[i];
cout<<endl;

cin.get();cin.get();
return 0;}