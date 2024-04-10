/*
Gently hold our heads
Gently hold our heads on high

Aimless time in fear now hide
Overthrow the plan
Confusion lies in all my words
Mad is the soul

We barricade ourselves in holes of temperament
This is the dawning of a new age
A heart that beats the wrong way
Insanity's crescendo

Gently hold our heads
Gently hold our heads on high

Wind colour - second sight
A touch of silence with the violence of dark
Illusion span - the aroma of time
Shadow life and the scent of nothingness

Insanity's crescendo

Infinite fall of instinct
Order of one spells deceit
Infinite lack of trust
Order of one obsolete

Oh, escaping time is all we lost ahead?
When it is found, can judgement make amends?

From force-fed impressions
Let us mortify the mind
Each soul to violate
Each instinct to be rendered false

Torn asunder be the conventional forms and frames
Now for the blood of heaven
Unlearn and the cleansing comes

Felt a tremor in the pillars of the senses
Cursed victim of a distance near
The first dream - the clearest vision

Aimlessly steer towards our light
We belong to thee
Oh, dearest bliss, unnerving silence
Entangled within

Dimly begotten in clarity found
Virgin-like tears for impurity bound
Beseech he who darkens the stars and the sky
Greet now this vision an emerald dawn

Empty the sun - carve out the wind
Insanity's crescendo
Tear out the blinded eye

Insanity's crescendo

Lament of thunder - take comfort in fear
Lightning veins in crude exterior
Voice the oppression - voice the hypocrisy
Lay down the law that made instinct fall

Escape now and revert
The cleansing rebirth
Torn asunder be
Affect me not; darkened vision
Insanity's crescendo

Grimly tread the footsteps torn
Rebellious stand the seeker tall
The thorn of insanity's hand
Take this darkened vision from my sight

Nailed to the image of ignorance
Each soul to violate
For the blood of heaven
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 200031;

int n,m;
long long sx,sy,fx,fy;
long long x[N],y[N];
set<pair<pair<long long, long long> ,int> > by_x,by_y;
set<pair<pair<long long, long long> ,int> >::iterator it_x;
set<pair<long long, int> > S;
set<pair<long long, int> >::iterator it_S;
long long D[N];
long long ans;

vector<int> get_interesting(int id){
	vector<int> ret;
	it_x=by_x.upper_bound(make_pair(make_pair(x[id],y[id]),id));
	if (it_x!=by_x.end())
		ret.push_back((*it_x).second);
	--it_x;
	if (it_x!=by_x.end()){
		--it_x;
		ret.push_back((*it_x).second);
	}
	it_x=by_y.upper_bound(make_pair(make_pair(y[id],x[id]),id));
	if (it_x!=by_y.end()){
		ret.push_back((*it_x).second);
	}
	--it_x;
	if (it_x!=by_y.begin()){
		--it_x;
		ret.push_back((*it_x).second);
	}
	return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>m;
    n=m;

    cin>>sx>>sy>>fx>>fy;
    for (int i=1;i<=n;i++){
    	cin>>x[i]>>y[i];
    	by_x.insert(make_pair(make_pair(x[i],y[i]),i));
    	by_y.insert(make_pair(make_pair(y[i],x[i]),i));
    }

    ans=abs(sx-fx)+abs(sy-fy);

    for (int i=1;i<=n;i++){
    	D[i]=min(abs(sx-x[i]),abs(sy-y[i]));
    	S.insert(make_pair(D[i],i));
    }

    for (int i=1;i<=n;i++){
    	it_S=S.begin();
    	pair<long long, int> p=(*it_S);
    	S.erase(it_S);
    	int my_id=p.second;
    	vector<int> interesting=get_interesting(my_id);
    	for (int j=0;j<interesting.size();j++){
    		int other_id=interesting[j];
    		//cout<<other_id<<"@"<<D[other_id]<<endl;
    		long long cost_here=D[my_id]+min(abs(x[my_id]-x[other_id]),abs(y[my_id]-y[other_id]));
    		//cout<<cost_here<<endl;

    		if (cost_here<D[other_id]){
    			S.erase(make_pair(D[other_id],other_id));
    			D[other_id]=cost_here;
    			S.insert(make_pair(D[other_id],other_id));
    		}
    	}
    }

    for (int i=1;i<=n;i++){
    	ans=min(ans,D[i]+abs(x[i]-fx)+abs(y[i]-fy));
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}