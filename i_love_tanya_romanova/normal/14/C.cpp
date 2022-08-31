/*
Life it seems, will fade away
Drifting further every day
Getting lost within myself
Nothing matters no one else
I have lost the will to live
Simply nothing more to give
There is nothing more for me
Need the end to set me free

Things are not what they used to be
Missing one inside of me
Deathly lost, this can't be real
Cannot stand this hell I feel
Emptiness is filing me
To the point of agony
Growing darkness taking dawn
I was me, but now He's gone

No one but me can save myself, but it's too late
Now I can't think, think why I should even try
Yesterday seems as though it never existed
Death Greets me warm, now I will just say good-bye
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
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

set<pair<long, long> > pts;
set<pair<pair<long, long> ,pair<long, long> > > has;
long x1[10],y1[10],x2[10],y2[10];

string solve()
{
       if (pts.size()!=4)return "NO";
       long mix,mx;
       mix=x1[0];
       mx=x1[0];
       for (int i=0;i<4;i++)
       {
           mix=min(mix,x1[i]);
           mx=max(mx,x1[i]);
       }
       for (int i=0;i<4;i++)
       {
           mix=min(mix,x2[i]);
           mx=max(mx,x2[i]);
       }
       if (mx==mix)return "NO";
       long my,miy;
       miy=my=y1[0];
       for (int i=0;i<4;i++)
       {
           miy=min(miy,y1[i]);
           my=max(my,y1[i]);
       }
       for (int i=0;i<4;i++)
       {
           miy=min(miy,y2[i]);
           my=max(my,y2[i]);
       }
       if (my==miy)return "NO";
       
       if (has.find(make_pair(make_pair(mix,miy),make_pair(mix,my)))==has.end())
       return "NO";
       
       if (has.find(make_pair(make_pair(mix,miy),make_pair(mx,miy)))==has.end())
       return "NO";
       
       if (has.find(make_pair(make_pair(mx,miy),make_pair(mx,my)))==has.end())
       return "NO";
       
       if (has.find(make_pair(make_pair(mix,my),make_pair(mx,my)))==has.end())
       return "NO";
       
       return "YES";
}


int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<4;i++)
{
    cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    pts.insert(make_pair(x1[i],y1[i]));
    pts.insert(make_pair(x2[i],y2[i]));
    has.insert(make_pair(make_pair(x1[i],y1[i]),make_pair(x2[i],y2[i])));
    has.insert(make_pair(make_pair(x2[i],y2[i]),make_pair(x1[i],y1[i])));
}

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}