/*
The selfish, they're all standing in line
Faithing and hoping to buy themselves time
Me, I figure as each breath goes by
I only own my mind

The North is to South what the clock is to time
There's East and there's West and there's everywhere life
I know I was born and I know that I'll die
The in-between is mine
I am mine

And the feeling, it gets left behind
All the innocence lost at one time
Significant, behind the eyes
There's no need to hide
We're safe tonight

The ocean is full 'cause everyone's crying
The full moon is looking for friends at high tide
The sorrow grows bigger when the sorrow's denied
I only know my mind
I am mine

And the meaning, it gets left behind
All the innocents lost at one time
Significant, behind the eyes
There's no need to hide
We're safe tonight

And the feelings that get left behind
All the innocents broken with lies
Significance, between the lines
We may need to hide

And the meanings that get left behind
All the innocents lost at one time
We're all different behind the eyes
There's no need to hide
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

string st;
int ans;
vector<pair<char,int > > compress(string st){
	vector<pair<char,int> > ret;
	int cnt=0;
	for (int i=0;i<st.size();i++){
		if (i>0&&st[i]!=st[i-1]){
			ret.push_back(make_pair(st[i-1],cnt));
			cnt=0;
		}
		++cnt;
	}
	ret.push_back(make_pair(st[st.size()-1],cnt));
	return ret;
}

vector<pair<char,int> > clean_up(vector<pair<char,int> > v){
	vector<pair<char,int> > ret;
	for (int i=0;i<v.size();i++){
		if (v[i].second>0)
			ret.push_back(v[i]);
	}
	return ret;
}

vector<pair<char,int> > rebuild(vector<pair<char,int> > v){
	vector<pair<char,int> > ret;
	if (v.size()==0)
		return ret;
	int cnt=0;
	for (int i=0;i<v.size();i++){
		if (i>0&&v[i].first!=v[i-1].first){
			ret.push_back(make_pair(v[i-1].first,cnt));
			cnt=0;
		}
		cnt+=v[i].second;
	}
	ret.push_back(make_pair(v[v.size()-1].first,cnt));
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;

	vector<pair<char,int> > V=compress(st);
	while (V.size()>1){
		++ans;
		for (int i=0;i<V.size();i++){
			if (i>0)
				V[i].second--;
			if (i+1<V.size())
				V[i].second--;
		}
		V=clean_up(V);
		V=rebuild(V);
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}