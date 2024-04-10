/*
Almighty Uncreator

I am your eyes
I am your ears
I am your mouth
Let your grandest hatred echo in my deprivation

A willing bearer of your creed
To consecrate the void

My thirsting mind lies fallow
Fertile soil to all delusions
Reason in me rings hollow
Truth is dissonant in salvation's lullaby

This is a hymn of self denial
A nihilist song of praise
To humbly sacrifice my judgment
And pledge allegiance to deceit
This is a hymn of self denial
A nihilist song of praise
To abandon criticism
And give in to apathy

Mammon's missionary
A self appointed idol
Religious symbolism
Consolidates your foul belief

I beg the light of your divine resolve
Conceal my earthly weakness
I vow to liberate these lands
With your all eclipsing insight
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st,temp,temp1;
long q,cnt,ans1,ans2;

map<string, set<string> > folders,files;
map<string, set<string> > ::iterator it;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

while (cin>>st)
{
 if (st=="#")break;
 q=0;
 cnt=0;
 while (cnt<2)
 {
  ++q;
  if (st[q]=='\\')++cnt;
  if (cnt==2)break;
 }
 
 long qq=q;
 
 string temp="";
 for (int i=0;i<=q;i++)
  temp+=st[i];
 files[temp].insert(st);
 q=st.size();
 while (true)
 {
  --q;
 while (st[q]!='\\')--q;
 if (q==qq)break;
 string temp1="";
 for (int i=0;i<=q;i++)
  temp1+=st[i];
 folders[temp].insert(temp1);
 }
 
}

for (it=files.begin();it!=files.end();it++)
{
 long t=(*it).second.size();
 ans1=max(ans1,t);
}
for (it=folders.begin();it!=folders.end();++it)
{
 long t=(*it).second.size();
 ans2=max(ans2,t);
}
cout<<ans2<<" "<<ans1<<endl;

cin.get();cin.get();
return 0;}