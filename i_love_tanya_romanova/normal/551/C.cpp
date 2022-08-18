/*
Safe from all the hurting safe from all the lies
Locked myself away now blindfold on my eyes
Lost in your predictions fiction from the stars
Bound to be your destiny you know who you are

Someone stopped the starlight loosened up the ties
Now the door is open open like my eyes

So if the sky's about to fall i'll still be up there flying
It's just the fear of what's in store that ever stops you trying
And if the storm throws you around it only makes you stronger
But when the stars come crashing down it's a phenomenon

Scared of all your visions scared of all you hear
Thought you'd bring security but all you brought was fear
Someone stopped the starlight brought me back to life
Set me free from your deceit threw away the lies

So if the sky's about to fall i'll still be up there flying
It's just the fear of what's in store that ever stops you trying
And if the storm throws you around it only makes you stronger
But when the stars come crashing down it's a phenomenon

I don't want many things just a chance to spread my wings
Don't know what the future brings but I want to be there

Someone stopped the starlight loosened up the ties
Now the door is open open like my eyes

So if the sky's about to fall i'll still be up there flying
It's just the fear of what's in store that ever stops you trying
And if the storm throws you around it only makes you stronger
But when the stars come crashing down it's a phenomenon
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
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,m,ar[1<<20],l,r,mid,need,rem;
long long minn;
long long memo,tmoves,todel,gmoves;

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++) 
 cin>>ar[i];

l=1;
r=1e14+1e13;
while (l<r)
{
    mid=l+r;
    mid/=2;
    need=0;
    memo=0;
    for (int i=n;i;i--)
    {
     rem=mid-i;
     tmoves=ar[i];
     todel=min(tmoves,memo);
     memo-=todel;
     tmoves-=todel;
     if (tmoves<=0)continue;
     if (rem<=0){need+=m+1;continue;}
     minn=tmoves/rem+(tmoves%rem>0);
     gmoves=minn*rem;
     need+=minn;
     memo+=gmoves-tmoves;       
    }
    if (need>m)l=mid+1;
    else r=mid;
    //cout<<"%"<<need<<" "<<mid<<endl;
}

cout<<l<<endl;

//cin.get();cin.get();
return 0;}