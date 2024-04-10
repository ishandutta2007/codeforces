/*
Murder takes me by the hand
We play this wicked game
I am the evil on these lands
Since the day darkness came
Bodies lay in shallow ground
Held tight in death's embrace
Consumed by the blood
As I dig my victim's grave

I lay hypnotized in the flood
Corruption of the dead

Bathe in blood
Bathe in blood
Bathe in blood
Bathe in blood

Screaming for no one to hear
The first cut I take
Hearing your weakened cries
The reaper awakes
Longing to consume your power
To renew my youth
Blood is my belief
Vanity is my truth

I lay hypnotized in the flood
Corruption of the dead

Bathe in blood
Bathe in blood
Bathe in blood
Bathe in blood

Kill, bathe in blood of the pure
Fresh youthful meat
No hope of fleeing from me
Your death will be sweet
Drained of your freedom and life
Stripped of your will
I'll keep you bleeding for me
You are my thrill

Bathe in blood

Terror on your deathly face
Blood spills from your wounds
Fate has sentenced you to death
Your gift I consume
Victim of violent torture
What was yours now mine
I tear the beauty from your flesh
I feed on the divine

I lay hypnotized in the flood
Corruption of the dead

Bathe in blood
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
double x[20000],y[20000],t[20000],p[20000],ans[20000],answ;
vector<pair<double, long> > v;
long temp;

double gd(long a,long b)
{
 return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>x[i]>>y[i]>>t[i]>>p[i];

for (int i=1;i<=n;i++)
{
    v.push_back(make_pair(t[i],i));
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    temp=v[i].second;
    for (int j=1;j<=n;j++)
     if (gd(temp,j)<=t[temp]-t[j])
     ans[temp]=max(ans[temp],ans[j]);
     ans[temp]+=p[temp];
     answ=max(answ,ans[temp]);
}
cout.precision(12);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}