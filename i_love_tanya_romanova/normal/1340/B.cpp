/*
I should have known there was someone else
Down below I always kept it to myself
Now I believe in nothing
Not today as I move myself out of your sight

Oh I'll be sleeping by myself tonight

I could never go with no one else
The hurt don't show but who knows, time will tell
Now I believe in nothing but the pain
And I can't see this turning out right

Oh I'll be sleeping by myself tonight

Forever be sad and lonely
Forever never be the same
Oh I close my eyes and wait for a sign
Am I just waiting in vain?

Oh I close my eyes and wait for a sign
Am I just waiting in vain?

Oh, I believe in love and disaster
Sometimes the two are just the same
I'm beginning to see
What's left of me is gonna have to be free to survive

Oh, I'll be sleeping by myself tonight

I believe in nothing but the pain
And I can't see this turning out right
I'll be sleeping by myself
I'll be sleeping by myself
I'll be sleeping by myself tonight
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

string maps[1000];

vector<int> ordr;

int n,k;
string st[N];
vector<int> ans;

int done[2031][2031],memo[2031][2031];
pair<int,int> next_move[2031][2031];
int already_done[2031][15],memo_put[2031][15];

int count_ones(string&st){
	int cnt=0;
	for (int i=0;i<st.size();i++){
		if (st[i]=='1')
			cnt++;
	}
	return cnt;
}

bool can_put(int id,int dig){
	if (already_done[id][dig])
		return memo_put[id][dig];

	already_done[id][dig]=1;
	for (int i=0;i<7;i++){
		if (maps[dig][i]=='0'&&st[id][ordr[i]]=='1')
			return false;
	}
	memo_put[id][dig]=1;
	return true;
}

bool solve(int ps,int rem){
	if (rem<0)
		return false;
	if (ps==n){
		return (rem==0);
	}
	if (done[ps][rem])
		return memo[ps][rem];
	done[ps][rem]=1;
	for (int i=9;i>=0;--i){
		if (!can_put(ps+1,i))
			continue;
		int new_rem=rem-count_ones(maps[i])+count_ones(st[ps+1]);
		int here=solve(ps+1,new_rem);
		if (here==1){
			memo[ps][rem]=1;
			next_move[ps][rem]=make_pair(i,new_rem);
			return true;
		}
	}
	return false;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);


  maps[0]="1111110";
  maps[1]="0110000";
  maps[2]="1101101";
  maps[3]="1111001";
  maps[4]="0110011";
  maps[5]="1011011";
  maps[6]="1011111";
  maps[7]="1110000";
  maps[8]="1111111";
  maps[9]="1111011";

  ordr.push_back(0);
  ordr.push_back(2);
  ordr.push_back(5);
  ordr.push_back(6);
  ordr.push_back(4);
  ordr.push_back(1);
  ordr.push_back(3);

  cin>>n>>k;
  for (int i=1;i<=n;i++){
	  cin>>st[i];
  }

  int ok=solve(0,k);

  if (!ok){
	  cout<<-1<<endl;
	  return 0;
  }

  int cur_rem=k;
  for (int iter=0;iter<n;iter++){
	  ans.push_back(next_move[iter][cur_rem].first);
	  cur_rem=next_move[iter][cur_rem].second;
  }

  for (int i=0;i<ans.size();i++){
	  cout<<ans[i];
  }
  cout<<endl;

  // cin.get(); cin.get();
  return 0;
}