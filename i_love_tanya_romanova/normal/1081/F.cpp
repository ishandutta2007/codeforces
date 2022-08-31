/*
I know you don't want to see. I know you're not part of me
But you wonder just the same. So I'll let you in on this game
What's on the top is just the beginning of the protectorate that keeps Gaia spinning
It never ends, and with the gifts Luna sends, to the apocalypse
on we defend for the right to live in a perfect world
For our past mistakes, extinction we are hurled
Trying to make amends for the Impergium, as Weaver and the Wyld and a bitch called the Wyrm

(You don't want to know)
All the power of the Wyld that runs through me, yet the reason why is an answer that eludes me

(You don't want to see)
Our viewpoint on what mankind is doing, that black inside when frenzy is brewing

(You don't want to feel)
The sorrow that my heart holds in knowing just where my hopes and dreams are going

(I won't let you be)
Caught up in a war that you are not part of. I sign this letter Your Father, With Love.

I'm trying to set my mind free. I'm sorry you never knew me.
My soul is in recession. Painful to make this confession.
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

int n,t,pref0,pref1,suf0,suf1;
int lo[10],hi[10];
int memo;
int ans[N];

int secret[N];

int apply_move(int l,int r){
	if (rand()%2)
		for (int i=l;i<=n;i++){
			secret[i]^=1;
		}
	else
		for (int i=1;i<=r;i++){
			secret[i]^=1;
		}
	int res=0;
	for (int i=1;i<=n;i++){
		res+=secret[i];
	}
	return res;
}
int query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int val;
	cin>>val;
//	val=apply_move(l,r);
	return val;
}

int LO[10],HI[10];

bool valid(){
	for (int i=0;i<2;i++){
		if (lo[i]!=LO[i]||hi[i]!=HI[i])
			return false;
	}
	return true;
}

int p1;
int ITER;

void update_state(int p0,int p1,int s0,int s1){
	pref1=memo-s1;
	pref0=ITER-pref1;
	suf1=memo-pref1;
	suf0=(n-ITER)-suf1;
}

void get_assum(int p0,int p1,int s0,int s1){
	LO[0]=min(p0,p1)+s1;
	LO[1]=min(p0,p1)+s0;
	HI[0]=max(p0,p1)+s1;
	HI[1]=max(p0,p1)+s0;
}

void generate_data(){
	vector<int> order;
	for (int i=1;i<=n;i++){
		order.push_back(i);
	}
	random_shuffle(order.begin(),order.end());
	for (int i=0;i<t;i++){
		secret[order[i]]=1;
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>t;
    pref0=0;
    pref1=0;
    suf0=n-t;
    suf1=t;

    /*generate_data();
    for (int i=1;i<=n;i++){
    	cout<<secret[i];
    }
    cout<<endl;
    */
    for (int iter=1;iter<n;iter++){
    	ITER=iter;
    	lo[0]=1e9;
    	hi[0]=0;
    	lo[1]=1e9;
    	hi[1]=0;
    	for (int i=1;i<=32;i++){
    		int here=query(iter+1,n);
    		lo[i%2]=min(lo[i%2],here);
    		hi[i%2]=max(hi[i%2],here);
    		memo=here;
    	}
    	get_assum(pref0+1,pref1,suf0-1,suf1);
    	//get_assum(pref0,pref1+1,suf0,suf1-1);
  //  	cout<<lo[0]<<" "<<lo[1]<<" "<<hi[0]<<" "<<hi[1]<<endl;
   // 	cout<<LO[0]<<" "<<LO[1]<<" "<<HI[0]<<" "<<HI[1]<<endl;
 //   	get_assum(pref0+1,pref1,suf0+1,suf1);
//    	cout<<LO[0]<<" "<<LO[1]<<" "<<HI[0]<<" "<<HI[1]<<endl;
    	if (valid()){
    		ans[iter]=0;
    		update_state(pref0+1,pref1,suf0-1,suf1);
    	}
    	else
    	{
    		ans[iter]=1;
    		update_state(pref0,pref1+1,suf0,suf1-1);
    	}
    }

    if (suf0)
    	ans[n]=0;
    else
    	ans[n]=1;

    cout<<"! ";
    for (int i=1;i<=n;i++){
    	cout<<ans[i];
    }
    cout<<endl;


//    cin.get(); cin.get();
    return 0;
}