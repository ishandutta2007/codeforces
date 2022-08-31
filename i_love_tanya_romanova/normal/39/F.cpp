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
#define eps 1e-11
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

long n,m,k,calc[1000],jump[1000],t;
long bst;
vector<long> v;

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=m;i++)
{
    cin>>jump[i];
}
for (int i=1;i<=k;i++)
{
 cin>>t;
 for (int j=1;j<=m;j++)
 {
     if (t%jump[j]==0)
     calc[j]++;
 }   
}

bst=1000000;
for (int i=1;i<=m;i++)
if (calc[i]<bst)bst=calc[i];

for (int i=1;i<=m;i++)
if (calc[i]==bst)
v.push_back(i);
cout<<v.size()<<endl;
for (int i=0;i<v.size();i++)
{
    if (i)cout<<" ";
    cout<<v[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}