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

long ps[1000],t,n[1000],places[1000][1000],points[1000];
string st[100][100];
vector<string >v;
vector<string> un;
map<string, long> mapp;
long wins[1000];
long p;
vector<long> vv;
vector<vector<long> > sys1,sys2;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>t;
ps[1]=25;
ps[2]=18;
ps[3]=15;
ps[4]=12;
ps[5]=10;
ps[6]=8;
ps[7]=6;
ps[8]=4;
ps[9]=2;
ps[10]=1;

for (int i=1;i<=t;i++)
{
    cin>>n[i];
    for (int j=1;j<=n[i];j++)
    {
        cin>>st[i][j];
        v.push_back(st[i][j]);
    }
}

sort(v.begin(),v.end());

un.push_back(v[0]);
for (int i=1;i<v.size();i++)
if (v[i]!=v[i-1])un.push_back(v[i]);


for (int i=0;i<un.size();i++)
{
    mapp[un[i]]=i;
}

for (int i=1;i<=t;i++)
{
    wins[mapp[st[i][1]]]++;
    for (int j=1;j<=n[i];j++)
    {
        p=mapp[st[i][j]];
        places[p][j]++;
        points[p]+=ps[j];
    }
}


for (int i=0;i<un.size();i++)
{
    vv.clear();
    vv.push_back(points[i]);
    for (int j=1;j<=50;j++)
    vv.push_back(places[i][j]);
    vv.push_back(i);
    sys1.push_back(vv);    
}

for (int i=0;i<un.size();i++)
{
    vv.clear();
    vv.push_back(places[i][1]);
    vv.push_back(points[i]);
    for (int j=2;j<=50;j++)
    vv.push_back(places[i][j]);
    vv.push_back(i);
    sys2.push_back(vv);    
}

sort(sys1.begin(),sys1.end());
sort(sys2.begin(),sys2.end());

cout<<un[sys1[sys1.size()-1][51]]<<endl;
cout<<un[sys2[sys2.size()-1][51]]<<endl;

cin.get();cin.get();
return 0;}