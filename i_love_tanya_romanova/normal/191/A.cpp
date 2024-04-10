//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

string st[600000];
long sz[1000000],lst[600000],bst[40],ans,n;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
getline(cin,st[0]);

for (int i=0;i<n;i++)
getline(cin,st[i]);

for (int i=0;i<n;i++)
sz[i]=st[i].size();


for (int i=0;i<n;i++)
lst[i]=st[i][st[i].size()-1]-'a';

for (int fst='a';fst<='z';++fst)
{

for (int i=0;i<=0;i++)
for (int j=0;j<=26;j++)
bst[j]=-10000000;

bst[fst-'a']=0;

for (int i=1;i<=n;i++)
{
  //  for (int j='a';j<='z';++j)
  //  {
   //     bst[i][j-'a']=bst[i-1][j-'a'];    
   // }
    
  //  cout<<bst[i-1][st[i-1][0]-'a']<<"  S   "<<st[i-1].size()<<" "<<bst[i][lst[i-1]]<<" "<<((bst[i-1][st[i-1][0]-'a']+sz[i-1])>(bst[i][lst[i-1]]))<<endl;
    
  
    if (bst[st[i-1][0]-'a']+sz[i-1]>bst[lst[i-1]])
    bst[lst[i-1]]=bst[st[i-1][0]-'a']+sz[i-1];
     
}

//cout<<fst-'a'<<" "<<bst[1]['c'-'a']<<endl;
ans=max(ans,bst[fst-'a']);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}