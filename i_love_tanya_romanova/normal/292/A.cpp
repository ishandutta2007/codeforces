

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
#define eps 1e-5
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

long long n,t[10000],c[10000],mx,timer,qtime,ps,qsize;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>t[i]>>c[i];}

mx=0;
timer=0;

ps=1;
qsize=0;
while (ps<=n)
{
      qtime=t[ps];
      qsize-=qtime-timer;
      if (qsize<0)qsize=0;
      while (t[ps]==qtime)
      {
            qsize+=c[ps];
            ++ps;
      } 
      mx=max(mx,qsize);
      timer=qtime;
     // cout<<qtime<<" "<<qsize<<endl;
}

cout<<t[n]+qsize<<" "<<mx<<endl;

cin.get();cin.get();
return 0;}