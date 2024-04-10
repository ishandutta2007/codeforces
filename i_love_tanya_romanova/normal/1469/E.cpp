/*
What we don't know will set us free
Until tomorrow
What we don't show the enemy
Breaks them all to follow

What we don't show can never be
Until tomorrow
What we don't see, the agony
Await the call of sorrow

Reverence, you're taking
We're all forsaken
Reverence, mistaken
We're all forsaken
We're all forsaken

What we don't show, affinity
Until tomorrow
Cannot breathe, cannot flee
Break them all to follow

Reverence, you're taking
We're all forsaken
Reverence, mistaken
We're all forsaken
We're all forsaken

What we don't know will set us free
Until tomorrow
The purest deep, an empty sea
Break them all to follow

Reverence, you're taking
We're all forsaken
Reverence, mistaken
We're all forsaken
Reverence, you're taking
We're all forsaken
Reverence, mistaken
We're all just faking
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

const int MAGIC = 23;

int tests;
int n,k;
string st;
int next0[N];
int C;
int subsize[N*MAGIC*2];
int son[N*MAGIC*2][2];
int par[N*MAGIC*2];
string ans;

void reset_vertex(int id){
	son[id][0]=son[id][1]=0;
	par[id]=0;
	subsize[id]=0;
}

int get_son(int cur,int here){
	if (son[cur][here]==0){
		++C;
		son[cur][here]=C;
		reset_vertex(C);
		par[C]=cur;
	}
	return son[cur][here];
}

int get_subsize(int v,int bit){
	int new_v=get_son(v,bit);
	return subsize[new_v];
}

void add_string(int ps,int len){
	int cur=0;
	for (int i=0;i<len;i++){
		int here=st[ps+i]-'0';
		int to=get_son(cur,here);
		cur=to;
	}
	if (subsize[cur]==0){
		while (true){
			subsize[cur]++;
			if (cur==0)
				break;
			cur=par[cur];
		}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	cin>>st;
    	next0[st.size()]=st.size();
    	for (int i=st.size()-1;i>=0;--i){
    		next0[i]=next0[i+1];
    		if (st[i]=='0')
    			next0[i]=i;
    	}

    	C=0;
    	reset_vertex(0);

    	for (int i=0;i+k<=st.size();i++){
    		int thold=max(0,k-MAGIC);
    		if (next0[i]-i<thold) // we will cover this with "0000" prefix anyway
    			continue;
    		add_string(i+thold,k-thold);
    	}

    	int thold=max(0,k-MAGIC);
    	ans="";
    	for(int i=0;i<thold;i++){
    		ans+="0";
    	}

    	int remaining=k-thold;
    	int cur=0;
    	int shit=0;
    	for (int i=thold;i<k;i++){
    		int what_if_zero=get_subsize(cur,1);
    		int what_if_one=get_subsize(cur,0);
    		--remaining;
    		if (what_if_zero<(1<<remaining)){ // have a solution over 0
    			ans+="0";
    			cur=get_son(cur,1);
    			continue;
    		}
    		if (what_if_one<(1<<remaining)){ // have a solution over 1, still better than nothing.
    			ans+="1";
    			cur=get_son(cur,0);
    			continue;
    		}
    		// we are fucked.
    		shit=1;break;
    	}
    	if (shit){
    		cout<<"NO"<<endl;
    	}
    	else
    	{
    		cout<<"YES"<<endl;
    		cout<<ans<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}