/*  
I built these wings
With broken things
Found strewn in me
My nemeses

Chaos reigns
Chaos reigns
Chaos reigns
Chaos reigns

I break and bleed
I tear, then feed
The wretchedness
Inside of me

Chaos reigns
Chaos reigns
Chaos reigns
Chaos reigns

I know where my hate truly hides
Front and center behind these
Eyes

Chaos

Reigns

It bits and holds
With fangs, so old
That loathsomeness
So bitter cold

Chaos reigns
Chaos reigns
Chaos reigns
Chaos reigns
Chaos reigns
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

string st;
vector<string> v;
vector<long> v1;
long mx,n,m,mn,ans;

long eval(string st,vector<long> v)
{
     long r=0;
     for (int i=0;i<v.size();i++)
     r=r*10+st[v[i]-1]-48;
     return r;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>st;
    v.push_back(st);
}

ans=100000099;

for (int i=1;i<=m;i++)
v1.push_back(i);
do 
{
 mx=-1000;
 mn=100000000;
 for (int j=0;j<v.size();j++)
 {
     mx=max(mx,eval(v[j],v1));
     mn=min(mn,eval(v[j],v1));
 }
 ans=min(ans,mx-mn);
}
while (next_permutation(v1.begin(),v1.end()));
cout<<ans<<endl;

cin.get();cin.get();
return 0;}