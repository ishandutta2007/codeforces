/*
Hanging from a noose
Wrapped tightly around my neck
The sentence passed in haste
The verdict incorrect

Hangman ties the blindfold
Life flashes before my eyes
I speak my last words
Why must I die?

Trapped here in this bedroom
As the cancer eats away at me
Each and every day, I am withering away
Undergoing chemotherapy

Disease consumes my body
The cure consumes my mind
Put me out of my misery
Just let me die

Screams of the dying
The silence of the dead
You won't last
Shattered like glass

Screams of the dying
The silence of the dead
Nothing lasts
Shattered like glass

Thrown through the front window
A thousand sudden lacerations
Injured and disfigured
Life becomes damnation

Cornered like an animal
I struggle to break free
Cannot face the horror
Of my own mortality

We are falling into early graves

Help me, I am dying
And I cannot see the light
Icy hands of death reach out
And pull me into the night

Nothing ever lasts
You won't last
The long silence begins
You've been shattered
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
#define count adsgasdgasdg

using namespace std;

long long n,k,s[1<<20],m[1<<20];
set<pair< long long,long long> > ::iterator it;
set<pair<long long, long long> > S;
long long fr;
pair<long long, long long> tp;
queue<long long> qu;
long long temp;
long long ans[1<<20];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>s[i]>>m[i];
 S.insert(make_pair(s[i],i));
}
fr=k;
int itr=1;

while (S.size())
{
 it=S.begin();
 tp=(*it);
 S.erase(it);
 if (tp.second<0)
 {
  fr++;
  if (qu.size()>0)
  {
   temp=qu.front();
   qu.pop();
   ans[temp]=tp.first+m[temp];
   S.insert(make_pair(ans[temp],-itr));
   ++itr;
   --fr;
  }
 }
 else
 {
  if (fr==0)
  {
   qu.push(tp.second);
   continue;
  }
  else
  {
   --fr;
   temp=tp.second;
   ans[temp]=tp.first+m[temp];
   S.insert(make_pair(ans[temp],-itr));
   ++itr;
  }
 }
}

for (int i=1;i<=n;i++)
{
 cout<<ans[i]<<endl;
}

cin.get();cin.get();
return 0;}