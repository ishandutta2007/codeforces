//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long long n,q,fl;
vector<long> v;
set<long> s; 
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<50000;i++)
{
    q=i;
    q*=(i+1);q/=2;
    s.insert(q);
    v.push_back(q);
}

for (int i=0;i<v.size();i++)
{
     if (v[i]>0&&v[i]<n&&s.find(n-v[i])!=s.end())
     fl=1;
}
if (fl)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}