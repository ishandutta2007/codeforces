/*
I follow the Moskva
Down to Gorky Park
Listening to the wind of change
An August summer night
Soldiers passing by
Listening to the wind of change

The world is closing in
Did you ever think
That we could be so close, like brothers
The future's in the air
I can feel it everywhere
Blowing with the wind of change

Take me to the magic of the moment
On a glory night
Where the children of tomorrow dream away
in the wind of change

Walking down the street
Distant memories
Are buried in the past forever
I follow the Moskva
Down to Gorky Park
Listening to the wind of change

Take me to the magic of the moment
On a glory night
Where the children of tomorrow share their dreams
With you and me
Take me to the magic of the moment
On a glory night
Where the children of tomorrow dream away
in the wind of change

The wind of change
Blows straight into the face of time
Like a stormwind that will ring the freedom bell
For peace of mind
Let your balalaika sing
What my guitar wants to say

Take me to the magic of the moment
On a glory night
Where the children of tomorrow share their dreams
With you and me
Take me to the magic of the moment
On a glory night
Where the children of tomorrow dream away
in the wind of change
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

string zr[1000];
long n;

string solve()
{
       string st;
 for (char a='a';a<='z';a++)
 {
     st=a;
     long fl=0;
     for (int i=1;i<=n;i++)
     if (zr[i].find(st)!=-1)
     fl=1;
     if (fl==0)return st;
 }
 for (char a='a';a<='z';a++)
 for (char b='a';b<='z';b++)
 {   st=a;st+=b;
     long fl=0;
     for (int i=1;i<=n;i++)
     if (zr[i].find(st)!=-1)
     fl=1;
     if (fl==0)return st;
 }
}

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


cin>>n;
for (int i=1;i<=n;i++)
cin>>zr[i];

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}