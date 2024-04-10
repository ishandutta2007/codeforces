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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
vector <long> v;
string st1,st2;
long long n,fl,s[5][1000000],ss,ans,answ,k;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>st1>>st2;
st2+=st2;

cin>>k;
n=st1.size();
for (int i=0;i<n;i++)
{
    fl=0;
    for (int j=0;j<n;j++)
    if (st1[j]!=st2[i+j])fl++;
    if (fl==0)v.push_back(i);
}

s[0][0]=1;
for (int i=0;i<k;i++)
{
    ss=0;
    for (int j=0;j<n;j++)
    s[(i+1)&1][j]=0;
    
    for (int j=0;j<n;j++)
    ss+=s[i&1][j];
    ss%=bs;
    
    for (int j=0;j<n;j++){
    s[(i+1)&1][j]+=ss-s[i&1][j]+bs;
    while (s[(i+1)&1][j]>=bs)s[(i+1)&1][j]-=bs;}
    
}

answ=0;
for (int i=0;i<v.size();i++)
answ+=s[k%2][v[i]];
cout<<answ%bs<<endl;

cin.get();cin.get();
return 0;}