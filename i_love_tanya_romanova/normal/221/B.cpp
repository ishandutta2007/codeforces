/*
Deep into a dying day
I took a step outside an innocent heart
Prepare to hate me fall when I may
This night will hurt you like never before

Old loves they die hard
Old lies they die harder
I wish I had an angel
For one moment of love
I wish I had your angel
Your Virgin Mary undone
I'm in love with my lust
Burning angel wings to dust
I wish I had your angel tonight

I'm going down so frail 'n cruel
Drunken disguise changes all the rules

Old loves they die hard
Old lies they die harder

I wish I had an angel
For one moment of love
I wish I had your angel
Your Virgin Mary undone
I'm in love with my lust
Burning angel wings to dust
I wish I had your angel tonight

Greatest thrill
Not to kill
But to have the prize of the night
Hypocrite
Wannabe friend
13th disciple who betrayed me for nothing!

Last dance, first kiss
Your touch my bliss
Beauty always comes with dark thoughts

I wish I had an angel
For one moment of love
I wish I had your angel
Your Virgin Mary undone
I'm in love with my lust
Burning angel wings to dust
I wish I had your angel tonight

[x4]
I wish I had an angel...
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
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,ans,c1[100],c2[100];

void check(long a,long b)
{
     for (int i=0;i<10;i++)
     c1[i]=c2[i]=0;
     while (a){c1[a%10]++;a/=10;}
     while (b){c2[b%10]++;b/=10;}
     long fl=0;
     for (int i=0;i<10;i++)
     if (c1[i]*c2[i])fl=1;
     if (fl)++ans;
}

int main(){
//freopen("distance5.in","r",stdin);
//freopen("distance5.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i*i<=n;i++)
if (n%i==0)
{
           check(n,i);
           if (i*i!=n)check(n,n/i);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}