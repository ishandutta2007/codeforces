/*
You walk through the subway, his eyes burn a hole in your back,
A footstep behind you, he lunges prepared for attack.
Scream for mercy, he laughs as he's watching you bleed,
Killer behind you, his blood lust defies all his needs.

My innocent victims are slaughtered with wrath and despise,
The mocking religion of hatred that burns in the night.
I have no one, I'm bound to destroy all this greed,
A voice inside me compelling to satisfy me.

I can see what a life's meant to be,
And you'll never know how I came to forsee, see, see.

My faith in believing is stronger than lifelines and ties,
With the glimmer of metal my moment is ready to strike.

Death call arises, a scream breaks the still of the night,
Another tomorrow, remember to walk in the light!
I have found you, and now there is no place to run,
Excitement shakes me, oh God help me what have I done?!
Oooh yeah, I've done it!
YEEEEAAAAAAAAHHHH!

You walk through the subway, my eyes burn a hole in your back,
A footstep behind you, he lunges prepared for attack.
Scream for mercy, he laughs as he's watching you bleed,
Killer behind you, my blood lust defies all my needs.
Oooh look out, I'm coming for you!
Ahahahaha!
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

long a,b,c,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>c;

ans=a/3+b/3+c/3;
if (a>0&&b>0&&c>0)
{--a;--b;--c;
ans=max(ans,a/3+b/3+c/3+1);
}
if (a>0&&b>0&&c>0)
{--a;--b;--c;
ans=max(ans,a/3+b/3+c/3+2);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}