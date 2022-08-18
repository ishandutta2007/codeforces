/*
Lost in a dream
Nothing is what it seems
Searching my head
For the words that you said

Tears filled my eyes
As we said our last goodbyes
This sad scene replays
Of you walking away

My body aches from mistakes
Betrayed by lust
We lied to each other so much
That in nothing we trust

Time and again,
She repeats let's be friends
I smile and say yes
Another truth bends,
I must confess

I try to let go, but I know
We'll never end 'til we're dust
We lied to each other again
But I wish I could trust

My body aches from mistakes
Betrayed by lust
We lied to each other so much
That in nothing we trust

God help me please, on my knees
Betrayed by lust
We lied to each other so much
That in nothing we trust

How could this be happening to me
I'm lying when I say "Trust me"
I can't believe this is true
Trust hurts
Why does trust equal suffering

Absolutely nothing we trust
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

double answ;
long long n,s1[300000][40];
string st1,st2;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st1;
cin>>st2;

for (long long i=1;i<=n;i++)
{
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];
    if (st2[i-1]-'A'==j)s1[i][j]+=i;}
    
    answ+=(n-i+1)*s1[i][st1[i-1]-'A'];
}

//cout<<answ<<endl;

reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());

for (long long i=1;i<=n;i++)
{
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];}
    answ+=(n-i+1)*s1[i][st1[i-1]-'A'];
    for (int j='A'-'A';j<='Z'-'A';j++){
    s1[i][j]=s1[i-1][j];
    if (st2[i-1]-'A'==j)s1[i][j]+=i;}
}
//cout<<answ<<endl;
long long znam=0;
for (long long i=1;i<=n;i++)
znam+=(n-i+1)*(n-i+1);
cout<<fixed<<answ*1.0/znam<<endl;

cin.get();cin.get();
return 0;}