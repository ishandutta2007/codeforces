/*
Somewhere there's a reason why things go like they do
Somewhere there's a reason why somethings just fall through
We don't always see them for what they really are
But I know there's a reason just can't see it from this far

Maybe I don't like it, but I have no choice
I know that somewhere, someone hears my voice
Maybe I don't like it, but I have no choice
I know that somewhere, someone hears my voice

I thought I knew it all
I thought I had it made
How could it end this way?
I thought I knew

Somewhere there's a reason why things don't go my way
Somewhere there's a reason that I cannot explain
Just like the change of season just may not be my turn
But I know there's a reason the lesson's mine to learn

Maybe I don't like it, but I have no choice
I know that somewhere, someone hears my voice
Maybe I don't like it, but I have no choice
I know that somewhere, someone hears my voice

I thought I knew it all
I thought I had it made
How could it end this way?
I thought I knew

I thought I knew it all
I thought I had it made
How could it end this way?
I thought I knew
I thought I knew

Thought I knew, thought I knew
Thought I knew, thought I knew
Thought I knew, thought I knew
Thought I knew, thought I knew
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
#define bsize 256

using namespace std;

string st;
vector<string> v;
long val1,val2;
vector<long> ans;

vector<string> parse(string st)
{
 vector<string> temp;
 string ts="";
 st+=":";
 for (int i=0;i<st.size();i++)
 if (st[i]==':'){temp.push_back(ts);ts="";}
 else ts+=st[i];
 return temp;              
}

long eval(char c)
{
 if (c<='9')return c-'0';
 return c-'A'+10;
}

long pars(string st,long base)
{
 long res=0;
 for (int i=0;i<st.size();i++){
     long temp=eval(st[i]);
     if (temp>=base)return -1;
     res=res*base+temp;
 }return res;
}

int main(){
//freopen("dinner.in","r",stdin);
//freopen("dinner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
v=parse(st);
for (int base=2;base<=120;base++)
{
    val1=pars(v[0],base);
    val2=pars(v[1],base);
    if (val1>=0&&val1<=23&&val2>=0&&val2<=59)
    {
     ans.push_back(base);
    }
}

if (ans.size()==0)
ans.push_back(0);

if (ans.size()>70)cout<<-1<<endl;
else {
     for (int i=0;i<ans.size();i++)
     {
         if (i)cout<<" ";
         cout<<ans[i];
     }
     cout<<endl;
     }
cin.get();cin.get();
return 0;}