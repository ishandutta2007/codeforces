/*
Stick your fingers in the eyes of night
Rip open the Belly of Death
Now you'll see
What is real

Tear down the image of youth all around
Steal the dreams from their minds
And you'll be
All their lies

Can it be what you're taught to believe
It's nothing more than your mind can conceive
He's out there waiting, he's waiting for you
The psycho is ready to kill

Well you're a mean one, a bloody bastard son
You don't care what they say or what they do
It matters not to you

You've been warned not to set foot after dark
You think it's all just for fun
But there's no setting sun

Can it be what you're taught to believe
It's nothing more than your mind can conceive
He's out there waiting, he's waiting for you
The psycho is ready to kill

One way all the time
You can't seem to get it right
You never see the tunnel
Or the light
Spend a million just to say
You're hip
You got to find a way
To get the thrill of your life
Trip the lights
Trip the light fantastic
Party and you'll die
Someday you will die

3 am and you feel that twitch again
For a walk in the park
It's getting late
Slip through the gate

The psycho jumps out from behind
Sticks his knife in your throat
And you die
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
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int tests,n,p[N];
vector<int> order;
long long pref[N];

long long x,y,a,b,cx,cy,cboth;
long long k,win;

long long solver(){
	long long ret=0;
	ret=pref[cboth]*(x+y)+(pref[cboth+cx]-pref[cboth])*x+(pref[cboth+cx+cy]-pref[cboth+cx])*y;
	ret=max(ret,pref[cboth]*(x+y)+(pref[cboth+cy]-pref[cboth])*y+(pref[cboth+cx+cy]-pref[cboth+cy])*x);
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>p[i];
    		p[i]/=100;
    		order.push_back(p[i]);
    	}
    	sort(order.begin(),order.end());
    	reverse(order.begin(),order.end());
    	for (int i=1;i<=n;i++){
    		pref[i]=pref[i-1]+order[i-1];
    	}

    	cin>>x>>a;
    	cin>>y>>b;
    	cin>>k;

    	win=-1;

    	cx=0;
    	cy=0;
    	cboth=0;

    	for (int i=1;i<=n;i++){
    		if (i%a==0&&i%b==0){
    			cboth++;
    		}
    		else if (i%a==0){
    			cx++;
    		}
    		else if (i%b==0){
    			cy++;
    		}
    		long long here=solver();
    		if (here>=k){
    			win=i;
    			break;
    		}
    	}
    	cout<<win<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}