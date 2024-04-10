/*
Shot!

Revelations - of the minds
Destination - changing all the times
Pave the way - speed of light
Here to stay - can not fear this fight or get it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

A situation - coming strong
From a nation - spinning worlds along
Don't ya see this new world life?
Can not beat it
Can not tear it down to make it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

Shot!

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!
Generation day... Shot!
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

const int N = 510031;

int old_bit[1<<22];
int n,m;
int mask[22];

int pcount(int x){
	if (x==0)
		return 0;
	return pcount(x/2)+x%2;
}

int get_old_bit_naive(int x){
	for (int i=22;i>=0;--i){
		if (x&(1<<i))
			return i;
	}
	return -1;
}

bool clique(){
	for (int i=0;i<n;i++){
		if (mask[i]!=(1<<n)-1)
			return false;
	}
	return true;
}

vector<int> ans_vec;

int MASK;

void dfs(int v){
	if (MASK&(1<<v))
		MASK-=(1<<v);
	while (true){
		int can_take=(mask[v]&MASK);
		if (can_take==0)
			break;
		int ps=old_bit[can_take];
		dfs(ps);
	}
}

bool is_connected(int mask_to_check){
	int q=old_bit[mask_to_check];
	MASK=mask_to_check;
	dfs(q);
	return (MASK==0);
}
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	old_bit[0]=-1;
	for (int i=1;i<(1<<22);i++){
		old_bit[i]=get_old_bit_naive(i);
	}

	cin>>n>>m;

	for (int i=0;i<n;i++){
		mask[i]|=(1<<i);
	}

	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		--a;
		--b;
		mask[a]|=(1<<b);
		mask[b]|=(1<<a);
	}

	if (clique()){
		cout<<0<<endl;
		return 0;
	}

	int ans=1e9;
	int ans_mask=1e9;

	for (int mask_taken=1;mask_taken<(1<<n);mask_taken++){
		int here=pcount(mask_taken);
		if (here>=ans)
			continue;
		int mask_covered=0;
		for (int i=0;i<n;i++){
			if (mask_taken&(1<<i))
				mask_covered|=mask[i];
		}
		if (mask_covered!=(1<<n)-1)
			continue;
		if (is_connected(mask_taken)){
			ans=here;
			ans_mask=mask_taken;
		}
	}

	cout<<ans<<endl;
	for (int i=0;i<n;i++){
		if (ans_mask&(1<<i))
			ans_vec.push_back(i+1);
	}
	for (int i=0;i<ans_vec.size();i++){
		if (i)
			cout<<" ";
		cout<<ans_vec[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}