/*
All has now been broken
On streets I dare not walk
Freedom is an illusion
I build my fences high
If there was something out there
I've learned not to expect
There's a hundred million reasons
Not to care

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown

As always in these matters
You broke the deal of deals
And wasted what was given
To revel in your mess
I gave up all for nothing
I tried my best and failed
There's a thousand million reasons
Never to share again

This is how it all begins
This is how it all begins

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown

This is how it all begins

Come now
Come now
Come now

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 100031;

string st,ans;
int cnt[N];
int mask[N];
int n;

int get_mask(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		res|=(1<<(st[i]-'a'));
	}
	return res;
}

int total_with[N];

bool can_put(int val,int ps){
	if (cnt[val]==0)
		return false;
	if (!(mask[ps]&(1<<val)))
		return false;
	//cout<<val<<"@"<<ps<<endl;
	cnt[val]--;
	int ok=1;
	for (int sub=1;sub<64;sub++){
		int ttl=0;
		for (int i=0;i<6;i++){
			if (sub&(1<<i))
				ttl+=cnt[i];
		}
		if (ttl>total_with[sub]){
		//	cout<<ttl<<" "<<total_with[sub]<<" "<<sub<<" "<<ps<<" "<<val<<endl;
			ok=0;}
	}
	cnt[val]++;
	return ok;
}

int shit;

int what_to_put(int ps){
	for (int i=0;i<6;i++){
		if (can_put(i,ps))
			return i;
	}
	shit=1;
	return 0;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	for (int i=0;i<st.size();i++){
		cnt[st[i]-'a']++;
	}

	for (int i=1;i<=st.size();i++)
		mask[i]=63;

	cin>>n;
	for(int i=1;i<=n;i++){
		int ps;
		string temp;
		cin>>ps>>temp;
		mask[ps]=get_mask(temp);
	//	cout<<ps<<"#"<<temp<<" "<<mask[ps]<<endl;
	}

	n=st.size();

	for (int i=1;i<=n;i++){
		for (int here=0;here<64;here++){
			if ((here&(mask[i]))!=0)
				total_with[here]++;
		}
	}

	for (int i=1;i<=st.size();i++){
		for (int here=0;here<64;here++){
			if ((here&(mask[i]))!=0)
				total_with[here]--;
		}
		/*for (int j=0;j<64;j++){
			cout<<total_with[j]<<" ";
		}
		cout<<endl;*/
		int ok=what_to_put(i);
		ans+=char(ok+'a');
	//	cout<<char(ok+'a');
		cnt[ok]--;
	}

	if (shit)
		ans="Impossible";
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}