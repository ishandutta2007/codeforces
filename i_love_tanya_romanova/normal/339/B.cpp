/*
"Feel no regrets, 'cause I am death
Feel no regrets."

"I wanna know where do we go
Where do you take me now
There is no choice, my inner voice
Tells not to fear somehow

It's hard for me to let it be
I cannot understand
I'm still so young, I don't belong
To those who meet their end."

"You always thought your first man would marry you
Now, as it seems, he just comes to burry you
I am this man and I'm gonna be your last
Give me your hand, your life belongs to the past

'Cause I am death
Feel no regrets."

"It's so unfair, 'cause everywhere
I see the blossom grow
While others try to end their lifes
I want it, heaven knows."

"You always thought your first man would marry you
Now, as it seems, he just comes to burry you
I am this man and I'm gonna be your last
Give me your hand, your life belongs to the past

'Cause I am death
Feel no regrets."

Feel no regrets, my friend, I will speak to those who listen
See, I am heaven sent, you will find what you've been missing
Feel no regrets, my friend, noone ever knows the reasons
Why and when it will end. Every life is just a season
Feel no regrets, 'cause I am death
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
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long n,m,ar[200000],ans,qpos;
long long gdist(long long a,long long b)
{
     if (b<a)return n-a+b;
     return b-a;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
qpos=1;
for (int i=1;i<=m;i++)
{
    cin>>ar[i];
    ans+=gdist(qpos,ar[i]);
    qpos=ar[i];
//    cout<<ans<<endl;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}