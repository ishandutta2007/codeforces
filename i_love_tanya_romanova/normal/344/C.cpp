/*
Metal thrashing mad
Oh yeah

Racing down the road
In a street machine of steel
Gears are jammed in full
I'm a madman at the wheel

Got my foot pinned to the floor
You can feel the engines roar
Got thunder in my hands
I'm metal thrashing mad, yeah
I'm metal thrashing mad, yeah

Driving like a maniac
Can't go any faster
Burning up the road
And heading for disaster

Got my foot pinned to the floor
You can feel the engines roar
Got thunder in my hands
I'm metal thrashing mad, yeah yeah

Ooh yeah, oh
Racing down the road
In a street machine of steel
Gears are jammed in full
I'm a madman at the wheel

Got my foot pinned to the floor
You can feel the engines roar
Got thunder in my hands
I'm metal thrashing mad

Got my foot pinned to the floor
You can feel the engines roar
Got thunder in my hands
I'm metal thrashing mad, oh
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long a,b;
//long dist[1000][1000];

long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

long long solve(long long a,long long b)
{
 if (a==0)return 0;
 if (a<b)swap(a,b);
 return a/b+solve(a%b,b);    
}
/*
void dfs(long a,long b)
{
     if (a>100||b>100)return;
     
     for (int q=1;q<=20;q++)
     for (int w=1;w<=20;w++)
     {
         if (dist[q][w]>1000)continue;
         long t1,t2,zn;
         zn=w*b;
         t1=a*w;
         t2=q*b;
         t1+=t2;
         long p=gcd(t1,zn);
         t1/=p;zn/=p;
         if (t1<=100&&zn<=100&&dist[t1][zn]>dist[q][w]+dist[a][b])
         {
          dist[t1][zn]=dist[q][w]+dist[a][b];
          dfs(t1,zn);
         }
         zn=q*a;
         t1=b*q;
         t2=w*a;
         t1+=t2;
         swap(t1,zn);
         p=gcd(t1,zn);
         t1/=p;zn/=p;
         if (t1<=100&&zn<=100&&dist[t1][zn]>dist[q][w]+dist[a][b])
         {
          dist[t1][zn]=dist[q][w]+dist[a][b];
          dfs(t1,zn);
         }
     }
     
}
*/

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
for (int i=1;i<=20;i++)
for (int j=1;j<=20;j++)
dist[i][j]=100000;

dist[1][1]=1;
dfs(1,1);

for (int i=1;i<=20;i++)
{
    for (int j=1;j<=20;j++)
    if (dist[i][j]<10000)
    cout<<i<<" "<<j<<" "<<dist[i][j]<<" "<<solve(i,j)<<endl;
    //cout<<dist[i][j]<<" ";
    //cout<<endl;
}
*/
cin>>a>>b;
cout<<solve(a,b)<<endl;

cin.get();cin.get();
return 0;}