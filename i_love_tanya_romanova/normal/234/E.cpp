/*
Pay to kill, die to lose, hunted, hunter which are you
Diablo come again to make trophies out of men
Lose your skin, lose your skull, one by one the sack is full
In the heat dehydrate, know which breath will be your last

Nowhere to run, nowhere to hide, you've got to kill to stay alive
Nowhere to run, nowhere to hide, you've got to kill to stay alive

Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain

Human heart, human mind, intellect intertwined
Focus sharp in the night, watch the jungle burning bright
Toe to toe throw the line, everyone's caught hand tied
Iron will iron fist, how could it have come to this?

Nowhere to run, nowhere to hide, you've got to kill to stay alive
Nowhere to run, nowhere to hide, you've got to kill to stay alive

Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain

Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain
Show them no fear, show them no pain
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

long long n,x,a,b,c,t;
string st;
vector<pair<long, string> > v,kor1,kor2,kor3,kor4;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>x>>a>>b>>c;

for (int i=1;i<=n;i++)
{
 cin>>st>>t;
 v.push_back(make_pair(t,st));    
}

sort(v.begin(),v.end());

long nn=v.size()/4;
for (int iter=1;iter<=nn;iter++)
{
    n=v.size()/4;
    kor1.clear();
    kor2.clear();
    kor3.clear();
    kor4.clear();
    reverse(v.begin(),v.end());
    cout<<"Group "<<char('A'+iter-1)<<":"<<endl;
    
    for (int i=0;i<n;i++)
    kor1.push_back(v[i]);
    for (int i=n;i<n*2;i++)
    kor2.push_back(v[i]);
    for (int i=n*2;i<n*3;i++)
    kor3.push_back(v[i]);
    for (int i=n*3;i<n*4;i++)
    kor4.push_back(v[i]);
    v.clear();
    
    x=x*a+b;
    x%=c;
    cout<<kor1[x%n].second<<endl;
    kor1.erase(kor1.begin()+x%n);
    
    x=x*a+b;
    x%=c;
    cout<<kor2[x%n].second<<endl;
    kor2.erase(kor2.begin()+x%n);
    
    
    x=x*a+b;
    x%=c;
    cout<<kor3[x%n].second<<endl;
    kor3.erase(kor3.begin()+x%n);
    
    
    x=x*a+b;
    x%=c;
    cout<<kor4[x%n].second<<endl;
    kor4.erase(kor4.begin()+x%n);
    
    for (int i=0;i<kor1.size();i++)
    v.push_back(kor1[i]);
    for (int i=0;i<kor2.size();i++)
    v.push_back(kor2[i]);
    for (int i=0;i<kor3.size();i++)
    v.push_back(kor3[i]);
    for (int i=0;i<kor4.size();i++)
    v.push_back(kor4[i]);
    sort(v.begin(),v.end());
}

cin.get();cin.get();
return 0;}