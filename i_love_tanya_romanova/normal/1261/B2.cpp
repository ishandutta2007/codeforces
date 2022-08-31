/*
Pounding the world like a battering ram
Forging the furnace for the final grand slam
Chopping away at the source soon the course will be done
Leaving a trail of destruction that's second to none

Hammering anvils straining muscle and might
Shattering blows crashing browbeating fright
Fast devastating and desolisating the curse
Blasting the cannons of truth through each man of this earth

Wielding the axe comes the one culmination
That's always seemed certain to bring down the curtain on greed

Sifting the good from the bad it's the age for the rage
Of the dogs which must fall to the just and be free

Now grate for the vandals who trampled and sampled
Till this place conditioned brought forth demolition to war

The slipping and sliding corrosive subsiding
That withered and wained till the world seemed all drained fills the bay

Pounding the world like a battering ram
Forging the furnace for the final grand slam
Chopping away at the source soon the course will be done
Leaving a trail of destruction that's second to none
Second to none
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