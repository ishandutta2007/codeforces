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

long n,k,t,ar[200000];

set<long> has,usd;
long ans;

int main(){
//freopen("olympia.in","r",stdin);
//freopen("olympia.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


cin>>n>>k;

for (int i=0;i<n;i++)
{cin>>ar[i];
 has.insert(ar[i]);
}

sort(ar,ar+n);

for (int i=0;i<n;i++)
{
    if (ar[i]%k)
   { ++ans;usd.insert(ar[i]);}
    else
    {
        t=ar[i]/k;
        if (usd.find(t)==usd.end())
        {
                                   usd.insert(ar[i]);
                                   ++ans;
        }
    }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}