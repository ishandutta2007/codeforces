/*  
Beneath the streets,
A common man is caged,
Tormented and mortified.

Subjected to intense hurt and mental shock,
Horrified by a brutality
He can't understand.

Tortured
Suffering to confess
The crime
Not match their impress

Colors of Hate

Aggression based on skin coler.
Disgusted to realize racial intolerance.
Discrimination is a tool of the machine.

Oppression
A scar that never heal
Racism
A brand ripped in flesh

Colors of Hate

Prejudice is the gun that guarantee
That we (already) live in a divided society
All the pain, all misery, has a history
And the past and its hate can't be erased

Colors of Hate
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

struct ordd{long a,b,ind;};
ordd ord[200000];
long res[200000],sres[200000],has;
long n,p,k,declim;
vector<long> ans; 
bool forsec(ordd a,ordd b)
{
 if (a.b!=b.b)return a.b<b.b;
 if (a.a!=b.a)return a.a>b.a;
 return a.ind<b.ind;
}

bool forstud(ordd a,ordd b)
{
 if (a.a!=b.a)return a.a>b.a;
 if (a.b!=b.b)return a.b>b.b;
 return a.ind<b.ind;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>p>>k;

for (int i=0;i<n;i++)
{
    cin>>ord[i].a>>ord[i].b;
    ord[i].ind=i;
}

sort(ord,ord+n,forsec);

for (int i=0;i<p-k;i++)
res[ord[i].ind]=1;

sort(ord,ord+n,forstud);

declim=1000000000;

for (int i=0;i<n;i++)
{
 if (has<k&&res[ord[i].ind]==0)
 {
  sres[ord[i].ind]=1;++has;declim=min(declim,ord[i].b);
 }
}

//cout<<declim<<endl;

sort(ord,ord+n,forsec);
reverse(ord,ord+n);

for (int i=0;i<n;i++)
{
    if (has<p&&(res[ord[i].ind]==0||sres[ord[i].ind]==0)&&
    ord[i].b<declim)
    {
     sres[ord[i].ind]=1;++has;
    }
}

/*for (int i=0;i<n;i++)
cout<<ord[i].ind<<"#";
cout<<endl;
*/
for (int i=0;i<n;i++)
{
    long q=ord[i].ind;if (has<p&&res[q]==1)
    {++has;ans.push_back(q);}
    if (sres[q]==1)ans.push_back(q);
}
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i]+1;
}
cout<<endl;

cin.get();cin.get();
return 0;}