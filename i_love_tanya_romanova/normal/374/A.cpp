/*
I have a problem that I cannot explain
I have no reason, why it should have been so plain?
Have no questions but I sure have excuse
I lack the reason, why I should be so confused?

I know, how I feel when I'm around you
I don't know, how I feel when I'm around you
Around you

Left a message but it ain't a bit of use
I have some pictures, the wild might be the deuce
Today you saw, you saw me, you explained
Playing the show and running down the plane

I know, how I feel when I'm around you
I don't know, how I feel when I'm around you
I, I know, how I feel when I'm around you
I don't know, how I feel when I'm around you
Around you

I, I know, how I feel when I'm around you
I don't know, how I feel when I'm around you
I, I know, how I feel when I'm around you
I don't know, how I feel when I'm around you
Around you, around you, around you, around you
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,x,y,a,b,ans;

long solve(long tx,long ty)
{
 if (tx%a!=x%a)return 1e8;
 if (ty%b!=y%b)return 1e8;
 long dist1=abs(tx-x)/a;
 long dist2=abs(ty-y)/b;
 if (dist1%2!=dist2%2)return 1e8;
 return max(dist1,dist2);
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>x>>y>>a>>b;

if (x==1&&y==1||x==1&&y==m||x==n&&y==m||x==n&&y==1)
{
 cout<<0<<endl;
}
else if (x+a>n&&x-a<1||y+a>m&&y-b<1)
{
 cout<<"Poor Inna and pony!"<<endl;
}
else
{
 ans=solve(1,1);ans=min(ans,solve(1,m));
 ans=min(ans,solve(n,1));ans=min(ans,solve(n,m));
 if (ans>12345678){cout<<"Poor Inna and pony!"<<endl;}
 else cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}