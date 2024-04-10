/*
Walls made of blood and gold
Starting to unfold ancient tales left untold
Amber colored eyes slowing hypnotize
Lead them to their sacrifice
Sail from the land of old, holding on to hope
Conquering a new world made of gold

Dreaming and searching
Finding and claiming
Blood and gold

Stars tell the prophecy of what is to be
Descending from the towers of the sea
As they realize the fate of their demise
The end of a mighty empire
Now, greed has come to claim
Falling eagles reign
Only ruins now remain

Dreaming and searching
Finding and claiming
Blood and gold
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
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

long n,m;
string st;
vector<vector<char> > V;
vector<vector<char> > x2(vector<vector<char > > v)
{
 vector<vector<char> > res;
 for (int i=0;i<v.size();i++)
 {
  vector<char> vv;
  for (int j=0;j<v[i].size();j++)
  {
      vv.push_back(v[i][j]);
      vv.push_back(v[i][j]);
  }
  res.push_back(vv);
  res.push_back(vv);
 }
 return res;
}

vector<vector<char> > mirror(vector<vector<char > > v)
{
 for (int i=0;i<v.size();i++)
  reverse(v[i].begin(),v[i].end());
  return v;
}

vector< vector< char> > rotate(vector<vector< char > > v)
{
 vector<vector<char> > res;
 for (int i=0;i<v[0].size();i++)
 {
  vector<char> vv;
  for (int j=v.size()-1;j+1;--j)
   vv.push_back(v[j][i]);
  res.push_back(vv);
 }
 return res;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
for (int i=0;i<n;i++)
{
 vector<char> v;
 cin>>st;
 for (int j=0;j<m;j++)
 {
  v.push_back(st[j]);
 }
 V.push_back(v);
}

V=rotate(V);
V=mirror(V);
V=x2(V);
for (int i=0;i<V.size();i++)
{
 for (int j=0;j<V[i].size();j++)
  cout<<V[i][j];
 cout<<endl;
}

cin.get();cin.get();
return 0;}