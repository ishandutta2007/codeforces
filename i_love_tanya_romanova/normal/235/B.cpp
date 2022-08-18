/*
Do you see what I see? 
Truth is an offense 
You silence for your confidence 

Do you hear what I hear? 
Doors are slamming shut 
Limit your imagination 
Keep you where they must 

Do you feel what I feel? 
Bittering distress 
Who decides what you express? 

Do you take what I take? 
Endurance is the word 
Moving back instead of forward 
Seems to me absurd 

Doesn't matter what you see 
Or into it what you read 
You can do it your own way 
If it's done just how I say 

Independence limited 
Freedom of choice is made for you, my friend 
Freedom of speech is words that they will bend 
Freedom with their exception 

Do you fear what I fear? 
Living properly 
Truths to you are lies to me 

Do you choose what I choose? 
More alternatives 
Energy derives from both the plus and negative 

Do you need what I need? 
Boundaries overthrown 
Look inside 
To each his own 

Do you trust what I trust? 
Me, myself and I 
Penetrate the smoke screen 
I see through the selfish lie 

Doesn't matter what you see 
Or into it what you read 
You can do it your own way 
If it's done just how I say 

Independence limited 
Freedom of choice is made for you, my friend 
Freedom of speech is words that they will bend 
Freedom with their exception 

Do you know what I know? 
Your money and your wealth 
You silence just to hear yourself 

Do you want what I want? 
Desire not a thing 
I hunger after independence 
Lengthen freedom's ring 

Doesn't matter what you see 
Or into it what you read 
You can do it your own way 
If it's done just how I say 

Independence limited 
Freedom of choice is made for you, my friend 
Freedom of speech is words that they will bend 
Freedom no longer frees you 

Doesn't matter what you see 
Or into it what you read 
You can do it your own way 
If it's done just how I say
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

long n;
double q,ans,dp[200000];

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
dp[0]=0;
for (int i=1;i<=n;i++)
{
    cin>>q;
    ans+=q*dp[i-1]*2+q;
    dp[i]=dp[i-1]*q+q;
}
cout.precision(8);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}