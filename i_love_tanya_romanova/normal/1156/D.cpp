/*
Can't speak
Can't talk
Can't do anything they want

Can't hide
Or change your mind
Gonna live with all my soul
Inside

Can't speak
Can't talk
Can't stop for the reeling cause
Or love
I told 'em all about it
Can't talk
'cause I'm already lost

Can't think
Can't cry
Keep thinking of a suicide
It's hard
I just can't forget it
Gonna fade 'cause I'm already dead

Can't think
Can't dream
Don't care if I live or die
Don't talk
I just can't believe it
Gonna fade 'cause I'm already dead

Can't think
I cant dream
I don't believe anything I see
I really don't wanna get it
Gotta leave or I'll live to regret it

Can't speak
Can't lie
Don't go anywhere to hide
Can't think
Can't cry
Keep thinking of a suicide

Can't speak
Can't talk
Can't do anything I want
Can't hide
Or change your mind
Gonna live with all my soul inside

Can't speak
Can't talk
Can't do anything I want
Can't hide
Or change your mind
Gonna live with all my soul inside
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

const int N = 610031;

int n;
vector<pair<int,int> > edges[3];

int w[N];
int SZ0[N];
int SZ1[N];

long long SZ01[N];

int sz[N];

long long ans;

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

int root0[N];

void merge(int a,int b){
	a=get(a);
	b=get(b);
	w[a]=b;
	sz[b]+=sz[a];
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<n;i++){
    	int a,b,clr;
    	cin>>a>>b>>clr;
    	edges[clr].push_back(make_pair(a,b));
    }

    for (int i=1;i<=n;i++){
    	w[i]=i;
    	sz[i]=1;
    }

    for (int i=0;i<edges[1].size();i++){
    	int a=edges[1][i].first;
    	int b=edges[1][i].second;
    	merge(a,b);
    }

    for (int i=1;i<=n;i++){
    	SZ1[i]=sz[get(i)];
    }

    for (int i=1;i<=n;i++){
    	w[i]=i;
    	sz[i]=1;
    }

    for (int i=0;i<edges[0].size();i++){
    	int a=edges[0][i].first;
    	int b=edges[0][i].second;
    	merge(a,b);
    }

    for (int i=1;i<=n;i++){
    	int a=get(i);
    	SZ01[a]+=SZ1[i];
    }

    for (int i=1;i<=n;i++){
    	ans+=SZ01[get(i)];
    }

    cout<<ans-n<<endl;

//    cin.get(); cin.get();
    return 0;
}