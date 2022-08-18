/*
From all lives beginning on 
we are pushed in little forms
no one asks us how we like to be
In school they teach us what to think
but everyone says different things
but they're all convinced that 
they're the ones to see

So they keep talking and they never stop
and at certains point you give it up
so the only thing that's left to think is this

I want out... To live my life alone
I want out... Leave me be
I want out... To do things on my own
I want out... To live my life and to be free

People tell me A and B
they tell me how I have to see
Things that I have seen already clear
so they push me then from side to side
they're pushing me from black to white
they're pushing'til there's nothing more to hear

But don't push me to the maximum
shut your mouth and take it home
'cause I decide the way things gonna be

I want out... To live my life alone
I want out... Leave me be
I want out... To do things on my own
I want out... To live my life and to be free

there's a million ways to see the things in life
a million ways to be the fool
in the end of it, none of us is right
sometimes we need to be alone

I want out... To live my life alone
I want out... Leave me be
I want out... To do things on my own
I want out... To live my life and to be free
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st;
long calc,fr;
set<char> dif;
long long ans,n;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
ans=1;
for (int i=0;i<st.size();i++)
{
    if (st[i]=='?')if (i==0)ans*=9;
    else ++calc;
    if (st[i]>='A'&&st[i]<='Z')dif.insert(st[i]);
}

fr=10;
/*
if (st.size()==1&&st[0]>'9')
cout<<10<<endl;
else{*/

if (st[0]>='A'&&st[0]<='Z'){dif.erase(st[0]);--fr;ans*=9;}

n=dif.size();
//cout<<fr<<" "<<ans<<endl;

for (int i=1;i<=n;i++)
{
    ans*=fr;--fr;
}
if (ans==0)
cout<<0<<endl;
else
{
    cout<<ans;
    for (int i=0;i<calc;i++)
    cout<<0;
    cout<<endl;
}


cin.get();cin.get();
return 0;}