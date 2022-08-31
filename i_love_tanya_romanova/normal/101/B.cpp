/*
Modulistic terror
A vast sadistic feast
The only way to exit
Is going piece by piece

You have no choice of life or death
My face you will not see
I'll rip your flesh 'till there's no breath
Dismembered destiny

As soon as life has left your corpse
I'll make you part of me
No emotion
Death is all I see

Modulistic terror
A vast sadistic feast
The only way to exit
Is going piece by piece

Bones and blood lie on the ground
Rotten limbs lie dead
Decapitated bodies found
On my wall, your head!

On your trail I close the gap
One more life that soon won't be
No emotion
Your flesh is all I need

I'll send you to your maker
Confront the God you seek
A flash of red upon his your chest
Safety out of reach

(You have no choice of life or death
My face you will not see
I'll rip your flesh 'till there's no breath
Dismembered destiny)

(Modulistic terror
A vast sadistic feast
There's only one way out of here
Piece by piece)
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