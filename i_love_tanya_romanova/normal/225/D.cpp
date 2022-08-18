/*  
Dolls of voodoo all stuck with pins
One for each of us and our sins
So you lay us in a line
Push your pins they make us humble
Only you can tell in time
If we fall or mearly stumble

But tell me
Can you heal what father's done?
Or fix this hole in mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

Mirror, mirror upon the wall
Break the spell or become the doll
See you sharpening the pins
So the holes will remind us
We're just the toys in the hands of another
And in time, the needles turn from shine to rust

But tell me
Can you heal what father's done?
Or fix this hole in mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

Jab it
Here come the pins

Blood for face
Sweat for dirt
Three X's for the stone
To break this curse
A ritual's due
I believe I'm not alone
Shell of shotgun
Pint of gin
Numb us up to shield the pins
Renew our faith
Which way we can
To fall in love with life again
To fall in love with life again
To fall in love with life again
To fall in love
To fall in love
To fall in love with life again

So tell me
Can you heal what father's done?
Or fix this hole in mother's son?
Can you heal the broken worlds within?
Can you strip away so we may start again?

Tell me
Can you heal what father's done?
Or cut this rope and let us run?
Just when all seems fine
And I'm pain free
You jab another pin
Jab another pin in me

No more pins in me
No more, no more pins in me
No more, no more pins in me
No more, no more, no more
No, no, no
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
#define eps 0.001
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
#define clone agsdahfaassdg
using namespace std;

long n,m;char c;
long bad[100][100],ti,tj,sz,pi[1000],pj[1000];
long mask;
queue<pair<pair<long, long> ,long> > qu;
long arp[17][17][1<<16];
long calc;
long qi,qj,tti,ttj;
pair<pair<long, long> ,long> temp;
long qmask,dir,tempi,tempj;
long tm,tempmask;
long ans;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=0;i<=n+1;i++)
for (int j=0;j<=m+1;j++)
bad[i][j]=-1;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
bad[i][j]=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>c;
    if (c=='#'){bad[i][j]=-1;continue;}
    if (c=='@'){ti=i;tj=j;}
    if (c>='1'&&c<='9'){sz=max(sz,sz+c-48-sz);pi[c-48]=i;pj[c-48]=j;}
}

for (int i=2;i<=sz;i++)
{
    if (pi[i-1]==pi[i]+1)
    mask+=(1<<(2*i-4))*0;
   else if (pi[i-1]==pi[i]-1)
    mask+=(1<<(2*i-4))*2;
    else if (pj[i-1]==pj[i]+1)
    mask+=(1<<(2*i-4))*3;
    else mask+=(1<<(2*i-4))*1;
 //   cout<<mask<<endl;
}


qu.push(make_pair(make_pair(pi[1],pj[1]),mask));
//cout<<mask<<endl;
arp[pi[1]][pj[1]][mask]=1;
/*
for (int i=1;i<=6;i++)
{
    cout<<mask%2;mask/=2;
}*/

cout<<endl;
ans=1000000;

while (qu.size())
{
      calc++;
      temp=qu.front();
      qu.pop();
      qi=temp.first.first;
      qj=temp.first.second;
      qmask=temp.second;
      if (qi==ti&&qj==tj)ans=min(ans,arp[qi][qj][qmask]);
      //cout<<qi<<" "<<qj<<" "<<qmask<<endl;
      tti=qi;ttj=qj;
      long ttm=qmask;
      for (int i=1;i<sz-1;i++)
      {
          dir=ttm%4;
          ttm/=4;
          //cout<<dir<<endl;
          //dir>>=(2*i);
          if (dir==0){tti--;}else if (dir==1){ttj++;}
          else if (dir==2){tti++;} else {ttj--;}
          bad[tti][ttj]=calc;
       //   cout<<tti<<"  D"<<ttj<<" "<<i<<" "<<dir<<" "<<tm<<endl;
      }
      if (bad[qi-1][qj]!=-1&&bad[qi-1][qj]!=calc)
      {
       tempmask=(qmask<<2);
       tempmask%=(1<<(sz*2-2));
       tempmask+=2;
       tempi=qi-1;
       tempj=qj;
       if (arp[tempi][tempj][tempmask]==0)
       {
        arp[tempi][tempj][tempmask]=arp[qi][qj][qmask]+1;
        qu.push(make_pair(make_pair(tempi,tempj),tempmask));
     // cout<<"up"<<tempi<<" "<<tempj<<" "<<tempmask<<endl;
       }
      }

      if (bad[qi+1][qj]!=-1&&bad[qi+1][qj]!=calc)
      {
       tempmask=(qmask<<2);
       tempmask%=(1<<(sz*2-2));
       tempi=qi+1;
       tempj=qj;
       if (arp[tempi][tempj][tempmask]==0)
       {
        arp[tempi][tempj][tempmask]=arp[qi][qj][qmask]+1;
        qu.push(make_pair(make_pair(tempi,tempj),tempmask));
       //cout<<"down"<<tempi<<" "<<tempj<<" "<<tempmask<<endl;
       }
      }

      if (bad[qi][qj-1]!=-1&&bad[qi][qj-1]!=calc)
      {
       tempmask=(qmask<<2);
       tempmask%=(1<<(sz*2-2));
       tempmask+=1;
       tempi=qi;
       tempj=qj-1;
       if (arp[tempi][tempj][tempmask]==0)
       {
        arp[tempi][tempj][tempmask]=arp[qi][qj][qmask]+1;
        qu.push(make_pair(make_pair(tempi,tempj),tempmask));
       //cout<<"left"<<tempi<<" "<<tempj<<" "<<tempmask<<endl;
       }
      }

      if (bad[qi][qj+1]!=-1&&bad[qi][qj+1]!=calc)
      {
       tempmask=(qmask<<2);
       tempmask%=(1<<(sz*2-2));
       tempmask+=3
       ;
       tempi=qi;
       tempj=qj+1;
       if (arp[tempi][tempj][tempmask]==0)
       {
        arp[tempi][tempj][tempmask]=arp[qi][qj][qmask]+1;
        qu.push(make_pair(make_pair(tempi,tempj),tempmask));
      // cout<<"rifht"<<tempi<<" "<<tempj<<" "<<tempmask<<endl;
       }
      }
    //  cin.get();
}

if (ans>10000)ans=0;
cout<<ans-1<<endl;


cin.get();cin.get();
return 0;}