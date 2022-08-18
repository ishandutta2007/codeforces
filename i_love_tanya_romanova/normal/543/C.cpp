/*
My prospects have become less promising
I find it hard to believe in anything
Seems I lost my world and so I lost my faith
And I can't go back to where I've been

A brand new day
It can't get worse

I have no lies or truth in what I say
There is no meaning
The words are numb and I am so afraid
There is no meaning

This is another chance or so I'm told
By these who can push themselves at any cost
They bless me with their fingers crossed
My youth is stolen, transformed and sold

Hear myself say
It can't get worse

I have no lies or truth in what I say
There is no meaning
The words are numb and I am so afraid
There is no meaning

A brand new day
It can't get worse
Hear myself say
It can't get worse

I have no lies or truth in what I say
There is no meaning
The words are numb and I am so afraid
There is no meaning
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
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,m;
string st;
char board[25][25];
int cost[25][25];
int tcost[25][25];
int dp[1<<21];
int same[25][25];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
    cin>>st;
    for (int j=0;j<m;j++)
        board[i][j]=st[j];
}

for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
        cin>>cost[i][j];

for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    {
        int mx=0;
        for (int q=0;q<n;q++)
            if (board[q][j]==board[i][j])
            {
                mx=max(mx,cost[q][j]);
                same[i][j]|=(1<<q);
                tcost[i][j]+=cost[q][j];
            }
        tcost[i][j]-=mx;
    }

for (int i=0;i<(1<<n);i++)
    dp[i]=1e9;

dp[0]=0;
for (int mask=0;mask+1<(1<<n);mask++)
{
    int q=0;
    while (mask&(1<<q))++q;
    for (int i=0;i<m;i++)
    {
        dp[mask|(1<<q)]=min(dp[mask|(1<<q)],dp[mask]+cost[q][i]);// change this
        dp[mask|same[q][i]]=min(dp[mask|same[q][i]],dp[mask]+tcost[q][i]);// change all other
    }
}

cout<<dp[(1<<n)-1]<<endl;

//cin.get();cin.get();
return 0;}