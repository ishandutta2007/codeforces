/*
Repair this soil of lost decay
The dark is the new form of light
In the end I'll find you there
Candid in the times I fight
The corpses lie in certain death
Disrespecting my...

Lost in time, spoiled mind
Reflective stones I turn
They capitalize on sacred ground
Where only crosses burn
Decapitated and mutilated
Draw power, through your head
In the end, frozen in time
Disrespecting my...

Repair this soil of lost decay
The dark is the new form of light
In the end I'll find you there
Candid in the times I fight
The corpses lie in certain death
Disrespecting my day
We've fallen to the first sacred ground
From souls that never end

On the floor
On the floor
On the floor
On the floor
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
long long q1,q2,pw[2100000],s1[2100000],n,pi[2100000],mpi,ans;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
getline(cin,st);
pw[0]=1;
for (int i=1;i<=2000000;i++)
pw[i]=pw[i-1]*17;


for (int i=1;i<=st.size();i++)
s1[i]=s1[i-1]+(st[i-1]-'a'+1)*pw[i];

n=st.size();
for (int i=1;i<n;i++)
{int j=pi[i-1];
while (j&&(st[i]!=st[j]))j=pi[j-1];
if (st[i]==st[j])++j;
pi[i]=j;
}

mpi=0;
for (int i=1;i<n-1;i++)
mpi=max(mpi,pi[i]);

//for (int i=1;i<=n;i++)cout<<s1[i]<<" ";
//cout<<endl;
for (int i=1;i<=mpi;i++)
{
    q1=s1[i];
    q2=s1[n]-s1[n-i];
   // cout<<q1<<" "<<q2<<endl;
    q1*=pw[n];
    q2*=pw[i];
    if (q1==q2)ans=i;
  //  cout<<q1<<" "<<q2<<endl;
}

if (ans)
{for (int i=0;i<ans;i++)cout<<st[i];
cout<<endl;}//cout<<ans<<endl;
else
cout<<"Just a legend"<<endl;
cin.get();cin.get();
return 0;}