/*
I miss the warm embrace I felt
First time you touched me
Secure and safe in open arms
I should have known you'd crush me
A snake you were when we met
I loved you anyway
Pulling out your poisoned fangs
The venom never goes away
Serpent swims free in my blood
Dragons sleeping in my veins
Jackyl speaking with tongue
Roach egg laying in my brain
Once stalked beneath your shadow
Sleepwalking to the gallows
I'm the sun that beats your brow in
'til I finally threw the towel in
Never knowing if I'd wake up in a
Whirlpool got redundant
My brain was just some driftwood
In a cesspool I became dead
From a rock star to a desk fool
Was my destiny someone said
Love's a tide pool
Taste the waters life's abundant
Taste me
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

const int N = 210031;

int n;
vector<pair<int,int> >order;
long long ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	int len;
    	cin>>len;
    	int cur_max=-2e9;
    	int cur_min=2e9;;
    	int has_increase=0;
    	for (;len;--len){
    		int val;
    		cin>>val;
    		cur_max=max(val,cur_max);
    		cur_min=min(val,cur_min);
    		if (val>cur_min){
    			has_increase=1;
    		}
    	}
    	if (has_increase==0){
    		order.push_back(make_pair(cur_min,cur_max));
    	}
    }
    sort(order.begin(),order.end());

    ans=1ll*n*n;

    for (int i=0;i<order.size();i++){
    	int id=lower_bound(order.begin(),order.end(),make_pair(order[i].second,-1))-order.begin();
    	ans-=(order.size()-id);
    }

    cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}