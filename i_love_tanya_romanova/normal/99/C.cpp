/*
Your hazel-green tint eyes watching every move I make
And that feeling of doubt, it's erased
I'll never feel alone again with you by my side
You're the one and in you I confide more

And we have gone through good and bad times
But your unconditional love was always on my mind
You've been there from the start for me
And your love's always been true as can be

I give my heart to you
I give my heart 'cause nothing
Can compare in this world to you

And we have gone through good and bad times
But your unconditional love was always on my mind
You've been there from the start for me
And your love's always been true as can be

I give my heart to you
I give my heart 'cause nothing
Can compare in this world to you

I give my heart to you
I give my heart 'cause nothing
Can compare in this world to you
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
#define right adsgasgadsg

using namespace std;

string st;
string temp,bst;
set<string>v;

string rl(string st)
{
 char c=st[0];
 st[0]=st[1];
 st[1]=st[2];
 st[2]=st[3];
 st[3]=c;
 return st;
}

string ru(string st)
{
char temp=st[4];
 st[4]=st[0];
 st[0]=st[5];
 st[5]=st[2];
 st[2]=temp;
 return st;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
sort(st.begin(),st.end());
do
{
                          temp=st;
                          bst=temp;
                          for (int iter=1;iter<=2000;iter++)
                          {
                              if (rand()%2)temp=rl(temp);
                              else temp=ru(temp);
                              if (bst>temp)bst=temp;
                          }
                          v.insert(bst);
}
while (next_permutation(st.begin(),st.end()));

cout<<v.size()<<endl;

cin.get();cin.get();
return 0;}