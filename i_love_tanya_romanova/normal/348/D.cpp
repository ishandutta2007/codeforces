/*
You and me 
We used to be together 
Everyday together always 
I really feel 
That I'm losing my best friend 
I can't believe 
This could be the end 
It looks as though you're letting go 
And if it's real 
Well I don't want to know 

Don't speak 
I know just what you're saying 
So please stop explaining 
Don't tell me cause it hurts 
Don't speak 
I know what you're thinking 
I don't need your reasons 
Don't tell me cause it hurts 

Our memories 
Well, they can be inviting 
But some are altogether 
Mighty frightening 
As we die, both you and I 
With my head in my hands 
I sit and cry 

Don't speak 
I know just what you're saying 
So please stop explaining 
Don't tell me cause it hurts (no, no, no) 
Don't speak 
I know what you're thinking 
I don't need your reasons 
Don't tell me cause it hurts 

It's all ending 
I gotta stop pretending who we are... 
You and me I can see us dying...are we? 

Don't speak 
I know just what you're saying 
So please stop explaining 
Don't tell me cause it hurts (no, no, no) 
Don't speak 
I know what you're thinking 
I don't need your reasons 
Don't tell me cause it hurts 
Don't tell me cause it hurts! 
I know what you're saying 
So please stop explaining 

Don't speak, 
Don't speak, 
Don't speak, 
Oh I know what you're thinking 
And I don't need your reasons 
I know you're good, 
I know you're good, 
I know you're real good 
Oh, la la la la la la La la la la la la 
Don't, Don't, uh-huh Hush, hush darlin' 
Hush, hush darlin' Hush, hush 
Don't tell me tell me cause it hurts 
Hush, hush darlin' Hush, hush darlin' 
Hush, hush don't tell me tell me cause it hurts 
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

long long n,m;
char z[3005][3005];
long long A,B,C,D;
long long res;
long dp[3005][3005];

long long solve(long x1,long y1,long x2,long y2)
{
     for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
     dp[i][j]=0;
     dp[x1][y1]=1;
     for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
     {
         dp[i][j]+=dp[i-1][j]+dp[i][j-1];
         dp[i][j]%=bs;
         if (z[i][j]=='#')dp[i][j]=0;
     }
     return dp[x2][y2];
}

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
    {
        cin>>z[i][j];
    }
}

A=solve(1,2,n-1,m);// gtop
B=solve(2,1,n,m-1);// gbot
C=solve(1,2,n,m-1);//overQ
D=solve(2,1,n-1,m);//overP
//cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
res=A*B%bs-C*D%bs;
while (res<0)res+=bs;
while (res>=bs)res-=bs;
cout<<res<<endl;

cin.get();cin.get();
return 0;}