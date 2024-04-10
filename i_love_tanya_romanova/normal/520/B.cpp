/*
The strike of midnight
All is silent, all is Hell
The dream evades us
In this endless nightmare cell

The stones lie forsaken
Only shadows here collide
Once more the world has turned
And left its children aside

"Even the crows have long since fled these tombstones..."

The crows have long since fled these tombstones
No fresh meat left for the beasts of the earth
Our throes have led us to new dimensions (of death)
Further away each day from joy and mirth

Lightless is the path, on this forlorn trail
Bleak are the days, full of death and travail

After battles lost that no one won
Still cold beneath the Sun

Our woes have long since fled these tombstones
The last signs of life left on this earth
Echoes resounding through empty halls and thrones
Deeper each day into our monstrous birth

"Further away from joy and mirth
Deeper into the arms of this monstrous birth..."

Despite the promise of fire
Still cold beneath the Sun
Depths of this Hell transpired
Our salvation remains undone
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

long n,m,dist[1<<20];
queue<long> qu;
long temp;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<=200000;i++)
 dist[i]=1e9;
dist[n]=0;
qu.push(n);
while (qu.size())
{
 temp=qu.front();
 qu.pop();
 if (temp>1&&dist[temp-1]>dist[temp]+1)
  dist[temp-1]=dist[temp]+1,
  qu.push(temp-1);
 if (temp<100000&&dist[temp*2]>dist[temp]+1)
  dist[temp*2]=dist[temp]+1,
  qu.push(temp*2);
}

cout<<dist[m]<<endl;

cin.get();cin.get();
return 0;}