/*
As I aim for that bright white day
Conflict serum is my aura
It seems that life's so fragile
I guess I'll fly some other time

I lack from superhighway thoughts
Won't live as long as the city lights
Soaked by underwater times
Electric splash on a midnight drive

Wish I could rape the day,
just something radical
Lost the sense of sweet things
Who's gonna take me widely?

Guided by the pinball map
The driver, still unknown to me
Who was sent to glorify?
Before we injected this common pride

Sometimes I don't belong
Release me from your world
Pacified by the small things in life
I wait for earthquakes to rearrange

Never been able to use the force
I only have it read to me
Despite all the misguided faith
(Maybe) I'll find a place in this mess

Early morning moments
A glimpse of joy
But soon it's over and I return to dust
As I try to be
Everything and everyone
I shrivel up and waste away
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n,m,cnt[N];
vector<int> with_cnt[N];
int ans;

int t[2][N*4];

int get(int id,int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[id][v];
	int tm=tl+tr;
	tm/=2;
	return max(get(id,v*2,tl,tm,l,min(r,tm)),get(id,v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int id,int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[id][v]=val;
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(id,v*2,tl,tm,ps,val);
	else
		update(id,v*2+1,tm+1,tr,ps,val);
	t[id][v]=max(t[id][v*2],t[id][v*2+1]);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b+1]--;
	}

	for (int i=1;i<=m;i++){
		cnt[i]+=cnt[i-1];
	}

	for (int i=1;i<=m;i++){
		//cout<<cnt[i]<<" ";
		with_cnt[cnt[i]].push_back(i);
	}

	for (int i=0;i<=n;i++){
		for (int j=0;j<with_cnt[i].size();j++){
			int ps=with_cnt[i][j];
			int max_left=get(0,1,1,m,1,ps-1);
			//cout<<ps<<" "<<max_left<<endl;

			update(0,1,1,m,ps,max_left+1);
		}
		reverse(with_cnt[i].begin(),with_cnt[i].end());
		for (int j=0;j<with_cnt[i].size();j++){
			int ps=with_cnt[i][j];
			int max_right=get(1,1,1,m,ps+1,m);
			update(1,1,1,m,ps,max_right+1);
		}
	}

	for (int i=1;i<=m;i++){
		int here=get(0,1,1,m,i,i)+get(1,1,1,m,i,i)-1;
		ans=max(ans,here);
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}