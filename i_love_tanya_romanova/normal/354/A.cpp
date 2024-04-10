/*
After all wars
We lie, as shelter falls
The world is but hell
A place darkened out by time
Submit to the fall

Live in peace for years
Turn back the hands of time

Light shines before
As lives are torn
Morals slow decline
We'll live in cold fear
Until we lay dead
Silent our pleas
Search for the end
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,l,r,ql,qr,ans,w[200000],sw[200000],tans,s1,s2;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>l>>r>>ql>>qr;
for (int i=1;i<=n;i++)
cin>>w[i];

for (int i=1;i<=n;i++)
{
    sw[i]=sw[i-1]+w[i];
}

ans=sw[n]*l+(n-1)*ql;
ans=min(ans,sw[n]*r+(n-1)*qr);

for (int cp=1;cp<n;cp++)
{
    // st l
    s1=cp;
    s2=n-cp;
    tans=sw[cp]*l+(sw[n]-sw[cp])*r;
    if (s1>s2)tans+=(s1-s2-1)*ql;
    if (s1<s2)tans+=(s2-s1)*qr;
    ans=min(ans,tans);
    //st r
    tans=sw[cp]*l+(sw[n]-sw[cp])*r;
    swap(s1,s2);
    if (s1>s2)tans+=(s1-s2-1)*qr;
    if (s1<s2)tans+=(s2-s1)*ql;
    ans=min(ans,tans);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}