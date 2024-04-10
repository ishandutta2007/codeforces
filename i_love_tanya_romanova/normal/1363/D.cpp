/*
Bypassed the day I can hear them coming
They walk round my door and speak of their coming
My trial awaits got nowhere to run
My only words how soon you have come

And I think about what you told me
When I was about to join in

Defy only if you have a way to resist the lies
Decline only if you have the intention of taking this advice
Apply only if you're not afraid to see your spirit die
Retreat only if you dare not hear yourself say goodbye

Who brought me here this place is familiar
Where houses are black under the sun
Strangers pass on streets with strange names
All I can think is how soon they have come

Look at me now they have cut my hair
It's a long way back
They kicked me down and I could not rise
I will never arrive
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

#define bs 998244353

const int N = 610031;

int tests,n,k;
vector<int> V[N];
int used[N];
vector<int> candidates;
int known_max;

int make_query(vector<int> v){
	if (v.size()==0)
		return -1;
	cout<<"?";
	cout<<" "<<v.size();
	for (int i=0;i<v.size();i++){
		cout<<" "<<v[i];
	}
	cout<<endl;
	int res;
	cin>>res;
	known_max=max(known_max,res);
	return res;
}

int query_external(int id){
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	for (int i=0;i<V[id].size();i++){
		int to=V[id][i];
		used[to]=1;
	}
	vector<int> vv;
	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		vv.push_back(i);
	}
	return make_query(vv);
}

int query_vector(vector<int> v){
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	for (int ii=0;ii<v.size();ii++){
		int id=v[ii];
		for (int i=0;i<V[id].size();i++){
			int to=V[id][i];
			used[to]=1;
		}
	}

	vector<int> vv;
	for (int i=1;i<=n;i++){
		if (used[i]==0)
			continue;
		vv.push_back(i);
	}
	return make_query(vv);
}

int solver(vector<int> v,int max_here){
	/*for (int i=0;i<v.size();i++){
		cout<<"@@@"<<v[i];
	}
	cout<<endl;
*/
	if (v.size()==1)
		return v[0];
	vector<int> l,r;
	for (int i=0;i<v.size();i++){
		if (i%2)
			l.push_back(v[i]);
		else
			r.push_back(v[i]);
	}
	if (max_here==-1){
		int left_val=query_vector(l);
		int right_val=query_vector(r);
		if (left_val>right_val)
			return solver(l,left_val);
		else
			return solver(r,right_val);
	}
	int here=query_vector(l);
	if (here==max_here)
		return solver(l,max_here);
	else
		return solver(r,max_here);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  //ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
//	  k=n-1;
	  known_max=0;
	  candidates.clear();
	  for (int i=0;i<=k;i++){
		  V[i].clear();
	  }
	  for (int i=1;i<=n;i++){
		  used[i]=0;
	  }

	  for (int i=0;i<k;i++){
		  int cnt;
		  cin>>cnt;
//		  cnt=1;
		  for (int ii=1;ii<=cnt;ii++){
			  int id;
//			  id=i+2;
			  cin>>id;
			  used[id]=1;
			  V[i].push_back(id);
		  }

	  }

	  for (int i=1;i<=n;i++){
		  if (used[i]==0){
			  V[k].push_back(i);
		  }
	  }

	  for (int i=0;i<=k;i++){
		  candidates.push_back(i);
	  }

	  int max_id=solver(candidates,-1);

	  int others=query_external(max_id);

	 // cout<<max_id<<endl;

	  cout<<"!";
	  for (int i=0;i<k;i++){
		  if (i==max_id)
			  cout<<" "<<others;
		  else
			  cout<<" "<<known_max;
	  }
	  cout<<endl;
	  string trash;
	  cin>>trash;
  }

  cin.get(); cin.get();
  return 0;
}