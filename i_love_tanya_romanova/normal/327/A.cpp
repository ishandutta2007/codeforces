/*
Alice isn't it frightening?
Alice aren't you scared?
Alice isn't it wonderful
Living life afraid?

Don't look around the corner
I might be lurking there
Under the bed at night
You're up till dawn again

Alison Hell, your mind begins to fold
Alison Hell, aren't you growing cold?
Alison Hell, you are looking blue
Alison Hell, what else can you do?

I begin my rule
Life hideous in your mind
Crying out you've lost your doll
It isn't worth a dime

Alison Hell, your mind begins to fold
Alison Hell, aren't you growing cold?
Alison Hell, what are you looking for?
Alison Hell, soon I close the door

Sitting in the corner
You are naked and alone
No one listens to your fears
You've created me

Alice isn't it frightening?
Alice aren't you scared?
I was killed at birth, I shoot this final scene
You're in the basement, you're trapped insanity

Alison Hell, what were you looking for?
Alison Hell, as I close the door
Alison Hell, here you shall dwell
Alison Hell, Alice dwells in hell

Alice, Alison
Alice in hell
Goodbye
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

long n,ar[200000],ans,s;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

ans=0;
for (int i=1;i<=n;i++)
for (int j=i;j<=n;j++)
{
    s=0;
    for (int q=1;q<=n;q++)
    if (q<i||q>j)s+=ar[q];
    else s+=(1-ar[q]);
    ans=max(ans,s);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}