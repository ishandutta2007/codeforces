/*
Words that are sealed in blood
Your tongue speaks unhonestly
Whatever leaves your lips
Insanity

The truth is eloquent
A vision not mine to share
Whatever is hiding in your shell
Disgusting and cruel

Temptated by sirens
Temptated by blood
Just try to resist them
Be your own god

Keep breeding your lies
It leads us to fall from the sky
A look in your eyes
I see that our past was alie
You once meant the world
Now I can see right through you
The promise you broke
I see right through you

The facts they show no doubt
You're nothing than a nameless face
Whatever is hiding in your shell
Disgusting and cruel
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
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

vector<long long> vec;
long long w[1<<10],h[1<<10],n,ans,tw,lie;
long long tl;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>w[i]>>h[i];
}

ans=1e18;

for (int mh=1;mh<=1000;mh++)
{
 tw=0;
 lie=0;
 vec.clear();
 
 for (int i=1;i<=n;i++)
 {
  if (h[i]>mh&&w[i]>mh){tw=1e9;break;}
  if (h[i]>mh){tw+=h[i];lie++;continue;}
  if (w[i]>mh){tw+=w[i];continue;}
  tw+=min(h[i],w[i]);
  vec.push_back(h[i]-w[i]);
 }
 
 if (lie*2>n)continue;
 
 sort(vec.begin(),vec.end());
 tl=lie+vec.size();
 while (tl*2>n)
 {
  if(vec.back()<0)tw-=vec.back();
  vec.pop_back();
  tl--;
 }
 /*
 if (mh<50)
  cout<<" "<<mh<<" "<<tw<<endl;
  */
 ans=min(ans,tw*mh);   
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}