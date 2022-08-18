/*
Rushing through thirty
Getting older every day... by two
Drawing pictures of innocent times
Can you add color... inside these lines?

[Chorus x2:]
I want you to lead me
Take me somewhere
Don't want to live
In a dream... one more day

Sure it would change my perspective
I'm certain I would change today
I'm certain it would change our ways
Would things fall into place?

I want you to lead me
Take me somewhere
Just don't want to live
In a dream one more day [x2]
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
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long n,k,q,s[500000];
vector<long> v;
long ans;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for(int i=1;i<=n;i++)
{
        cin>>q;v.push_back(q*(n-i+1));
}
sort(v.begin(),v.end());
for (int i=1;i<=n;i++)
s[i]=s[i-1]+v[i-1];
for (int i=1;i<=n;i++)
if (s[i]<=k)ans=i;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}