/*
A morning breeze through my window
Some sun rays gone strange
There is one on my pillow
Waiting for someone to wake
Waiting for someone to break

Makes me feel just like a leaf

Like a leaf in the breeze
In the morning but still asleep
Slowly falling to the ground Without a sound

Morning breaks in the shadows
And mist from the near lying lake
Making shapes of the willows
Outside my window they wait
waiting for someone to take

Makes me feel just like a leaf

Like a leaf in the breeze
In the morning but still asleep
Slowly falling to the ground Without a sound

I say please, please believe me
If I would stay
just for the day
I would always be around

Slowly falling to the ground
Without a sound
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

long long n,k;
vector<long long> ans;
long long ways[1<<20];
long long done;
vector<int> v;
vector<vector<int> > good;
int used[20];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
/*
cin>>n;
for (int i=1;i<=n;i++)
{
    v.push_back(i);
}
do
{
    
    for (int i=0;i<n;i++)
        used[i]=0;
    vector<vector<int> > cycles;
    for (int i=0;i<n;i++)
    {
        if (used[i])
            continue;
        vector<int> temp;
        int cur=i;
        while (used[cur]==0)
        {
            temp.push_back(v[cur]);
            used[cur]=1;
            cur=v[cur]-1;
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        cycles.push_back(temp);
    }
    sort(cycles.begin(),cycles.end());
    vector<int> have;
    for (int i=0;i<cycles.size();i++)
    {
        for (int j=0;j<cycles[i].size();j++)
            have.push_back(cycles[i][j]);
    }
    if (have==v)
        good.push_back(have);
}while (next_permutation(v.begin(),v.end()));

for (int i=0;i<good.size();i++)
{
    cout<<i<<"^^^ : ";
    for (int j=0;j<good[i].size();j++)
        cout<<good[i][j]<<" ";
    cout<<endl;
}

*/
cin>>n;
ways[0]=1;
ways[1]=1;
for (int i=2;i<=60;i++)
ways[i]=ways[i-1]+ways[i-2];

cin>>k;
--k;
int done=0;
while (done<n)
{
    if (done==n-1)
    {
        ans.push_back(done+1);
        ++done;
        continue;
    }
    if (ways[n-done-1]>k)
    {
        //k-=ways[n-done-1];
        ans.push_back(done+1);
        ++done;
    }
    else
    {
        ans.push_back(done+2);
        ans.push_back(done+1);
        k-=ways[n-done-1];
        done+=2;
    }
}

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}