/*
It's complete but obsolete
All tomorrow's become yesterday
In demand but second hand
It's been heard before you even play
Up to date but came too late
Better get yourself another name
You're so right but overnight
You're the one who has to take the blame
Everyone just gets on top of you
The pain begins to eat your pride
You can't believe in anything you knew
When was the last time that you cried
Don't delay you're in today
But tomorrow is another dream
Sunday's star is Monday's scar
Out of date before you're even seen
At the top so quick to flop
You're so new but rotting in decay
Like butterfly so quick to die
But you're only looking for today
Everyone just gets on top of you
The pain begins to eat your pride
You can't believe in anything you knew
When was the last time that you cried
Looking for today
Glamour trip so soon to slip
Easy come but oh how quick it goes
Ten foot tall but what to fall
Hard to open yet so easy to close
Front page news but so abused
You just want to hide yourself away
Over-paid, but soon you fade
Because you're only looking for today
Looking for today
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

using namespace std;

long long n,k,pre;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
pre=n+1;
pre/=2;
if (pre>=k)cout<<k*2-1;
else
{
    k-=pre;
    cout<<k*2<<endl;
}
cin.get();cin.get();
return 0;}