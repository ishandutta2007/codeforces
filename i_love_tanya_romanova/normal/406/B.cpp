/*
Angel - put sad wings around me now
Protect me from this world of sin
So that we can rise again

Oh angel - we can find our way somehow
Escaping from the world we're in
To a place where we began

And I know we'll find
A better place and peace of mind
Just tell me that it's all you want - for you and me
Angel won't you set me free

Angel remember how we'd chase the sun
Then reaching for the stars at night
As our lives had just begun

When I close my eyes I hear your velvet wings and cry
I'm waiting here with open arms - oh can't you see
Angel shine your light on me

Angel we'll meet once more - I'll pray
When all my sins are washed away
Hold me inside your wings and stay
Oh! angel take me far away

Put sad wings around me now
Angel take me far away
Put sad wings around me now
So that we can rise again

Put sad wings around me now
Angel take me far away
Put sad wings around me now
So that we can rise again
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,used[1200000],calc[1200000];
long p;
set<long> aset;
set<long>::iterator it;
long need;
vector<long> av;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

scanf("%d",&n);
for (int i=1;i<=n;i++)
{
 scanf("%d",&q);
 used[q]=1;
 if (q>500000)p=1000000-q+1;
 else p=q;
 calc[p]++;
 if (calc[p]==1){aset.insert(1000000-q+1);}
 if (calc[p]==2){aset.erase(q);need++;}
}

for (int i=1;i<=500000;i++)
{
 if (calc[i]==0&&need>0)
 {
  need--;
  aset.insert(i);aset.insert(1000000-i+1);
 }   
}

for (it=aset.begin();it!=aset.end();it++)
{
 av.push_back(*it);
}

cout<<av.size()<<endl;
for (int i=0;i<av.size();i++)
{
 if (i)printf(" ");
 printf("%d",av[i]);
}
cout<<endl;

cin.get();cin.get();
return 0;}