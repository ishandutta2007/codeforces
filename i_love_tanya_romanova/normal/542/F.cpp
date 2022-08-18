/*
Painless words don't mean a thing
Stainless world is a gift of lie
King of kings is a fallen man
No way out of here alive

Boy and girl never meet again
Life or death - which one hurts more?
Chained outside cold every night
Reaching out for a helping hand

I don't believe my faith belongs to no one
They will deceive me if only they will get a chance
Why do I hide from her? She's blinded by her God of Love
The boy and the girl savage and saint
The end of the line fortune or fate

Somewhere else before the end
Man and God lost on the way
End of time - Who will survive?
Reaching out for a single one

I don't believe my faith belongs to no one
They will deceive me if only they will get a chance
Why do I hide from her? She's blinded by her God of Love
The boy and the girl savage and saint
The end of the line fortune or fate

I don't believe my faith belongs to no one
They will deceive me if only they will get a chance
Why do I hide from her? She's blinded by her God of Love
The boy and the girl savage and saint
The end of the line fortune or fate
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define MAXN 1000

using namespace std;

long long n,t,a,b,q,T,dp[105][1005],answ,s,nhave;
vector<long long> v[10005];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>T;
for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    q=a+15;
    v[T-a].push_back(b);
}

for (int i=0;i<=100;i++)
 sort(v[i].begin(),v[i].end()),
 reverse(v[i].begin(),v[i].end());
 
 for (int i=0;i<=T;i++)
  for (int j=0;j<=n;j++)
   dp[i][j]=-1e18;
dp[0][1]=0;
for (int i=0;i<=T;i++)
 for (int have=0;have<=n;have++)
 {
    answ=max(answ,dp[i][have]);
    s=0;
    for (int add=0;add<=v[i].size()&&add<=have;add++)
    {
        nhave=(have-add)*2;
        if (nhave>n)nhave=n;
        dp[i+1][nhave]=max(dp[i+1][nhave],dp[i][have]+s);
        if (add<v[i].size())
         s+=v[i][add];
    }
        
 }

cout<<answ<<endl;

//cin.get();cin.get();
return 0;}