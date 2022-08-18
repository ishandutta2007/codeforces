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
 
#define  INF 100000000
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;

long long over[200000],arp[200000];
long long mplus,mminus, pot[200000],ans[200000];
vector<long long> g[200000];long long cost[200000];
long long n,a,b;
long long needplus[200000],needminus[200000];


void dfs(long long v)
{
     arp[v]=1;
     
     vector<long long> sons;
     for (int i=0;i<g[v].size();i++)
     {
         long long t=g[v][i];
         if (arp[t])continue;
         sons.push_back(t);
         dfs(t);
     }
     
     mplus=0;
     mminus=0;
     
     for (int q=0;q<sons.size();q++)
     {
         long i=sons[q];
         
         mminus=max(mminus,needminus[i]);
     mplus=max(mplus,needplus[i]);   
     }
     
    
  //   cost[v]+=mplus;
   //  cost[v]-=mminus; pot[v]=-cost[v];
    // ans[v]=abs(pot[v]);
     
     cost[v]-=mminus;
     cost[v]+=mplus;
     needminus[v]=mminus;
     needplus[v]=mplus;
     
     if (cost[v]<0){needplus[v]+=abs(cost[v]);}else needminus[v]+=abs(cost[v]);
     
    // cout<<v<<" "<<needplus[v]<<" "<<needminus[v]<<endl;
     }

int main(){
//freopen("olympia.in","r",stdin);
//freopen("olympia.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);   
}

for(int i=1;i<=n;i++)
cin>>cost[i];

dfs(1);

cout<<needplus[1]+needminus[1]<<endl;

cin.get();cin.get();
return 0;}