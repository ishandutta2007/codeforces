/*  
I stab you right between the eyes
You awaken from the lies
I said it ever since the inception
Where the masters of deception
I'm a godless heretic
Not a god-fearing lunatic
That's why it's become my obsession
To treat God like an infection

My scars insane, my life profane
I deny, defy, and spread a little hate, worldwide!

Like a storm that devastates
Religious doubt I instigate
Take a listen to my confession
There is no filter on my aggression
With a blister open wide
To keep the massacre alive
I got cold devastation
With my moral imperfection

My scars insane, my life profane
I deny, defy, and spread a little hate, worldwide!

Religious death, I instigate
From what the bible demonstrates
Does it document creation
Of this hopeless infliction
Of a godless heretic
Not a god-fearing lunatic
Not a god-fearing lunatic
That's why it's become my obsession
To treat God like an infection

My scars insane, my life profane
I deny, defy, and spread a little hate, worldwide!

Open life scars, crushing open wounds
The walls of this scene will be crashing at you
You left senseless mentally unfit
Never fucking heard from you again
Never fucking heard from again
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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long lst,n;
string st;

bool ok(string st)
{
     long calc=0;
     for (int i=0;i<st.size();i++)
     if (st[i]=='@')++calc;
     if (calc<1)return false;
     if (st[0]=='@')return false;
     if (st[st.size()-1]=='@')return false;
     for (int i=0;i<st.size();i++)
     {
         if (st[i]!='@')continue;
         if (i+1<st.size()&&st[i+1]=='@')return false;
         if (i+2<st.size()&&st[i+2]=='@')return false;
         lst=i;
     }
     return true;
}

void show(string st)
{
     for (int i=0;i<st.size();i++)
     {cout<<st[i];
     if (i>0&&st[i-1]=='@'&&i<lst)cout<<",";}
     cout<<endl;
}
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
if (ok(st))
show(st);
else cout<<"No solution"<<endl;

cin.get();cin.get();
return 0;}