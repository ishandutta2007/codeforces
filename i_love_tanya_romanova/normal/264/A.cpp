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

char c;
string st;
long n;
vector<long> v[10];

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
n=st.size();

for (int i=1;i<=n;i++)
{
 c=st[i-1];
 if (c=='l')v[1].push_back(i);
 else v[0].push_back(i);   
}
for (int i=0;i<v[1].size();i++)
v[0].push_back(v[1][v[1].size()-i-1]);

for (int i=0;i<v[0].size();i++)
{
 //   if (i)cout<<" ";
    cout<<v[0][i]<<endl;
    
}
cout<<endl;

cin.get();cin.get();
return 0;}