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

long n,m;
string st;
long s[100][100],ts,ar[100][100];
long ans;

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=st.size();j++)
    ar[i][j]=(st[j-1]=='1');
    
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
s[i][j]=s[i-1][j]+s[i][j-1]-
s[i-1][j-1]+ar[i][j];

/*
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    {cout<<s[i][j]<<" ";}
    cout<<endl;
}
*/
for (int li=1;li<=n;li++)
for (int lj=1;lj<=m;++lj)
{
    for (int ri=li;ri<=n;ri++)
    for (int rj=lj;rj<=m;rj++)
    {
        ts=s[ri][rj]-s[li-1][rj]-s[ri][lj-1]
        +s[li-1][lj-1];
        if (ts==0)
        {
                  ans=max(ans,ans-ans+(ri-li+rj
                  -lj+2)*2);
        }
    /*    if (li==2&&lj==1&&ri==n&&rj==m)
        cout<<ts<<" @"<<" "<<s[ri][rj]<<" "<<
        s[li-1][rj]<<" "<<s[ri][lj-1]<<" "<<
        s[li-1][lj-1]<<endl;
      */  
    }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}