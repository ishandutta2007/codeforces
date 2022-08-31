//#pragma comment(linker, "/STACK:16777216")
//#include <fstream>
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

long pr[1200000];
long long n,q,t;
set<long long > s;

int main(){
//freopen("horse.in","r",stdin);
//freopen("horse.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

pr[1]=1;
for (int i=2;i<=1000000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000000;j+=i)
pr[j]=1;

for (int i=2;i<=1000000;i++)
if (pr[i]==0)
{q=1;
q*=i;q*=i;
s.insert(q);}

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>t;
    if (s.find(t)!=s.end())
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
cin.get();cin.get();
return 0;}