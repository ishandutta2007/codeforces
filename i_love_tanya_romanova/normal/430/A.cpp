/*
Searching for absolution
Nailed to your cross of self redemption

Your salvation has long time past
Holding onto the curse thats your fate

Try to tear these walls down
But I will not take the fall

First in line
Cleanse your sins cast away anxieties
Today the suffering is done

Your dream is dead
The end has just begun

Try to tear these walls down
But I will not take the fall

Forget this life and what you once knew
Forget this suffering and what is eternal
Forget this life and all that you know
Forget youre sins and what is eternal

Try to tear these walls down
But I will not take the fall
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;
 
 long n,m,t,ans[20000];
 vector<pair<long, long> >  v;
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
 cin>>n>>m;
 for (int i=1;i<=n;i++)
 {
  cin>>t;
  v.push_back(make_pair(t,i));
 }
 sort(v.begin(),v.end());
 for (int i=0;i<v.size();i++)
 ans[v[i].second]=i%2;
 
 for (int i=1;i<=n;i++)
 {
 if (i-1)cout<<" ";
 cout<<ans[i];
 }
 cout<<endl;
 
cin.get();cin.get();
return 0;}