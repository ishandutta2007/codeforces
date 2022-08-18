/*
Ah
Yeah

Die, die, die my darling
Don't utter a single word
Die, die, die my darling
Just shut your pretty eyes
I'll be seeing you again
Yeah, I'll be seeing you, in hell

So don't cry to me oh baby
Your future's in an oblong box
Don't cry to me oh baby
You should have seen it a-coming on
Don't cry to me oh baby
Had to know it was in your card
Don't cry to me oh baby
Dead-end soul for a dead-end girl
Don't cry to me oh baby
And now your life drains on the floor
Don't cry to me oh baby

Die, die, die my darling
Don't utter a single word
Die, die, die my darling
Just shut your pretty mouth
I'll be seeing you again, yeah-yeah
I'll be seeing you, in hell

Don't cry to me oh baby
Your future's in an oblong box
Don't cry to me oh baby
You should have seen it a-coming on
Don't cry to me oh baby
Had to know it was in your card
Don't cry to me oh baby
Dead-end soul for a dead-end girl
Don't cry to me oh baby
And now your life drains on the floor
Don't cry to me oh baby

Die, die, die my darling
Don't utter a single word
Die, die, die my darling
Shut your pretty mouth
I'll be seeing you again
I'll be seeing you, in hell
Die-die-die
Die-die-die
Die-die-die

Die
*/

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

string st1,st2;
long long n,orm,ans[200000][5];

bool fit(long a,long ps,long c)
{
     char temp;
     if (a==1)temp=st1[ps]; else temp=st2[ps];
     if (temp==c+48)return true;
     if (temp=='?')return true;
     return false;
}

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st1>>st2;
ans[0][0]=1;

for (int i=0;i<n;i++)
{
    for (int a=0;a<10;a++)
    for (int b=0;b<10;b++)
    if (fit(1,i,a)&&fit(2,i,b))
    {
     if (a<b)orm=2; else if (a>b)orm=1; else orm=0;
     for (int mask=0;mask<4;mask++)
     ans[i+1][mask|orm]=(ans[i+1][mask|orm]+ans[i][mask])%bs;
    }
}

cout<<ans[n][3]<<endl;

cin.get();cin.get();
return 0;}