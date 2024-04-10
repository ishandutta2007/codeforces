/*
Searching
From so far away
I'll be back to stay
Searching
From so far away
All these endless days
Maladjusted, I suffer
Maladjusted, I suffer

Yearning
From so far away
Dreams are left decayed
Ill adjusted I suffer
Readjusting discovered

Ending life
The days of unending strife
So sacred as years go by
We don't care till it's time to die
On those ending days we'll harmonise

Searching
From so far away
I'll be back to stay
Back to stay

Ending life
The days of unending strife
So sacred as years go by
We don't care till it's time to die
On those ending days we'll harmonise
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

const int bs = 1000000007;

const int N = 1100031;

long long n,k;
long long ar[N];
long long t[N*4];
vector<long long> S;
vector<long long> memo_S;

multiset<long long> ::iterator it;

long long total_white,cur_dep,cur_aggr,at_cur_dep;

vector<int> events[N];

void apply_all_events(int dep){
	for (int i=0;i<events[dep].size();i++){
		int p=events[dep][i];
		cur_aggr+=p;
	}
}

long long get_longest_that_fits(int h_lim){
	// in fact no requirement to stay below
	if (S.size()==0)
		return -1;
	long long ret=S.back();
	S.pop_back();
	return ret;
}

void add_event(pair<int,int> p){
	int a=p.first;
	int b=p.second;
	if (a>1e6)
		return;
	events[a].push_back(b);
}

bool solve(long long bound){
	for (int i=0;i<=1000000;i++){
		events[i].clear();
	}

	total_white=1;
	cur_dep=0;
	cur_aggr=0;
	at_cur_dep=1;

	S.clear();
	S=memo_S;

	while (true){
		if (total_white>=k)
			return true;
		while (at_cur_dep==0){ // get the right depth
			cur_dep++;
			if (cur_dep>bound||cur_dep>1e6)
				return false; // because thinking about proper handling is hard.
			apply_all_events(cur_dep);
			at_cur_dep=cur_aggr;
		}

		--at_cur_dep;
		long long height_left=bound-cur_dep;
		long long max_len=height_left*2-1;
		int LEN=get_longest_that_fits(max_len);
		if (LEN==-1) // no more left.
			return false;
		total_white-=2;
		long long effective_len;
		if (LEN>max_len){
			effective_len=max_len;
		}
		else
		{
			effective_len=LEN;
		}

		total_white+=effective_len;

		if (LEN%2==1) // nice case
		{
			add_event(make_pair(cur_dep+2,2));
			add_event(make_pair(cur_dep+2+LEN/2,-2));
		}
		else // crappy parity
		{
			add_event(make_pair(cur_dep+2,2));
			add_event(make_pair(cur_dep+2+LEN/2-1,-1));
			add_event(make_pair(cur_dep+2+LEN/2,-1));
		}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	memo_S.push_back(ar[i]);
    }

    sort(memo_S.begin(),memo_S.end());

    long long SS=1;
    for (int i=1;i<=n;i++){
    	SS+=ar[i]-2;
    }

    if (SS<k){
    	cout<<-1<<endl;
    	return 0;
    }

    long long l,r;
    l=0;
    r=1e9;


    while (l<r){
    	long long mid=l+r;
    	mid/=2;
    	if (solve(mid))
    		r=mid;
    	else
    		l=mid+1;
    }

    if (l>1e9-1e5){
    	l=-1;
    }

    cout<<l<<endl;

    //cin.get(); cin.get();
    return 0;
}