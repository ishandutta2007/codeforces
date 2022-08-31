/*
Covered in sinners and dripping with gilt
Making you money from slime and from filth
Parading your bellies in ivory towers
Investing our lives in your schemes and your powers

You got to watch them - Be quick or be dead
Snake eyes in heaven - The thief's in your head
You've got to watch them - Be quick or be dead
Snake eyes in heaven - The thief's in your head....

Be quick!
Or be dead!
Be quick!
Or be dead

See... what's ruling all our lives
See... who pulling the strings...
I bet you won't fall on your face
Your belly will hold you in place

The serpent is crawling inside of your ear
He says must vote for what you want to hear
Don't matter what's wrong as long as you're alright
So pull yourself stupid and rob yourself blind.

You got to watch them - Be quick or be dead
Snake eyes in heaven - The thief's in your head
You've got to watch them - Be quick or be dead
Snake eyes in heaven - The thief's in your head....

Be quick!
Or be dead!
Be quick!
Or be dead!
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

long n,l[200000],r[200000],ans,ar[200000];

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int i=1;i<=n;i++)
l[i]=l[i-1]+(ar[i]>=0);
for (int i=n;i>=1;i--)
r[i]=r[i+1]+(ar[i]<=0);
r[0]=r[1];

ans=n;
for (int i=1;i<n;i++)
ans=min(ans,l[i]+r[i+1]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}