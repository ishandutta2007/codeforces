/*
As you watch from your house on the hill
World keeps spinning around you you're standing still
And a thought rivers enters your mind
Something happened once in my life
A fading picture of you that's so hard to describe
I've been where the sun never shines

That's alright there's a change in the story
That's alright there's a change in the plan
A twist in the tale

Face in the mirror head in the clouds
Hanging on to a dream that you can't do without
As it drops like a stone without trace
Give what you want take what you need
Squeezing so hard there's no room to breathe
And your flavour has fallen from grace

That's alright there's a change in the story
That's alright there's a change in the plan
A twist in the tale

I saw you dancing
Dancing on air
You were lost in the in the starlight
No one but me really cared

Every question turns out a lie
Can't you swallow the truth for once in your life
I loved you but don't ask me why

It's alright there's a change in the story
It's alright there's a change in the plan
A twist in the tale
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m,k,lab[N];
int id[N];
int w[N];
int max_w[N];

vector<pair<int,pair<int,int> > > edges;

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b,int c){
	w[a]=b;
	max_w[b]=max(max_w[b],max_w[a]);
	if (lab[a]>0&&lab[b]>0)
		max_w[b]=c;
	lab[b]+=lab[a];
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;

    for (int i=1;i<=k;i++){
    	cin>>id[i];
    	lab[id[i]]=1;
    }
    for(int i=1;i<=n;i++){
    	w[i]=i;
    	max_w[i]=0;
    }

    for (int i=1;i<=m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	edges.push_back(make_pair(c,make_pair(a,b)));
    }

    sort(edges.begin(),edges.end());
    for (int i=0;i<edges.size();i++){
    	int a=edges[i].second.first;
    	int b=edges[i].second.second;
    	//cout<<a<<" "<<b<<" "<<get(a)<<" "<<get(b)<<" "<<edges[i].first<<endl;
    	a=get(a);
    	b=get(b);
    	if (a==b)
    		continue;
    	merge(a,b,edges[i].first);
    }

    for (int i=1;i<=k;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<max_w[get(id[i])];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}