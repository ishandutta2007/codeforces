/*
I was born in the dirt
I never had no home
And the places I've lived
You don't wanna know
But if you wanna hear evil
Just come a little bit close

I was a snake-eyed boy
And at the age of five
I made love to the howl of the wolves
With a dark haired girl
So if you wanna hear evil
Come a little bit close

She whispered in my ear
Little boy you the one
Set the world to rights
Make it tremble in fear
Do it one more time
'Cause you the one, you're the one

You're the one, you're the one
You're the one, you're the one
Yea, you're the one
Little boy, you're the one
Do it one more time

She said the path you walk
Gonn' be hard one to tread
'Cause the night is your only love
Lots of girls gonn' be hurt
Said it's part of your fate
'Cause you're the one, you're the one

And now I know my place
In this life I ride
And I know the things I feel
A burning deep inside
So if you want to meet evil
I'm the one, I'm the one

I'm the one, I'm the one
I'm the one, I'm the one
Yea, I'm the one
I'm the one, I'm the one
Do it one more time
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
#define eps 1e-6
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

long long c[200][200],dp[200][200],num[200],answ,n;

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<10;i++)
cin>>num[i];

c[0][0]=1;

for (int i=0;i<=100;i++)
for (int j=0;j<=i;j++)
if (j==0)c[i][j]=1;
else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

for (int i=0;i<=n;i++)
{
 if (i<num[9])dp[i][9]=0; else dp[i][9]=1;
 
 for (int q=9;q>=1;q--)
 for (int j=num[q];j<=i;j++)
 dp[i][q]+=dp[i-j][q+1]*c[i][j]%bs;
 
 for (int j=num[0];j<=i;j++)
 dp[i][0]+=dp[i-j][1]*c[i-1][j]%bs;
 
 for (int j=0;j<=9;j++)
 dp[i][j]%=bs;   
}

//cout<<dp[1][7]<<endl;

answ=0;
for (int i=1;i<=n;i++)
answ+=dp[i][0]%bs;
cout<<answ%bs<<endl;

cin.get();cin.get();
return 0;}