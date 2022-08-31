/*
I drown in the sadness of your eyes
Behind them the knowing
My every touch turns to ash
My every word fades to silence

No saviour in the beat of your heart
From this curse that drags me down
Suffocating veil of misery
The foreshadow of my demise

The warmth of a thousand suns, drawn away
And fade before my eyes
The Inevitable End, I always knew would be
The truth you could always see

Once again cast unto the dark
To the coldest night, and misery's dawn
But with it, I shall depart
And feel your warmth once more...
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long x[100],y[100];
long d,mx,my;
set<pair<long, long> > has,sett;
set<pair<long, long> > ::iterator it;
pair<long, long> tp;
vector<pair<long, long> > ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x[0]>>y[0]>>x[1]>>y[1];

if (x[0]!=x[1]&&y[0]!=y[1]&&abs(x[1]-x[0])!=abs(y[1]-y[0]))
{
 cout<<-1<<endl;
 return 0;
}

d=max(abs(x[1]-x[0]),abs(y[1]-y[0]));

/*for (int mask1=0;mask1<4;mask1++)
for (int mask2=0;mask2<4;mask2++)
{
 x[2]=x[mask1%2];
 x[3]=x[mask1/2];
 y[2]=y[mask2%2];
 y[3]=y[mask2/2];
 if (dif()==4){
 ok();break;}
}
*/

mx=min(x[0],x[1]);
my=min(y[0],y[1]);
sett.insert(make_pair(mx,my));
sett.insert(make_pair(mx+d,my));
sett.insert(make_pair(mx,my+d));
sett.insert(make_pair(mx+d,my+d));
has.insert(make_pair(x[0],y[0]));
has.insert(make_pair(x[1],y[1]));

for (it=sett.begin();it!=sett.end();it++)
{
 tp=(*it);
 if (has.find(tp)==has.end())
 ans.push_back(tp);
}

cout<<ans[0].first<<" "<<ans[0].second<<" "<<ans[1].first<<" "<<ans[1].second<<endl;

cin.get();cin.get();
return 0;}