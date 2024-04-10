/*
I'm the great Leviathan, insatiable colossus
Titanic engulfer of lives, I reward you, absorb you
I'm the monstrous mouth that hungers for your awe
Immense construction of lies. I own you, disown you

I am life. I'm death. You empower me

I'm a mammoth king evoked, conjured by your dreams
Summoned by your fears. You need me, you feed me
I'm the imposing giant. Infallible dictator
My rules apply to all. You'll heed me, bleed for me

I am life. I'm death. I decide your fate
You empower me. You'd even kill for me

Guzzling down your dreams - the tears of unheard pleas I drink,
Imbibe with such delight the fear that floods your temporal shell
Raging red rivers and streams - the kingdom of my shadow
Where dread of man in endless night revives my every cell

To those who doubt - your wounds will never heal
To those who question my creation - I'm not real

I am pain. I am grief. I'm the things you fear
I'm the lie whispered into your ear
I'm the great Leviathan. I'm dominance and greed
You imagined me, so I was conceived

I am life. I'm death. You belong to me
Call me what I am. I am colossus
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

long m,x,y,s[2000];
vector<long> ans;

bool ok(long a)
{
     if (a<x)return false;
     if (a>y)return false;
     return true;
}

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m;
for (int i=1;i<=m;i++)
{cin>>s[i];s[i]+=s[i-1];}
cin>>x>>y;

for (int i=0;i<=m;i++)
if (ok(s[i])&&ok(s[m]-s[i]))
ans.push_back(i+1);
if(ans.size()==0)ans.push_back(0);
cout<<ans[0]<<endl;

cin.get();cin.get();
return 0;}