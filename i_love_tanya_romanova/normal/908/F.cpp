/*
Like a man without a home
Watching people come and go
Carry on their daily lives
Without a thought for the ones alone

Cast the dream aside like throwing
A pebble into the ocean tide
And I'm feeling so alone again

Free the angry from their pain
Free the captives from their chains
Cast aside the doubt that
Nothing good can come their way again

Living in a world of lies
No matter how or hard we try
Living life without a dream today

Looking through a mist of truth
That we believe an elusive cloud
The things we find are hard to say now
That we live through day to day
Find it hard to force the reasons
Why we find it hard to die

Now we need to know the truth now
Open our eyes that we can see
So we live and breathe again
Better days for you and me
Can we even hope to deliver this
We are so far away

As one turns against the other
With a brother against brother
Situation like no other it's a picture of despair

As we look to see the man of sorrows
Passing knowledge to those
Who don't know
As we watch all our friends passing over
As they pass through the edges of time

And we see what's ahead that awaits us
That no longer do we feel afraid
So we look to see the man of sorrows
And the light is the darkness no more
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

const int N = 400031;

int X[N];
vector<int> entries[10];
int n;

int get_id(string st){
	if (st=="G")
		return 0;
	if (st=="R")
		return 1;
	return 2;
}

long long solve(vector<int> v,int le,int ri){
	if (v.size()==0)
		return 0;
	if (le==-1)
		return ri-v[0];
	if (ri==-1)
		return v.back()-le;
	long long longest=-1;
	v.push_back(ri);
	reverse(v.begin(),v.end());
	v.push_back(le);
	reverse(v.begin(),v.end());
	for (int i=1;i<v.size();i++){
		longest=max(longest,0ll+v[i]-v[i-1]);
	}
	return v.back()-v[0]-longest;
}

long long old_solver(int a,int b){
	long long res=b-a;
	vector<int> v;
	int id=lower_bound(entries[1].begin(),entries[1].end(),a)-entries[1].begin();
	for (int i=id;i<entries[1].size();i++){
		if (entries[1][i]>b)
			break;
		v.push_back(entries[1][i]);
	}
	res+=solve(v,a,b);

	v.clear();
	id=lower_bound(entries[2].begin(),entries[2].end(),a)-entries[2].begin();
	for (int i=id;i<entries[2].size();i++){
		if (entries[2][i]>b)
			break;
		v.push_back(entries[2][i]);
	}
	res+=solve(v,a,b);

	return res;
}

bool do_have(int id,int l,int r){
	int ps=lower_bound(entries[id].begin(),entries[id].end(),l)-entries[id].begin();
	if (ps<entries[id].size()&&entries[id][ps]<=r)
		return true;
	return false;
}

long long closest_solver(int v_id,int a,int b){
	int id=lower_bound(entries[v_id].begin(),entries[v_id].end(),a)-entries[v_id].begin();
	long long res=1e12;
	if (id>0)
		res=min(res,0ll+a-entries[v_id][id-1]);
	id=lower_bound(entries[v_id].begin(),entries[v_id].end(),b)-entries[v_id].begin();
	if (id<entries[v_id].size())
		res=min(res,entries[v_id][id]-b+0ll);
	return res+b-a;
}

long long smart_solver(long long a,long long b){
	int have1=do_have(1,a,b);
	int have2=do_have(2,a,b);
	if (have1==0&&have2==0) // just connect
		return b-a;
	if (have1==0||have2==0){
		if (entries[1].size()==0||entries[2].size()==0)
			return 1e15;
		long long here=b-a;
		if (have1)
			here+=closest_solver(2,a,b);
		else
			here+=closest_solver(1,a,b);
		return here;
	}
	return (b-a)*2;
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
		string temp;
		cin>>X[i]>>temp;
		int clr_id=get_id(temp);
		entries[clr_id].push_back(X[i]);
	}

	for (int i=0;i<3;i++){
		sort(entries[i].begin(),entries[i].end());
	}

	if (entries[0].size()==0){ // no G
		long long ans=0;
		if (entries[1].size())
			ans+=entries[1].back()-entries[1][0];
		if (entries[2].size())
			ans+=entries[2].back()-entries[2][0];
		cout<<ans<<endl;
		return 0;
	}

	long long res=0;

	for (int i=0;i+1<entries[0].size();i++){
		long long cand1=smart_solver(entries[0][i],entries[0][i+1]);
		long long cand2=old_solver(entries[0][i],entries[0][i+1]);
		//cout<<cand1<<"$"<<cand2<<endl;
		res+=min(cand1,cand2);
	}

	for (int i=1;i<=2;i++)
	{
		if (entries[i].size()>0){
			if (entries[i][0]<entries[0][0])
				res+=entries[0][0]-entries[i][0];
			if (entries[i].back()>entries[0].back())
				res+=entries[i].back()-entries[0].back();
		}
	}

	cout<<res<<endl;

	cin.get(); cin.get();
	return 0;
}