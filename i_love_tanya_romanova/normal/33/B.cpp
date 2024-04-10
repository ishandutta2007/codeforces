/*
Tonight the wind comes from afar
with a distant call
Scent of valleys and fields
in early fall
There's ache in my heart
a mystery deep within the bones
She lays beside me asleep
She sometimes softly moans

Everything I do, every word I say
they're solid by the light of day
The night fills with dreams
I wish them real
There is no deeper way to feel
Oh, to feel

Does she understand
if I'm distant and feeling lost
Hiding inside one's self
is not dishonest
My fingers are not crossed
sometimes I don't feel
as good or strong
as I would like to be
I'd bring peace to her heart
if I could find some also for me

Everything I do, every word I say
they're solid by the light of day
The night fills with dreams
I wish them real
There is no deeper way to feel

Ooh...

Tonight the wind comes from afar
*/

#pragma comment(linker, "/STACK:16777216")
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

long long ar[200][200],n,cost;
string st1,st2,t1,t2;
long long bst,bp,answ;
string ast;
long long m;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<26;i++)
 for (int j=0;j<26;j++)
  ar[i][j]=1e12;

for (int i=0;i<26;i++)
 ar[i][i]=0;
 
cin>>st1>>st2;
if (st1.size()!=st2.size()){cout<<-1<<endl;return 0;}

ast=st1;
cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>t1>>t2;
 cin>>cost;
 ar[t1[0]-'a'][t2[0]-'a']=min(ar[t1[0]-'a'][t2[0]-'a'],cost);
}
for (int k=0;k<26;k++)
 for (int i=0;i<26;i++)
  for (int j=0;j<26;j++)
   ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);

answ=0;
for (int i=0;i<st1.size();i++)
{
 bst=1e13;
 bp=0;
 for (int j=0;j<26;j++)
 if (ar[st1[i]-'a'][j]+ar[st2[i]-'a'][j]<bst)
 {
  bp=j;
  bst=ar[st1[i]-'a'][j]+ar[st2[i]-'a'][j];
 }
// cout<<bst<<" "<<bp<<endl;
 answ+=bst;
 ast[i]=bp+'a';
}
if (answ>1e10)cout<<-1<<endl;
else cout<<answ<<endl<<ast<<endl;

cin.get();cin.get();
return 0;}