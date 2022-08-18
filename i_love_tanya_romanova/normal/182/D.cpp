/*
I feel the wind in my hair
And it's whispering, telling me things
Of a storm that is gathering near
Full of power I'm spreading my wings

Now I'm leaving my worries behind
Feel the freedom of body and mind
I'm starting my journey, I'm drifting away with the wind, I go

I am Hunting High and Low
Diving from the sky above
Looking for, more and more, once again
I'm Hunting High and Low
Sometimes I may win, sometimes I'll lose
It's just a game that I play

After the storm there's a calm
Through the clouds shines a ray of the sun
I'm carried from all my harm
There is no one I can't outrun

Now I'm leaving my worries behind
Feel the freedom of body and mind
I'm starting my journey, I'm drifting away with the wind, I go

[Repeat: x2]
I am Hunting High and Low
Diving from the sky above
Looking for, more and more, once again
I'm Hunting High and Low
Sometimes I may win sometimes I lose
It's just a game that I play
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
#define eps 1e-6
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

string st1,st2;
long ans;

bool check(string st,long siz)
{
 for (int i=0;i<st.size();i++)
 if (st[i]!=st[i%siz])return false;
 return true;
}

bool check1(string st1,string st2,long b)
{
     for (int i=0;i<b;i++)
     if (st1[i]!=st2[i])return false;
     return true;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
for (int divv=1;divv<=100000;++divv)
{
    if (st1.size()%divv==0&&st2.size()%divv==0)
    {
     if (check(st1,divv)&&check(st2,divv)&&check1(st1,st2,divv))++ans;
    }
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}