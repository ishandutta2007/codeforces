/*
This is the age of dehumanization
Perverted creation
Damned, misled children
You never stood a chance
Resurrecting a dead messiah
For a paralysed race
Damned, misled children
You never stood a chance

Infected
Neglected
The new breed of a generation to come
Rejected
Ill-fated
The new breed - a generation to kill

Sowing the seed of suffering
Upon these fertile hearts
Damned, misled children
You never stood a chance
Chosen to be slaughtered
By the masters of manipulation
Dmaned, misled children
You never stood a chance

Infected
Neglected
The new breed
Of a generation to come
Rejected
Ill-fated
The new breed
Parasites
A generation to kill
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256
#define nice dhhssgsggsgsgs

using namespace std;

long er,ans[200000],n,a,b;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=0;i<=100000;i++)
ans[i]=-1;
er=0;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 if (ans[b]<a-1)er=1;
 ans[b]=max(ans[b],a);
}
if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}