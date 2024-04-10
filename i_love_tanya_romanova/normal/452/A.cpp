/*
Ooh, Devon, won't go to heaven
She's just another lost soul about to be mine again
Leave her, we will receive her
And it is beyond your control, will you ever meet again

Devon, no longer living
Who had been rendered unwhole as a little child
She was taken and then forsaken
You will remember it all, let it blow your mind again

Devon lies beyond this portal
Take the word of one immortal

Give your soul to me for eternity
Release your life to begin another time with her
End your grief with me, there's another way
Release your life, take your place inside the fire with her

Sever, now and forever
You're just another lost soul about to be mine again
See her, you'll never free her
You must surrender it all and give life to me again

Fire, all you desire
As she begins to turn cold and run out of time
You will shiver till you deliver
You will remember it all, let it blow your mind again

Devon lies beyond this portal
Take the word of one immortal

Give your soul to me for eternity
Release your life to begin another time with her
End your grief with me, there's another way
Release your life, take your place inside the fire with her

Give your soul to me for eternity
Release your life to begin another time with her
End your grief with me, there's another way
Release your life, take your place inside the fire with her

Ooh, Devon, no longer living
Who had been rendered unwhole as a little child
She was taken and then forsaken
You will remember it all, let it blow your mind again
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

vector<string> z;

void add(string st)
{
 z.push_back(st);
}

long l;
string st;

bool check(string t)
{
 if (t.size()!=st.size())return false;
 for (int i=0;i<t.size();i++)
  if (t[i]!=st[i]&&st[i]!='.')return false;
  return true;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

add("vaporeon");
add("jolteon");
add("flareon");
add("espeon");
add("umbreon");
add("leafeon");
add("glaceon");
add("sylveon");

cin>>l;
cin>>st;
for (int i=0;i<z.size();i++)
 if (check(z[i]))
  cout<<z[i]<<endl;
  
cin.get();cin.get();
return 0;}