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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

pair<long, long> p;
map<pair<long, long> , long> mapp;
set<pair<long, long> > good;
queue<pair<long, long> >qu;
long arp[200000];
long dd,dist;
long a,b,n,c;
long x0,x1,y0,y1,start,finish;
long aa[200000],bb[200000],rr[200000];
long calc;

void tryy(long a,long b)
{
     pair<long, long> p=make_pair(a,b);
     if (good.find(p)==good.end())return;
     long ps=mapp[p];
     if (arp[ps])return;
     arp[ps]=dist+1;
     qu.push(p);
}

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x0>>y0>>x1>>y1;

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>rr[i]>>aa[i]>>bb[i];
    for (int j=aa[i];j<=bb[i];j++)
    {
     p=make_pair(rr[i],j);
     if (good.find(p)==good.end())
     {
      good.insert(p);
      calc++;
      mapp[p]=calc;                            
     } 
    }
}

for (int i=1;i<=100000;i++)
arp[i]=0;

p=make_pair(x0,y0);
start=mapp[p];
p=make_pair(x1,y1);
finish=mapp[p];

qu.push(make_pair(x0,y0));
arp[start]=1;

while (qu.size())
{
 p=qu.front();
 qu.pop();
 
 a=p.first;
 b=p.second;
 dd=mapp[p];
 dist=arp[dd];
 
 tryy(a,b-1);
 tryy(a,b+1);
 tryy(a-1,b-1);
 tryy(a-1,b);
 tryy(a-1,b+1);
 tryy(a+1,b-1);
 tryy(a+1,b);
 tryy(a+1,b+1);
      
}

cout<<arp[finish]-1<<endl;

cin.get();cin.get();
return 0;}