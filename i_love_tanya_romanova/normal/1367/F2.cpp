/*
Monuments of dying dreams
As far away as Eden
These hours standing still
Finding comfort in a distant past

Slaves of yesterday
You are blind
Blind to the sunrise

A roaming spirit, Forever lost
Among the living
Walking down the fatal road
Cursed to be left behind

Slaves of yesterday
You are blind
Blind to the sunrise
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

#define bs 1000000007

const int N = 500031;

int tests,n;
vector<pair<int,int> > order;
int t[N*4];
int ans;
int ar[N];
vector<vector<int> > rebuild(vector<pair<int,int> > v){
	vector<vector<int> > ret;
	vector<int> cur;
	for (int i=0;i<v.size();i++){
		if (i>0&&v[i].first!=v[i-1].first){
			ret.push_back(cur);
			cur.clear();
		}
		cur.push_back(v[i].second);
	}
	ret.push_back(cur);
	return ret;
}

int how_much_before(vector<int> l,vector<int> r){
	int ret=0;
	for (int i=0;i<l.size();i++){
		if (l[i]<r[0])
			ret++;
	}
	return ret;
}

int how_much_after(vector<int> l,vector<int> r){
	int ret=0;
	for (int i=0;i<r.size();i++){
		if (r[i]>l.back())
			++ret;
	}
	return ret;
}

bool disjoint(vector<int> l,vector<int> r){
	return l.back()<r[0];
}

int merge2(vector<int> l,vector<int> r){
	int ret=r.size();
	for (int i=0;i<l.size();i++){
		int ps=lower_bound(r.begin(),r.end(),l[i])-r.begin();
		ret=max(ret,i+1+((int)r.size()-ps));
	}
	return ret;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);


  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  order.clear();
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
		  order.push_back(make_pair(ar[i],i));
	  }
	  sort(order.begin(),order.end());
	  vector<vector<int> > vv=rebuild(order);

	  int ans=0;
	  for (int i=0;i<vv.size();i++){

//		  cout<<vv[i].size()<<"@"<<endl;
		  int here=vv[i].size();
		  if (i+1<vv.size()){
			  here=max(here,merge2(vv[i],vv[i+1]));
		  }
		  if (i>0&&i+1<vv.size()){
			  here=max(here,how_much_before(vv[i-1],vv[i])+(int)vv[i].size()+how_much_after(vv[i],vv[i+1]));
		  }
		  ans=max(ans,here);

		  if (i>0&&disjoint(vv[i-1],vv[i]))
			  continue;
		  int cnt=vv[i].size();
		  if (i>0)
			  cnt+=how_much_before(vv[i-1],vv[i]);

		  for (int j=i+1;j<vv.size();j++){
			  if (!disjoint(vv[j-1],vv[j]))
			  {
				  cnt+=how_much_after(vv[j-1],vv[j]);
				  break;
			  }
			  cnt+=vv[j].size();
		  }
		  ans=max(ans,cnt);
	  }
	  cout<<n-ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}