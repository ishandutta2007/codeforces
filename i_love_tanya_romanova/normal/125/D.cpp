/*
There was a friend of mine on murder
And the judge's gavel fell
Jury found him guilty
Gave him sixteen years in hell
He said "I ain't spending my life here
I ain't living alone
Ain't breaking no rocks on the chain gang
I'm breakin' out and headin' home

Gonna make a jailbreak
And I'm lookin' towards the sky
I'm gonna make a jailbreak
Oh, how I wish that I could fly

All in the name of liberty
All in the name of liberty
Got to be free

Jailbreak, let me out of here
Jailbreak, sixteen years
Jailbreak, had more than I can take
Jailbreak, yeah

He said he'd seen his lady being fooled with
By another man
She was down and he was up
He had a gun in his hand
Bullets started flying everywhere
And people started to scream
Big man lying on the ground
With a hole in his body
Where his life had been
But it was -

All in the name of liberty
All in the name of liberty
I got to be free

Jailbreak, jailbreak
I got to break out
Out of here

Heartbeats they were racin'
Freedom he was chasin'
Spotlights, sirens, rifles firing
But he made it out
With a bullet in his back
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

int n,ar[1<<20];
vector<int> ans1,ans2;
int found;
int used[1<<20];

void solve(vector<int> v)
{
    for (int i=1;i<=n;i++)
        used[i]=0;
    for (int i=0;i<v.size();i++)
        used[v[i]]=1;
    
    vector<int> v2;
    for (int i=1;i<=n;i++)
    {
        if (used[i])
            continue;
        v2.push_back(i);
    }
    for (int i=1;i<v2.size();i++)
    {
        int dif1=ar[v2[1]]-ar[v2[0]];
        int dif2=ar[v2[i]]-ar[v2[i-1]];
        if (dif1!=dif2)
            return;
    }
    found=1;
    vector<int> v1=v;
    ans1=v1;
    ans2=v2;
    for (int i=0;i<v1.size();i++)
        ans1[i]=ar[v1[i]];
    for (int i=0;i<v2.size();i++)
        ans2[i]=ar[v2[i]];
}

void tryy(int ind1,int ind2)
{
    for (int i=1;i<=n;i++)
        used[i]=0;
    
    used[ind1]=used[ind2]=1;
    
    vector<int> v1;
    v1.push_back(ind1);
    v1.push_back(ind2);
    
    int cur=ar[v1.back()];
    int dif=cur-ar[v1[0]];
    for (int i=1;i<=n;i++)
    {
        if (used[i])
            continue;
        if (ar[i]!=cur+dif)
            continue;
        v1.push_back(i);
        cur+=dif;
    }
    
    solve(v1);
    int tval=v1[0];
    v1.erase(v1.begin());
    solve(v1);
    v1.insert(v1.begin(),tval);
    v1.pop_back();
    solve(v1);
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

if (n==2)
{
    cout<<ar[1]<<endl;
    cout<<ar[2]<<endl;
    return 0;
}

tryy(1,2);
if (n>2)
{
    tryy(1,3);
    tryy(2,3);
}

if (found==0)
{
    cout<<"No solution"<<endl;
}
else
{
    for (int i=0;i<ans1.size();i++)
    {
        if (i)
            cout<<" ";
        cout<<ans1[i];
    }
    cout<<endl;
    for (int i=0;i<ans2.size();i++)
    {
        if (i)
            cout<<" ";
        cout<<ans2[i];
    }
    cout<<endl;
}

//cin.get();cin.get();
return 0;}