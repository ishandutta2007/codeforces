/*
Sea full of diamonds, good morning new day
I'll fix us breakfast, and the newspaper says
The company will lay off 5000 souls today

"I wish I was a child with no worries back then", I say
"Kiss me and smile", you reply, in your way
You wake up the children for schoolfor the last time
For suddenly our beautiful life blurs away and the world breaks into pieces

'Cause today the sea came in
The wave came and stole my loved ones
I write these lines alone on the rooftop of my home
I'm adrift on the vast oceans, can you feel me?
I will not see you again, even if I live through
The day when the sea came...
Day when the sea came...
Day when the sea came in

I trace the scenes our children once played
Names carved in wood, all the words, bound to fade
I believe, my love, your memory and dreams deserve to live again tomorrow

My love
We built this world together, we lived in here together
And shared the fun together, bore the sorrows, all together

My friend
We'll win the fight together, we'll lose the game together
Greet the heroes all together, and forever, we'll remember

My world
We built this world together, we lived in here together
And shared the fun together, bore the sorrows, all together

And as long as we're together, in spirit, yet together,
You're the air that I am kissing
You will always be there
I can feel you in the wind
I can feel you in the wind...
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long sz[500],ar[500][500];
vector<long> v;
long s1,s2;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>sz[i];
    for (int j=1;j<=sz[i];j++)
    cin>>ar[i][j];
}
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=sz[i];j++)
    {
     if (j<=sz[i]/2){s1+=ar[i][j];continue;}
     if (sz[i]%2==1&&j==sz[i]/2+1){v.push_back(ar[i][j]);continue;}
     s2+=ar[i][j];
    }
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    if (i%2==0)s1+=v[i];
    else s2+=v[i];
}
cout<<s1<<" "<<s2<<endl;

cin.get();cin.get();
return 0;}