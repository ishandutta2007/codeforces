/*
Time goes by
But you can't rest
Too many things
And you're obsessed
Trying to find
Some sense to it all

No-one knows what you've been through
Like no-one cares
But it's not true
Turn the page
And make a fresh start

When you are low
You should know
You are not the only lonely soul
And you will find
The strength inside
There is no more need to hide

Just carry on
Fullfill your dreams
Don't let them try to pull you down
So carry on
Don't give up
March on till the end
The road is long but you'll reach the final bend
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
 
#define  INF 100000000
#define eps 1e-11
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

string st;
long mu;
vector<char>v;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;

mu=-1;
for (int q='z';q>='a';--q)
for (int i=0;i<st.size();i++)
if (st[i]==q&&i>mu){mu=i;v.push_back(q);}
for (int i=0;i<v.size();i++)
cout<<v[i];
cout<<endl;
cin.get();cin.get();
return 0;}