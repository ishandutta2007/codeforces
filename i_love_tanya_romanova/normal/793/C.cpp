/*
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
int X1,Y1,X2,Y2;
vector<pair<double,int> > events;
int rx[N],ry[N],vx[N],vy[N];

pair<double,double> intersect(pair<double,double> p1,pair< double,double> p2){
	p1.first=max(p1.first,p2.first);
	p1.second=min(p1.second,p2.second);
	return p1;
}

pair< double, double> solver(int sx,int dx,int l,int r){
	if (dx==0)
	{
		if (sx>l&&sx<r)
			return make_pair(-1e18,1e18);
		return make_pair(-1e9,-1e9);
	}

	long long D1=l-sx;
	long long D2=r-sx;
	if (dx<0)
	{
		D1*=-1;
		D2*=-1;
		dx*=-1;
	}
	if (D1>D2)
		swap(D1,D2);

	if (D2<=0)
		return make_pair(-1e9,-1e9);

	return make_pair(1.0*D1/dx,1.0*D2/dx);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>X1>>Y1>>X2>>Y2;

	events.push_back(make_pair(0,1));

	for (int i=1;i<=n;i++)
	{
		cin>>rx[i]>>ry[i]>>vx[i]>>vy[i];
		pair< double, double> seg1=solver(rx[i],vx[i],X1,X2);
		pair< double, double> seg2=solver(ry[i],vy[i],Y1,Y2);
		pair< double, double> p=intersect(seg1,seg2);

		if (p.first>p.second)
		{
			cout<<-1<<endl;
			return 0;
		}
		events.push_back(make_pair(p.first,1));
		events.push_back(make_pair(p.second,-1));
	}

	sort(events.begin(),events.end());
	int cnt=0;

	for (int i=0;i<events.size();i++)
	{
		cnt+=events[i].second;
		if (cnt==n+1)
		{
			cout.precision(12);
			cout<<fixed<<events[i].first<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

	cin.get(); cin.get();
	return 0;
}