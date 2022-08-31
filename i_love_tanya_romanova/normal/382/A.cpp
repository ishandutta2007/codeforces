/*
Dark are the streets, gloom's creeping out of the walls
Dirt comes alive and all the neon-lights call
Demons and fools and a lady of black
She's of the kind nighttime-insomniac

She sees the prey and she's aware
The times are hard but she don't care

She's a vampire
Desire darker than black
She's a vampire
Reach higher, no turning back
Her wings are curtains of the night
She knows no wrong or right

Dead are the places where this goddess has been
Cold is the skin that this creature has seen
Her universe is an ocean of blood
Her dining table the cradle of mud

She sees the prey and she's aware
The times are hard but she don't care

She's a vampire...

The night is blind, the mistress she is calling you
To be by her side forevermore
Follow her until her thirst is sated
An immortal lie, heart blood

Can't help yourself, she's got you paralyzed

So would you kiss the sun goodbye
And give your life to never die?

She's a vampire...
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st,st1;
long s1,s2;
long fl;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='|'){fl=1;continue;}
 if (fl)s2++;else s1++;
}
cin>>st1;
for (int i=0;i<st1.size();i++)
{
 if (s1<s2){st=st1[i]+st;++s1;}
 else{st=st+st1[i];++s2;}
}
if (s1==s2)cout<<st<<endl;
else cout<<"Impossible"<<endl;

cin.get();cin.get();
return 0;}