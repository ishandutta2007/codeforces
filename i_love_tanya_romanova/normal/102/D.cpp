/*
Have you ever felt the need
To see more than you can see
Look into uncertainty
Reflections of treachery
Would you leave the world behind
Endless life is here to find
Can I interest you in lies
Sell your soul for all it buys

[chorus:]
Play with your insanity
Shatter your reality
Pulsing in your blood

I can satisfy your greed
For now all your debts are free
I have all eternity
To quench all the death I breed
Recreate the rules of play
From now things are done my way
None have ever won my game
Crucified them all in flames

[chorus]

Have you ever danced with the devil
His temptation ever summoned you
Ever penned your name in blood
Let possession slowly swallow you
When you stand under full moonlight
The attraction mesmerizes you
Have you ever wondered why
It seems that evil you're attracted to

Reach out to my hand
Step back in time's sand
Genetic wasteland
Far beyond death
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
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

vector<long long> v;
map<long long, long long> mapp;
long long n,m,ans[500000];
long long s[500000],t[500000];
vector<pair<long long, long long> > vv;
long long calc;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m>>n;
for (int i=0;i<n;i++)
{
 cin>>s[i]>>t[i];
 v.push_back(s[i]);
 v.push_back(t[i]);   
}
v.push_back(0);v.push_back(m);

sort(v.begin(),v.end());

mapp[v[0]]=1;
calc=1;

for(int i=1;i<v.size();i++)
{
        if (v[i]!=v[i-1]){++calc;mapp[v[i]]=calc;}
}

for (int i=0;i<n;i++)
{
 vv.push_back(make_pair(mapp[t[i]],mapp[s[i]]));   
}
sort(vv.begin(),vv.end());
ans[1]=1;
for (int i=0;i<=500000;i++)
s[i]=0;
s[1]=1;

long lc=0;
lc=1;

for (int i=0;i<vv.size();i++)
{
//    cout<<vv[i].first<<" "<<vv[i].second<<endl;
    
    for (int j=lc;j<=vv[i].first;j++)
    {
        s[j+1]=s[j]+ans[j+1];
    }
    lc=vv[i].first;
    
    ans[vv[i].first]+=s[vv[i].first-1]-s[vv[i].second-1];
    ans[vv[i].first]+=bs;
    ans[vv[i].first]%=bs;
    s[vv[i].first]=s[vv[i].first-1]+ans[vv[i].first];
    s[vv[i].first]%=bs;
}

cout<<ans[calc]<<endl;
cin.get();cin.get();
return 0;}