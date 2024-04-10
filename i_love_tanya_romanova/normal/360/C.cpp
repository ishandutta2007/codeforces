/*
We were one in words
You finished my sentence
I could never attract tomorrow
It pushes me aside

I sink in waters deep
Your presence kept me floating far from depths where secrets lie
Maybe in another lifetime I can be the first you meet

I once read a poem
Held my breath but that moment's gone
First time I felt life somewhat hurts
I need an option, a reason and some hope

Yell at me, I want to be your light that shines
But my ground is shaking, and I might fall
I wish that I could say, I wish that I could be your evil in a closet

Yell at me, I want to be your light that shines
But my ground is shaking and I might fall
I wish that I could say, I wish that I could be your evil in a closet
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

long long n,k,ways[2100][2100][3];
string st;
long long shf[25000];
long long temp;

int main(){
//freopen("supper.in","r",stdin);
//freopen("supper.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
cin>>st;

// les - eq - big

ways[n+1][0][1]=1;

shf[0]=1;

for (int i=n;i;--i)
{
for (int calc=0;calc<=2000;calc++)
{
 // easy one
 ways[i][calc][0]=1ll*(st[i-1]-'a')*(ways[i+1][calc][2]+ways[i+1][calc][1]+ways[i+1][calc][0])%bs;
 // + one more
 temp=n-i+1;
 temp=calc-temp;
 if (temp>=0)
 ways[i][calc][2]=1ll*('z'-st[i-1])*(ways[i+1][temp][0]+ways[i+1][temp][1]+ways[i+1][temp][2])%bs;
 
 ways[i][calc][1]+=shf[calc];//+ways[i+1][calc][2];//ways[i+1][calc][2];
 // bsup
 ways[i][calc][1]%=bs;
 for (int q=i-1;q>=1;--q)
 {
     temp=(i-q)*(n-i+1);
     if (temp+calc>2000)break;
     ways[q][temp+calc][1]+=ways[i][calc][2];
     
 }
}
//for (int calc=0;calc<=2000;calc++)
//shf[n-i+calc+1]=(shf[n-i+calc+1]+ways[i][calc][2])%bs;
for (int calc=0;calc<=2000;calc++)
shf[calc]=(shf[calc]+ways[i][calc][0])%bs;

}
/*
for (int i=1;i<=n;i++)
cout<<ways[i][0][0]<<" "<<ways[i][0][1]<<" "<<ways[i][0][2]<<endl;

for (int i=1;i<=n;i++)
cout<<shf[i]<<"%";
cout<<endl;*/

cout<<(ways[1][k][0]+ways[1][k][1]+ways[1][k][2])%bs<<endl;

cin.get();cin.get();
return 0;}