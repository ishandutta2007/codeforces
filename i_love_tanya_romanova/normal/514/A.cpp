/*
Hey, leech
No longer will you suck my blood
You cant keep away, you need another taste
Hey, leech
You think that you are here to stay
You cant keep away, you need another taste

Seems to me insanity
Has lived upon an alternate reality
Youre so delusional, yea
Go and feed your appetite
And gorge on the weak to relieve your lies
Youre so delusional yea

Nobodys listening, nobody cares
Nobodys listening, nobody,
Nobody cares

Your invitation, it doesnt exist
So tell me why you keep crashing the party
No invitation but you cant resist
So tell me why you keep crashing the party

Hey, leech
Youre living in a world of lies
Your life is fictional, so unpredictable
Hey, leech
Please tell me how your story ends
Your life is fictional, so unpredictable

Run motherfucker, its time to hide
You will bury yourself in a grave of lies
Youre so delusional, yea
Festering your only hope
And watch from below as the truth unfolds
Youre so delusional, yea

Nobodys listening, nobody cares
Nobodys listening, nobody,
Nobody cares

Your invitation, it doesnt exist
So tell me why you keep crashing the party
No invitation but you cant resist
So tell me why you keep crashing the party

Nobodys listening, nobody cares
Nobodys listening, cause nobody cares

Your invitation, it does not exist
So tell me why you keep crashing the party
No invitation but you cant resist
So tell me why you keep crashing the party

Your invitation, it doesnt exist
So tell me why you keep crashing the party
No invitation but you cant resist
So tell me why you keep crashing the,
Crashing the party.
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
#define MAG 10000

using namespace std;

string st;
char inv(char x)
{
 return '9'+'0'-x;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 st[i]=min(st[i],inv(st[i]));
 if (i==0&&st[i]=='0')
  st[i]='9';
}
cout<<st<<endl;

cin.get();cin.get();
return 0;}