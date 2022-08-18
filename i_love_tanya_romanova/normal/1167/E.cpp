/*
In the gloom the gathering storm abates
In the ships gimlet eyes await
The call to arms to hammer at the gates
To blow them wide throw evil to its fate

All summers long the drills to build the machine
To turn man from flesh and blood to steel
From paper soldiers to bodies on the beach
From summer sends to Armageddon's reach

Overlord your master not your god
The enemy coast dawning grey with scud
These wretched souls puking shaking fear
To take a bullet for those who send them here

The world's all right the cliffs erupt in flame
No escape remorseless shrapnel rains
Drowning men no chance for a warrior's fate
A choking death enter hell's gates

Sliding we go only fear on our side
To the edge of the wire
And we rush with the tide
Oh the water is red
With the blood of the dead
But I'm still alive pray to God I survive

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through

The rising dead faces bloated torn
They are relieved the living wait their turn
Your number's up the bullet's got your name
You still go on to hell and back again

Valhalla waits Valkyries rise and fall
The warrior tombs lie open for us all
A ghostly hand reaches through the wall
Blood and sand we will prevail

Sliding we go only fear on our side
To the edge of the wire
And we rush with the tide
Oh the water is red
With the blood of the dead
But I'm still alive pray to God I survive

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through

How long on this longest day
'Till we finally make it through
How long on this longest day
'Till we finally make it through
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int cut[N],n,x,ar[N],hi;

vector<int> entries[N];

long long ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d",&n);
    scanf("%d",&x);
    for (int i=1;i<=n;i++){
    	scanf("%d",&ar[i]);
    	entries[ar[i]].push_back(i);
    }

    for (int i=1;i<=n;i++){
    	cut[ar[i]]=max(cut[ar[i]],hi);
    	hi=max(hi,ar[i]);
    }

    for (int i=1;i<=x;i++){
    	cut[i]=max(cut[i],cut[i-1]);
    }

   /* for (int i=1;i<=x;i++){
    	cout<<cut[i]<<" ";
    }
    cout<<endl;
*/
    int R=1;
    int max_reached=0;

    int max_prefix=x;

    for (int i=1;i<=x;i++){
    	if (entries[i].size()==0)
    		continue;
    	if (max_reached>entries[i][0])
    	{
    		max_prefix=i-1;
    		break;
    	}
    	max_reached=max(max_reached,entries[i].back());
    }

    int min_suffix=1;
    int min_reached=n;
    for (int i=x;i>=1;--i){
    	if (entries[i].size()==0)
    		continue;
    	if (min_reached<entries[i].back())
    	{
    		min_suffix=i;
    		break;
    	}
    	min_reached=min(min_reached,entries[i][0]);
    }

    //cout<<max_prefix<<" "<<min_suffix<<endl;


    int cur_lim=min_suffix;

    for (int pref=0;pref<=max_prefix;pref++){
    	cur_lim=max(cur_lim,cut[pref]);
    	cur_lim=max(cur_lim,pref+1);
    //	cout<<cur_lim<<"@"<<ans<<endl;
   		ans+=x-cur_lim+1;
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}