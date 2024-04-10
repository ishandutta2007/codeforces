/*
I hear you calling me
Just like the voices in a dream
I hear you calling me
Just like the voices in a dream
I can remember
Daylight dancing in your eyes
And when my mind is still
The memories come alive
The silent space between my thoughts
Is where your soul resides
And when my heart is still
The memories come to life
Memories haunting me
They echo through eternity
I hear you calling me
Just like the voices in a dream
When fear and darkness overcome
I have no need to hide
I only need to call your name
In my heart you are still alive
The silent space between my thoughts
Is where your soul resides
And when my heart is still
The memories come to life
Voices in a dream
Voices in a dream
Memories haunting me
They echo through eternity
I hear you calling me
Just like the voices in a dream
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

string st1,st2;
long n,a,b;
long cnt[100][100],lst[100][100];
long dist;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st1>>st2;

for (int i=0;i<st1.size();i++)
{
 a=st1[i]-'a';
 b=st2[i]-'a';
 if (a!=b){
           ++cnt[a][b];
           lst[a][b]=i;
           ++dist;
           }
}

for (int i=0;i<n;i++)
{
    a=st1[i]-'a';
    b=st2[i]-'a';
    if (a!=b&&cnt[b][a]!=0)
    {
     cout<<dist-2<<endl;
     cout<<lst[a][b]+1<<" "<<lst[b][a]+1<<endl;
     return 0;
    }
}
for (int i=0;i<n;i++)
{
    a=st1[i]-'a';
    b=st2[i]-'a';
    if (a!=b)
    {
     for (int j=0;j<26;j++)
      if (cnt[b][j]!=0)
      {
       cout<<dist-1<<endl;
       cout<<lst[b][j]+1<<" "<<i+1<<endl;
       return 0;
      }
    }
}

cout<<dist<<endl;
cout<<-1<<" "<<-1<<endl;

cin.get();cin.get();
return 0;}