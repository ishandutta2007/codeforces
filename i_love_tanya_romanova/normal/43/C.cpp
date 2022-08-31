/*
Black shadow hangin' over your shoulder
Black mark up against your name
Your green eyes couldn't get any colder
There's bad poison runnin' thru your veins
Evil walks behind you
Evil sleeps beside you
Evil talks arouse you
Evil walks behind you

Black widow weavin' evil notion
Dark secret's bein' spun in your web
Good men goin' down in your ocean
They can't swim cos their tied to your bed
Evil walks behind you
Evil sleeps beside you
Evil talks arouse you
Evil walks behind you
You're just crying wolf
I sometimes wonder where you park your broom
Oh black widow

C'mon weave your web
Down in your ocean
You got 'em tied to your bed
With your dark dark secret's
And your green green eyes
You black widow

Evil, walks behind you
Evil, sleeps beside you
Evil, talks arouse you
Evil, walks behind you
Evil walks behind you
Evil sleeps beside you
Evil talks arouse you
Evil walks behind you

Evil sleeps beside you
Evil talks arouse you
Evil walks behind you
Evil walks

You're so bad
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st;
long s,n,calc[100];

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>st;
 s=0;
 for (int i=0;i<st.size();i++)
 s+=st[i];
 s%=3;
 calc[s]++;   
}

cout<<min(calc[1],calc[2])+calc[0]/2<<endl;

cin.get();cin.get();
return 0;}