/*
It can't get any colder, no sun left, no light
It makes me even stronger, boosts my will to fight
So much undone
Let's get it on
No moral tells me so, there is no wrong no right

It's all that I do
It's all that I say
It's all that I live for
It's my only way

There's no point in waiting when there is no where or when
Blow it all to pieces and then build it up again
It's understood
So far so good
Start it all over and I'll see you there my friend
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

int tests,n,sz[N];
int have[231][231];
int know_solution;
vector<int> real_answer,cur_answer;
int cur_sz[231];
int already_used[231];
int where_in_ans[231];

void set_it_up(){
	cur_answer.clear();
	for (int i=1;i<=n;i++){
		cur_sz[i]=sz[i];
		already_used[i]=0;
	}
}

int get_free(int id){
	int ok=1;
	int tsz=sz[id];
	int bound=(int)cur_answer.size()-(tsz-1);

	for (int i=1;i<=n;i++){
		if (have[id][i]==1&&already_used[i]==1&&where_in_ans[i]<bound)
			return -1;
	}

	for (int i=1;i<=n;i++){
		if (have[id][i]==1&&already_used[i]==0)
			return i;
	}
	return 0;
}

void remove_el(int val){
	cur_answer.push_back(val);
	where_in_ans[val]=cur_answer.size()-1;
	already_used[val]=1;
	for (int i=2;i<=n;i++){
		if (have[i][val]){
			cur_sz[i]--;
		}
	}
}

int get_next(){
	vector<int> candidates;
	for (int i=2;i<=n;i++){
		if (cur_sz[i]==1){
			candidates.push_back(i);
		}
	}
	if (candidates.size()==1){
		return get_free(candidates[0]);
	}
	return -1;
}

void validate(int fi){
	set_it_up();
	remove_el(fi);
//	remove_el(se);

	/*if (fi==3&&se==1){
		cout<<"!"<<endl;
	}*/

	for (int iter=2;iter<=n;iter++){
		int Q=get_next();
		if (Q==-1)
			return;
		/*if (fi==3&&se==1){
			cout<<Q<<"@"<<endl;
		}*/
		remove_el(Q);
	}
	/*if (fi==3&&se==1)
		cout<<cur_answer.size()<<endl;*/
	if (cur_answer.size()==n){
		know_solution=1;
		real_answer=cur_answer;
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=2;i<=n;i++){
		  cin>>sz[i];
		  for (int j=1;j<=n;j++){
			  have[i][j]=0;
		  }
		  for (int j=1;j<=sz[i];j++){
			  int val;
			  cin>>val;
			  have[i][val]=1;
		  }
	  }

	  know_solution=0;

	  for (int fi=1;fi<=n;fi++){
		    if (know_solution)
				  break;
			  validate(fi);
	  }

	  for (int i=0;i<real_answer.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<real_answer[i];
	  }
	  cout<<endl;

  }

  // cin.get(); cin.get();
  return 0;
}