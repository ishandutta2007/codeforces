/*
Shot!

Revelations - of the minds
Destination - changing all the times
Pave the way - speed of light
Here to stay - can not fear this fight or get it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

A situation - coming strong
From a nation - spinning worlds along
Don't ya see this new world life?
Can not beat it
Can not tear it down to make it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

Shot!

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!
Generation day... Shot!
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
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n,k;
int x[N],r[N],q[N];
vector<pair<int,int> > by_r;
vector<pair<pair<int,int>,int > > by_qx;

int where_in_second[N];
int t[N];

void add(int i,int delta){
	for (;i<N;i=(i|(i+1)))
		t[i]+=delta;
}

int sum(int r){
	int result=0;
	for (;r>=0;r=(r&(r+1))-1)
		result+=t[r];
	return result;
}

int solver(int iq,int L,int R){
	L=lower_bound(by_qx.begin(),by_qx.end(),make_pair(make_pair(iq,L),-1))-by_qx.begin();
	R=lower_bound(by_qx.begin(),by_qx.end(),make_pair(make_pair(iq,R+1),-1))-by_qx.begin();
	--R;
	if (R<L)
		return 0;
	return sum(R)-sum(L-1);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>k;

	for (int i=1;i<=n;i++){
		cin>>x[i]>>r[i]>>q[i];
		by_r.push_back(make_pair(r[i],i));
		by_qx.push_back(make_pair(make_pair(q[i],x[i]),i));
	}

	sort(by_r.begin(),by_r.end());
	reverse(by_r.begin(),by_r.end());

	sort(by_qx.begin(),by_qx.end());
	//reverse(by_qx.begin(),by_qx.end());

	for (int i=0;i<by_qx.size();i++){
		int id=by_qx[i].second;
		where_in_second[id]=i;
	}

	long long ans=0;

	for (int i=0;i<by_r.size();i++){
		int id=by_r[i].second;
		int L=x[id]-r[id];
		int R=x[id]+r[id];
		int my_iq=q[id];
		for (int iq=my_iq-k;iq<=my_iq+k;iq++){
			ans+=solver(iq,L,R);
			//cout<<solver(iq,L,R)<<" "<<iq<<" "<<L<<" "<<R<<endl;
		}
		add(where_in_second[id],1);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}