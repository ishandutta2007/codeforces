/*
Spineless from the start, sucked into the part
Circus comes to town, you play the lead clown
Please, please
Spreading his disease, living by his story
Knees, knees
Falling to your knees, suffer for his glory
You will

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Marvel at his tricks, need your Sunday fix
Blind devotion came, rotting your brain
Chain, chain
Join the endless chain
Taken by his glamour
Fame, Fame
Infection is the game, stinking drunk with power
We see

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Bow to Leper Messiah
Witchery, weakening
Sees the sheep are gathering
Set the trap, hypnotize
Now you follow

Time for lust, time for lie
Time to kiss your life goodbye
Send me money, send me green
Heaven you will meet
Make a contribution
And you'll get a better seat
Bow to Leper Messiah

Lie.
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

long d[2000000],a,b,c,ans;

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=1000000;i++)
{
    for (int j=i;j<=1000000;j+=i)
    d[j]++;
}

cin>>a>>b>>c;
for (int i=1;i<=a;i++)
for (int j=1;j<=b;j++)
for (int q=1;q<=c;q++)
{
    ans=(ans+d[i*j*q])%(1<<30);
    }

cout<<ans<<endl;
cin.get();cin.get();
return 0;}