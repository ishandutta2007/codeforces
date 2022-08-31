/*
There's someone in the attic
Building a strange machine
Never really seen him
But I think he works all day
Blinded by the world outside,
I stay inside
Hardly know my name
But it's getting better by time

I saw something in the mirror
Someone's watching me
If I hide in the attic
He will never get to me
I found some rope on the floor
I have to build a trap
So I start on my machine
I am never to be seen
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,m,p,ar[300000],temp;
map<long long ,long long> ex,have;
set<long long> qdif,dif;
vector<long long> ans;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>p;
for (int i=1;i<=n;i++)
cin>>ar[i];

for(int i=1;i<=m;i++)
{
 cin>>temp;
 ex[temp]++;
 dif.insert(temp);
}

for (int stp=1;stp<=p;stp++)
{
    if (stp+(m-1)*p>n)continue;
    have=ex;
    qdif=dif;
    for (int i=1;i<=m;i++)
    {
     temp=ar[stp+(i-1)*p];
     if (have[temp]==1)qdif.erase(temp);
     if (have[temp]==0)qdif.insert(temp);
     have[temp]--;
    }
    
    if (qdif.size()==0)ans.push_back(stp);
    
    for (int i=m+1;(i-1)*p+stp<=n;i++)
    {
     temp=ar[stp+(i-m-1)*p];
     if (have[temp]==0)qdif.insert(temp);
     if (have[temp]==-1)qdif.erase(temp);
     have[temp]++;
     temp=ar[stp+(i-1)*p];
     if (have[temp]==1)qdif.erase(temp);
     if (have[temp]==0)qdif.insert(temp);
     have[temp]--;
     if (qdif.size()==0)
     ans.push_back(stp+(i-m)*p);
    }
}
sort(ans.begin(),ans.end());

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}