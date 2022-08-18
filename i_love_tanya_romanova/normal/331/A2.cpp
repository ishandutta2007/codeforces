/* 

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
#define eps 0.001
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

long long n,ar[500000],temp,t,s[500000];
map<long long, long long> calc,fst,lst;
long long aclr,bst;
vector<long long> ans;
long long start,finish;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];
 calc[ar[i]]++;
 if (calc[ar[i]]==1)fst[ar[i]]=i;
 lst[ar[i]]=i;
}

aclr=-1;
bst=-10000000000000000ll;

for (int i=1;i<=n;i++)
{
 s[i]=s[i-1];
 if (ar[i]>0)s[i]+=ar[i];
}

for (int i=1;i<=n;i++)
{
    temp=ar[i];
    if (calc[temp]>1)
    {
     t=2*temp;
     t+=s[lst[temp]-1]-s[fst[temp]];
     if (t>bst){bst=t;aclr=temp;}
    }
}

//cout<<aclr<<" "<<bst<<endl;
start=fst[aclr];
finish=lst[aclr];
for (int i=1;i<=n;i++){
    if (i<start||i>finish)ans.push_back(i);
    else 
if (i>start&&i<finish&&ar[i]<0)
ans.push_back(i);}

cout<<bst<<" "<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}