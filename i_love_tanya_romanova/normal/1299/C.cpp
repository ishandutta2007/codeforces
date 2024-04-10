/*
Here I am
Exposed in my brokenness
Here I am
Screaming these words
It's all I ever known of serenity
Here I am
Telling my pain, bearing my soul to the world
Here I am
Venting on this page, flawed and insecure no more
Here I am coming clean with myself, knowing that this time would come
Here I am
Like a thousand voices, I know I'm not the only one
Now my fist must never become unclenched
Eternally prevailing against
I must endure this misfortune and bring starvation for those
Hunger for my defeat

Give wings to my triumph
Let this life ascend
Give wings to my triumph
Give rebirth for ever death

Here I am
Exposed in my brokenness
For the world to see
Here I am screaming these words
It's all I've known for serenity

See my will before you know
Life ascend in every breath
A rise for every fall
A life for every death

Give me wing
So I ascend
Let me soar, take me farther then ever before

Give wings to my triumph
Life ascend in every breath
Give wings to my triumph
Rebirth for every death
Give wings to my triumph
And let me soar
Give wings to my triumph
Take me farther then every before
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
#define left asdgashgrketwjklrej
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

const int N = 1100031;

int n,ar[N];
double ans[N];
vector<pair<long long, long long> > v;

bool try_combine(){
	if (v.size()<2)
		return false;
	// v[v.size()-2].first/v[v.size()-2].second>v[v.size()-1].first/v[v.size()-1].second
	if (v[v.size()-2].first*v[v.size()-1].second>v[v.size()-1].first*v[v.size()-2].second){
		pair<long long, long long> p;
		p.first=v[v.size()-2].first+v[v.size()-1].first;
		p.second=v[v.size()-2].second+v[v.size()-1].second;
		v.pop_back();
		v.pop_back();
		v.push_back(p);
		return true;
	}
	return false;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	scanf("%d",&ar[i]);
    }

    for (int i=1;i<=n;i++){
    	v.push_back(make_pair(ar[i]+0ll,1ll));
    	while (true){
    		bool ok=try_combine();
    		if (!ok)
    			break;
    	}
    }

    int done=0;

    for (int i=0;i<v.size();i++){
    	int cnt=v[i].second;
    	for (int j=done+1;j<=done+cnt;j++){
    		ans[j]=1.0*v[i].first/cnt;
    	}
    	done+=cnt;
    }

    for (int i=1;i<=n;i++){
    	printf("%.12lf\n",ans[i]);
    }
   // cout<<endl;

    //    cin.get(); cin.get();
    return 0;
}