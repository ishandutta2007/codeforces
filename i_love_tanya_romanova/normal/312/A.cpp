/*
Public enemy number one
Jail break and a smoking gun
You won't believe the things I've done
And the killing is just for fun

Public enemy number one
A stolen car and I'm on the run
Through the night till the rising sun
And the trouble has just begun

Roses on your grave
I'll be on my way
There's no time to stay
With the enemies I've made

I'm invincible
You might say despicable
Punishment's reciprocal
Public enemy number one

I'm unbeatable
My mind is untreatable
Crimes unrepeatable
Public enemy number one

Public enemy number one
Watch the authorities come undone
With every stand-off that I've won
Flirting death just for fun

Public enemy number one
Born a fugitive father's son
Another heist of a bank is done
And the trouble has just begun

[Chorus]

The posters say I'm wanted "Dead or Dead"
Anyone who's tried got a bullet to the head

[Chorus]

Public Enemy [repeat 4x]
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
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long tests,fl1,fl2,n;
string st;
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
getline(cin,st);

for (;tests;--tests)
{
 getline(cin,st);
 fl1=fl2=0;
 n=st.size()-1;
 if (n>3&&st[n-4]=='l'&&st[n-3]=='a'&&st[n-2]=='l'&&st[n-1]=='a'&&st[n]=='.')
 fl1=1;
 if (n>3&&st[0]=='m'&&st[1]=='i'&&st[2]=='a'&&st[3]=='o'&&st[4]=='.')fl2=1;
 if (fl1+fl2-1)
 cout<<"OMG>.< I don't know!"<<endl;
 else if (fl1)cout<<"Freda's"<<endl;
 else cout<<"Rainbow's"<<endl;   
}

cin.get();cin.get();
return 0;}