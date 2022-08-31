/*
Autumn - the time of darkness and decay
Life's running shorter day by day

Winter - has gripped the land in cold caress
He's all alone and deeply depressed, she's dead

Don't you fear the winter, I will keep you safe
And warm
Don't you fear the winter, nothing's gonna
Do you harm

Midnight - and on the graveyard a storm is RAGEing
The clods of earth hide his whole life

Homeless - who's lonely now will be for long
The wind will drift him on and on, like the leaves

Don't you fear the winter, I will keep you safe
And warm
Don't you fear the winter, come with me,
There'll be no harm

A silent might that has moved you
Hear your waters stand still
Striding down to the elder
Soon you'll meet her again

Autumn - who's got the time knows nothing yet
Who cares? But watchful are the Dead

Midnight - It's hard to face and deeply sad
But you're asleep so don't look back, you're dead

Don't you fear the winter, I will keep you safe
And warm
Don't you fear the winter, nothing's gonna
Do you harm
Don't you fear the winter, I will keep you safe
And warm
Don't you fear the winter, come with me,
There'll be no harm
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
string st;
vector<long> v;
long r;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
st+='+';
for (int i=0;i<st.size();i++)
{
    if (st[i]=='+'){v.push_back(r);r=0;}
    else r=r*10+st[i]-48;
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    if (i)cout<<"+";cout<<v[i];
}
cout<<endl;
cin.get();cin.get();
return 0;}