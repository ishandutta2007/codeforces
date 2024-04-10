/*
Been here before, been here before
Been here before, been here before
Been here before, been here before

Been here before couldn't say I liked it
Do I start writing all this down?
Just let me plug you into my world
Can't you help me be un crazy?

Name this for me, heat the cold air
Take the chill off of my life
And if I could I'd turn my eyes
To look inside to see what's comin'

It comes alive, it comes alive
It comes alive and I die a little more
It comes alive, it comes alive
It comes alive each moment here I die a little more
Ooh, I die, I die, I die a little more

Then the unnamed feeling
It comes alive
Then the unnamed feeling
Takes me away

Been here before, been here before
Been here before, been here before
Been here before, been here before

I'm frantic in your soothing arms
I can not sleep in this down filled world
I've found safety in this loneliness
But I cannot stand it anymore

I cross my heart and hope not to die
Swallow evil, ride the sky
Lose myself in a crowded room
You fool, you fool, it will be here soon

It comes alive, it comes alive
It comes alive and I die a little more
It comes alive, it comes alive
It comes alive each moment here I die a little more
Ooh, I die, I die, I die a little more

Then the unnamed feeling
It comes alive
Then the unnamed feeling
Treats me this way

And I wait for this train
Toes over the line
And then the unnamed feeling
It takes me away
It takes me

Then the unnamed feeling
It comes alive, yeah-e-yeah
Then the unnamed feeling
It takes me away
Yeah, it takes me away

Get the fuck out of here
I just wanna get the fuck away from me
I rage, I glaze, I hurt, I hate
It hate it all, why, why, why me?

I cannot sleep with a head like this
I wanna cry, I wanna scream
I rage, I glaze, I hurt, I hate
I wanna hate it all away

Then the unnamed feeling
It comes alive, yeah-e-yeah
Then the unnamed feeling
Treats me this way, yeah

Then I wait for this train
My toes are over the line, yeah
Then the unnamed feeling
It takes me away
Yeah, it takes me away

Then the unnamed feeling
It comes alive
Then the unnamed feeling
It takes me away
*/

#pragma comment(linker, "/STACK:16777216")
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

using namespace std;

long n,m,k;
vector<pair<long,long> > ans[200000];
long cur;

void move(long a,long b)
{
 if (cur<k&&ans[cur].size()==2)++cur;
 ans[cur].push_back(make_pair(a,b));
}
int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
cur=1;

for (int i=1;i<=n;i++)
{
 if (i%2)for (int j=1;j<=m;j++)
 move(i,j);
 else for (int j=m;j;--j)
  move(i,j);
}

for (int i=1;i<=k;i++)
{
 cout<<ans[i].size();
 for (int j=0;j<ans[i].size();j++)
 {
  cout<<" "<<ans[i][j].first<<" "<<ans[i][j].second;
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}