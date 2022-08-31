/*
I got my feelers out
Pleasure I can give you pain
I'm the demon of misfortune
Let me tell you that bad luck is my game

Fires burning make you cold
You can touch but you can't hold
It's an even split
Between zip and the number on your ticket
Nothing to brag about dragging in the dirt
I'm a nasty piece of work

Down get down on your knees
Running gonna bring you down
I'm the demon of disorder
You know I'm gonna drive you into the ground

As you're stepping through the door
My shadow crawls across your floor
Your dream of love
It's not enough it's gonna come to nothing
You ain't seen nothing it's gonna get worse
I'm a nasty nasty

It's an even split
Between zip and the number on your ticket
Your dream of love
It's not enough it's gonna come to nothing
Nothing to brag about dragging in the dirt
You ain't seen nothing it's gonna get worse
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
#define bsize 512

using namespace std;

int n,k,a,m,have,val1,val2,x;
set<int> c;
set<int>::iterator it;

int get(int x)
{
    int block=a+1;
    int full=x/block;
    if (x%block==block-1)
        ++full;
    return full;
}

int ans;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>a;
cin>>m;

have=get(n);

c.insert(0);
c.insert(n+1);

ans=-1;

for (int i=1;i<=m;i++)
{
    cin>>x;
    it=c.lower_bound(x);
    --it;
    val1=(*it);
    it++;
    val2=(*it);
    have-=get(val2-val1-1);
    c.insert(x);
    have+=get(x-val1-1);
    have+=get(val2-x-1);
    if (have<k)
    {
        ans=i;
        break;
    }
}
cout<<ans<<endl;
//cin.get();cin.get();
return 0;}