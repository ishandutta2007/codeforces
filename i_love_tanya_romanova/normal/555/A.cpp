/*
The dusk falls - time is drawing near
The sky lit blood red -
The moon displays it's glory
The gusts carry's a silent hymn to my ear
Darkness surrounds me with a veil of silk
Coldness chisels signs with my breath

Close your eyes - close your mind
And dancing in the moonlight
Close your eyes - close your mind
And dancing in the moonlight

My feet carry me softly as on clouds
The luscious odor of the night wind
Slips into my nose
From a distant I recall
The howling of an animal
Shadows moving in rhythm with the trees
The night has never seen the grey of day
My hands caressed by moonlight
My eyes close to the melody of night

Close your eyes - close your mind
And dancing in the moonlight
Close your eyes - close your mind
And dancing in the moonlight

The night has never seen the grey of day
My body drifts like in a fairy tale

Close your eyes - close your mind
And dancing in the moonlight
Close your eyes - close your mind
And dancing in the moonlight
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

int n,m,sz,q,ans;
vector<int> v;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

int lines=n;

for (int i=1;i<=m;i++)
{
    cin>>sz;
    v.clear();
    for (int j=1;j<=sz;j++)
    {
        cin>>q;
        v.push_back(q);
    }
    if (v[0]==1)
    {
        int q=0;
        while (q<v.size()&&v[q]==q+1)
            ++q;
        lines-=q-1;
    }
}

ans=lines-1+(lines-m);
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}