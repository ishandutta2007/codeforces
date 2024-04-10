/*
Let me take you down
Deeper than you know
Reality is gone
Yet so much left to show
Let me take you down
Let us look inside
There's still so much to come
It's time to say goodbye

Broken dreams
Misery replaced by constant extasy
Wide awake open wide
existance of a better kind
Waits for you waits for me
Our minds become forever free
Free of fear free of rage
The coming of the Golden Age for all

Let me take you down
Let life fade away
The ritual has begun
Your life begins today
Let me take you down
Explore the other side
Enlightened as we drown
It's time to say goodbye

Don't you turn around now
Don't you be afraid now
Just turn another page now
Celebrate the Golden Age
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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define N 4000005
using namespace std;

long pr[3000000],n;
vector<long> v;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;
for (int i=2;i<=2000000;i++)
if (pr[i]==0)
for (int j=i*2;j<=2000000;j+=i)
pr[j]=1;
for (int i=1;i<=2000000;i++)
if (pr[i]==0)
v.push_back(i);
cin>>n;
for (int i=0;i<n;i++)
{
    if (i)cout<<" ";
    cout<<v[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}