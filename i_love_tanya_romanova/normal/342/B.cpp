/*
Alright hold tight
I really wanna ball tonight
On a bender no space defender
A joy on the floor I'll get it tight
Toe to toe with a black widow
Fee fi fum smell the blood of rock 'n' roll
All out drive on a rockin' suicide
My feet are jumpin' she's a joy to ride
Joy to ride, joy to ride
She's a joy to ride on a rockin' suicide
Brain shake, brain shake, brain shake
All I can take
It's a brain shake, brain shake, brain shake

She's a mean lean rockin' machine
A hip huggin' blue jean dream
She's a woman worth givin'
A sweet sweet kissin'
Lips are runnin' round on me
Toe to toe with a black widow
Fee fi fum smell the blood of rock 'n' roll
All out drive on a rockin' suicide
My feet are jumpin' she's a joy to ride
Joy to ride, joy to ride
She's a joy to ride on a rockin' suicide
Brain shake, brain shake, brain shake
Ready to shake
It's a brain shake, brain shake, brain shake
It's a brain shake, brain shake, brain shake
For mercy's sake
It's a brain shake, brain shake, brain shake
Cause she's a joy to ride
Joy to ride, joy to ride
She's an all out drive on a rockin' suicide
Brain shake

Brain shake, brain shake, brain shake
Ready to shake
It's a brain shake, brain shake, brain shake
It's a brain shake, brain shake, brain shake
For mercy's sake
It's a brain shake, brain shake, brain shake
All I could take
It's a brain shake, brain shake, brain shake
You can't fake
It's a brain shake, brain shake, brain shake
Well it's a brain shake, brain shake, brain shake
For mercy's sake
It's a brain shake, brain shake, brain shake
It's a brain
It's a brain
It's a brain
Shake
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,s,f,a,b,c,timer;
set<long> bad;
map<long,pair<long, long> > mapp;
vector<char> ans;

long check(long timer, long ps)
{
     if (bad.find(timer)==bad.end())return 0;
     pair<long, long> tp=mapp[timer];
     if (ps<tp.first||ps>tp.second)return 0;
     return 1;
}
int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>s>>f;
for (int i=1;i<=m;i++)
{
    cin>>a>>b>>c;
    bad.insert(a);
    mapp[a]=make_pair(b,c);
}

while (s!=f)
{
 ++timer;
 b=check(timer,s);
 if (s>f)c=check(timer,s-1);
 else c=check(timer,s+1);
 if (c==1)b=1;
 
 if (b==1){ans.push_back('X');}
      else
      {
           if (s<f){ans.push_back('R');s++;}
           else {ans.push_back('L');--s;}
      } 
}

for (int i=0;i<ans.size();i++)
cout<<ans[i];
cout<<endl;

cin.get();cin.get();
return 0;}