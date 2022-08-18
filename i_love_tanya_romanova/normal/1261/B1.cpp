/*
Behold 'tis I the commander
Whose grip controls you all
Resist me not, surrender
I'll no compassion call

(Tyrant) Capture of humanity
(Tyrant) Conqueror of all
(Tyrant) Hideous destructor
(Tyrant) Every man shall fall

Your very lives are held within my fingers
I snap them and you cower down in fear
You spineless things who belly down to slither
To the end of the world you follow to be near

(Tyrant) Capture of humanity
(Tyrant) Conqueror of all
(Tyrant) Hideous destructor
(Tyrant) Every man shall fall

Mourn for us oppressed in fear
Chained and shackled we are bound
Freedom choked in dread we live
Since Tyrant was enthroned

I listen not to sympathy
Whilst ruler of this land
Withdraw your feeble aches and moans
Or suffer smite from this my hand

(Tyrant) Capture of humanity
(Tyrant) Conqueror of all
(Tyrant) Hideous destructor
(Tyrant) Every man shall fall

Mourn for us oppressed in fear
Chained and shackled we are bound
Freedom choked in dread we live
Since Tyrant was enthroned

My legions faithful unto death
I'll summon to my court
And as you perish each of you
Shall scream as you are sought

(Tyrant) Capture of humanity
(Tyrant) Conqueror of all
(Tyrant) Hideous destructor
(Tyrant) Every man shall fall
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

const int N = 500031;

int n;
int ar[N];
vector<pair<int,int> > order;
int tests;
int len[N],ps[N];
vector<int> queries[N];
int t[N*4];
int ans[N];

void add(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v]+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	t[v]=t[v*2]+t[v*2+1];
}

int get(int v,int tl,int tr,int am){
	if (tl==tr)
		return tl;
	int tm=tl+tr;
	tm/=2;
	if (t[v*2]>=am)
		return get(v*2,tl,tm,am);
	am-=t[v*2];
	return get(v*2+1,tm+1,tr,am);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	order.push_back(make_pair(ar[i],-i));
    }

    sort(order.begin(),order.end());
    reverse(order.begin(),order.end());

    cin>>tests;
    for (int test=1;test<=tests;test++){
    	cin>>len[test]>>ps[test];
    	queries[len[test]].push_back(test);
    }

    for (int i=0;i<order.size();i++){
    	int pss=order[i].second;
    	pss*=-1;
    	add(1,1,n,pss,1);
    	for (int j=0;j<queries[i+1].size();j++){
    		int qu_id=queries[i+1][j];
    		int which=ps[qu_id];
    		int where=get(1,1,n,which);
    		ans[qu_id]=ar[where];
    	}
    }

    for (int i=1;i<=tests;i++){
    	cout<<ans[i]<<"\n";
    }

//    cin.get(); cin.get();
    return 0;
}