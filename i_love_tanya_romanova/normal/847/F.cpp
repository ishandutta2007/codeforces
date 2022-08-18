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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n,k,m,a;
int w[N],l[N];
int vote[N];

int last_vote[N],points[N];
vector<int> order;

bool cmp(int a,int b){
	if (points[a]!=points[b])
		return points[a]>points[b];
	return last_vote[a]<last_vote[b];
}

bool can_win(int id){
	for (int i=a+1;i<=m;i++)
		vote[i]=id;
	for (int i=1;i<=n;i++){
		last_vote[i]=-1;
		points[i]=0;
	}

	for (int i=1;i<=m;i++)
	{
		int id=vote[i];
		last_vote[id]=i;
		points[id]++;
	}

	order.clear();
	for (int i=1;i<=n;i++){
		order.push_back(i);
	}

	sort(order.begin(),order.end(),cmp);
	while (order.size()>k||points[order.back()]==0)
		order.pop_back();
	for (int i=0;i<order.size();i++){
		if (order[i]==id)
			return true;
	}

	return false;
}

bool can_lose(int id){
	for (int i=1;i<=n;i++)
		last_vote[i]=-1,points[i]=0;
	for (int i=1;i<=a;i++){
		int id=vote[i];
		last_vote[id]=i;
		points[id]++;
	}

	order.clear();
	for (int i=1;i<=n;i++)
	{
		order.push_back(i);
	}
	sort(order.begin(),order.end(),cmp);

	int q=0;
	while (order[q]!=id)
		++q;
	int ps=a+1;
	for (int i=q+1;i<order.size();i++){
		int cur_id=order[i];
		int need_votes=max(1,points[id]-points[cur_id]+1);
		while (ps<=m&&need_votes>0){
			need_votes--;
			vote[ps]=cur_id;
			++ps;
		}
	}

	for (int i=ps;i<=m;i++){
		if (n==1)
			vote[i]=1;
		else
		{
			if (id==1)
				vote[i]=2;
			else
				vote[i]=1;
		}
	}

	// CP
	for (int i=1;i<=n;i++){
		last_vote[i]=-1;
		points[i]=0;
	}

	for (int i=1;i<=m;i++)
	{
		int id=vote[i];
		last_vote[id]=i;
		points[id]++;
	}

	order.clear();
	for (int i=1;i<=n;i++){
		order.push_back(i);
	}

	/*if (id==1){
		for (int i=1;i<=m;i++){
			cout<<vote[i]<<"% ";
		}
		cout<<endl;
	}*/
	sort(order.begin(),order.end(),cmp);
	/*if (id==1){
		for (int i=0;i<order.size();i++){
			cout<<order[i]<<" ";
		}
		cout<<endl;
	}
*/
	while (order.size()>k||points[order.back()]==0)
		order.pop_back();
	for (int i=0;i<order.size();i++){
		if (order[i]==id)
			return false;
	}

	return true;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k>>m>>a;

	for (int i=1;i<=a;i++){
		cin>>vote[i];
	}

	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		w[i]=can_win(i);
		l[i]=can_lose(i);
		if (l[i]==0)
			cout<<1;
		else if (w[i]==1)
			cout<<2;
		else
			cout<<3;
	}
	cout<<endl;


	cin.get(); cin.get();
	return 0;
}