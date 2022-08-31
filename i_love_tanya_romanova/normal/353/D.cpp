/*
Greedy for blood
Paralysed by power
The decision to die
Tales of terror
Deep in the corner
Passion to kill
Corpse on the ground
Minds starts to chill

A man lies in the corner, covered with blood
Bloody wounds on his body, praying to his god
People pass him by, but they say
Why should we care about him? he will die today

Riot of violence

Find your own way
You must go alone
Kill all next to you
They want the throne
The infectious disease
Is the only life
You're scared to death
Die by their knife

A man lies in the corner, covered with blood
Bloody wounds on his body, praying to his god
People pass him by, but they say
Why should we care about him? he will die today

Brutality and mighty wars, warriors start to fight
With bombs and guns, the troops have come to extinguish the light
I'd rather not go wild tonight, but I must save myself

On a field littered with corpses
Stands a lonely flower
It reminds the world how it was
But we kicked it away with power
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

string st;
long fl1,fl2,ans,fems,overd,moves;

long solve(string st)
{
 fl1=fl2=0;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='F')++fl1;
  if (st[i]=='M')++fl2;
 }    
 if (fl1==0||fl2==0)return 0;
 
 ans=0;
 fems=0;
 overd=0;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='M'){if (overd>0)--overd;continue;}
  if (st[i]=='F')
  {
   moves=i-fems;
   ++fems;
   if (moves==0)continue;
   ans=max(ans,moves+overd);
   ++overd;
  }   
 }
 return ans;
}

long usd[2000];

long solve1(string st)
{
       long res=0;
       while (true)
       {
        long fl=0;
        for (int i=st.size()-1;i;--i)
         if (st[i]=='F'&&st[i-1]=='M')fl=1;
         if (fl==0)return res;
         ++res;
         for (int i=0;i<=st.size();i++)
         usd[i]=0;
         for (int i=st.size()-1;i;--i)
          if (st[i]=='F'&&st[i-1]=='M'&&usd[i]==0)
          {
           usd[i-1]=1;swap(st[i],st[i-1]);
          }
       }
}
int main(){
//freopen("unionday.in","r",stdin);
//freopen("unionday.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cout<<solve(st)<<endl;
//cout<<solve1(st)<<endl;

cin.get();cin.get();
return 0;}