/*
Trapped in purgatory
A lifeless object, alive
Awaiting reprisal
Death will be their acquisition

The sky is turning red
Return to power draws near
Fall into me, the sky's crimson tears
Abolish the rules made of stone

Pierced from below, souls of my treacherous past
Betrayed by many, now ornaments dripping above

Awaiting the hour of reprisal
Your time slips away

Raining blood
From a lacerated sky
Bleeding its horror
Creating my structure
Now I shall reign in blood!
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

const int N = 200031;

int n,s1,s2;
int L[N];
int sparse_min[22][N],sparse_max[22][N];
int x[N];
int max_reach;

pair<int,int> get_bound(int l,int r){
	int span=r-l+1;
	int lev=L[span];
	int min_value=min(sparse_min[lev][l],sparse_min[lev][r-(1<<lev)+1]);
	int max_value=max(sparse_max[lev][l],sparse_max[lev][r-(1<<lev)+1]);
	return make_pair(min_value,max_value);
}

bool check(int span){
	if (abs(s2-s1)>span)
		return false;
	max_reach=0;
	for (int i=1;i<=n;i++){
		if (abs(x[i]-s1)>span)
			break;
		max_reach=max(max_reach,i);
	}

	for (int i=1;i<=n;i++){
		if (abs(x[i]-s2)>span)
			break;
		max_reach=max(max_reach,i);
	}

	//cout<<max_reach<<" "<<span<<endl;

	pair<int,int> temp=get_bound(1,2);
//	cout<<temp.first<<" "<<temp.second<<endl;
	for (int i=1;i<=n;i++){
//		cout<<span<<" "<<i<<" "<<max_reach<<endl;
		if (max_reach<i)
			return false;
		int l,r;
		l=i;r=n;
		while (l<r){
			int mid=l+r+1;
			mid/=2;
			pair<int,int> p=get_bound(i,mid);
			if (p.first<x[i]-span||p.second>x[i]+span)
				r=mid-1;
			else
				l=mid;
		}
		max_reach=max(max_reach,l);
	}

	return true;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>s1>>s2;

	L[1]=0;
	for (int i=2;i<=n;i++)
		L[i]=L[i/2]+1;

	for (int i=1;i<=n;i++){
		cin>>x[i];
	}

	for (int i=1;i<=n;i++)
		sparse_min[0][i]=x[i],
		sparse_max[0][i]=x[i];

	for (int lev=1;lev<=20;lev++){
		for (int i=1;i+(1<<lev)-1<=n;i++){
			sparse_min[lev][i]=min(sparse_min[lev-1][i],sparse_min[lev-1][i+(1<<lev)/2]);
			sparse_max[lev][i]=max(sparse_max[lev-1][i],sparse_max[lev-1][i+(1<<lev)/2]);
		}
	}

	int l,r;
	l=0;
	r=1e9;
	while (l<r){
		int mid=l+r;
		mid/=2;
		if (check(mid))
			r=mid;
		else
			l=mid+1;
	}

	cout<<l<<endl;

	cin.get(); cin.get();
	return 0;
}