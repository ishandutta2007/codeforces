/*
We will not return to the countless mistakes of the past
I will not relive the failures of the man I once was

Only through dedication will I destroy all preconception

No longer will I let myself be truly satisfied with the standard
We will not return to the countless mistakes of the past

Only through dedication will I destroy all preconception

Let this be
Be the day
Day of my
My declaration
Let this be the day of my declaration

Join me,
Walk with me

Shatter the bonds that tie us
To what we strive to never be

Join me,
Walk with me
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1200031;

int n;
string st[N];

int can_be_first[N],can_be_second[N];

long long ans;

pair<int,int> get_balance(string st){
	int cur=0;
	int mx=0;
	for (int i=0;i<st.size();i++){
		if (st[i]=='(')
			++cur;
		else
			--cur;
		mx=min(mx,cur);
	}
	return make_pair(mx,cur);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;

	for (int i=1;i<=n;i++){
		cin>>st[i];
		pair<int,int> p=get_balance(st[i]);
		// can be first?
		if (p.first>=0&&p.second>=0)
			can_be_first[p.second]++;
		// can be second?
		if (p.first==p.second&&p.second<=0){
			can_be_second[-p.second]++;
		}
	}

	for (int i=0;i<=1000000;i++){
		ans+=can_be_first[i]*1ll*can_be_second[i];
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}