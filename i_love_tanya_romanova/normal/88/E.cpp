/*
Mott the Hoople and the game of Life yeah, yeah, yeah, yeah
Andy Kaufman in the wrestling match yeah, yeah, yeah, yeah
Monopoly, Twenty one, checkers, and chess yeah, yeah, yeah, yeah
Mister Fred Blassie in a breakfast mess yeah, yeah, yeah, yeah
Let's play Twister, let's play Risk yeah, yeah, yeah, yeah
I'll see you heaven if you make the list yeah, yeah, yeah, yeah

Now, Andy did you hear about this one?
Tell me, are you locked in the punch?
Andy are you goofing on Elvis? Hey, baby
Are we losing touch?

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool

Moses went walking with the staff of wood yeah, yeah, yeah, yeah
Newton got beaned by the apple good yeah, yeah, yeah, yeah
Egypt was troubled by the horrible asp yeah, yeah, yeah, yeah
Mister Charles Darwin had the gall to ask yeah, yeah, yeah, yeah

Now, Andy did you hear about this one?
Tell me, are you locked in the punch?
Andy are you goofing on Elvis? Hey, baby
Are you having fun?

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool

Here's a little agit for the never-believer yeah, yeah, yeah, yeah
Here's a little ghost for the offering yeah, yeah, yeah, yeah
Here's a truck stop instead of Saint Peter's yeah, yeah, yeah, yeah
Mister Andy Kaufman's gone wrestling yeah, yeah, yeah, yeah

Now, Andy did you hear about this one?
Tell me, are you locked in the punch?
Andy are you goofing on Elvis? Hey, baby
Are we losing touch?

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool

If you believed they put a man on the moon
Man on the moon
If you believe there's nothing up his sleeve
Then nothing is cool
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
long long ii,sq[200000];
long long q;long ts[500000],ans[500000],answ,was[2000];
    vector <pair <long, long> >v[300000];
int main()
{long n;
    cin>>n;
    answ=1000000;
    
for (int i=1;i<=51000;i++)
{ii=i;sq[i]=(ii+1)*ii/2;}

for (int i=1;i<=50000;i++)
for (int j=i+1;sq[j]-sq[i-1]<100000;j++)
{q=sq[j]-sq[i-1];pair <long, long> p=make_pair(i,j);
v[q].push_back(p);}

for (int i=2;i<n;i++)
{ 
    for (int i=0;i<1200;i++)
    was[i]=0;
    
    for (int j=0;j<v[i].size();j++)
      {long res=ts[v[i][j].second]^ts[v[i][j].first-1];
       was[res]=1;}
       
 q=0;
 while (was[q])++q;
 ans[i]=q;
  ts[i]=ts[i-1]^ans[i];}
 
 for (int i=0;i<v[n].size();i++)
 {long res=ts[v[n][i].second]^ts[v[n][i].first-1];
  if (res==0)answ=min(answ,v[n][i].second-v[n][i].first+1);

}

if (answ>10000)answ=-1;

cout<<answ<<endl;
cin.get();cin.get();
return 0;
}