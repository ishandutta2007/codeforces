/*
I want to reach out and touch the sky
I want to touch the sun
But I don't need to fly
I'm gonna climb up every mountain of the moon
And find the dish that ran away with the spoon.

I've crossed the ocean, turned every bend
I found the crossing near a golden rainbow's end
I've been through magic and through life's reality
I've lived a thousand years and it never bothered me

Got no religion, don't need no friends
Got all I want and I don't need to pretend
Don't try to reach me, 'cause I'd tear up your mind
I've seen the future and I've left it behind
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,q,ar[15000];
map<long, long> bad;
long fl;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>q;
    ar[i]=q;
    bad[q]=1;
}

if (bad[1]||bad[n])fl=1;
for (int i=1;i<=m;i++)
if (bad[ar[i]-1]&&bad[ar[i]+1])fl=1;
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}