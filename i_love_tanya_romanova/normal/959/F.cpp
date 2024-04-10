/*
Uh-oh!

Carry our streams
Lift up our less than elated lives
Transmit our selves
We breathe out
Where no one
Take in all the dark light
Turn the nighttime into day
Take in all the dark light
Turn the nighttime into day

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

Uh-oh!

Alienate
Block out all
Amid the breaking of the light
See it again and again
Single sight

Sensory perception
Turn the nighttime into day
Sensory perception
Turn the nighttime into day

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

To our great distrust
Escapism a means of getting through alive
Take it in and spit it out again
That measly filth

Focal degradation
Bring the chaos into light
Cathode ray Sunshine
Burn
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

vector<int> entries[N];
int l[N],x[N];
int n,tests;
int ar[N];
vector<int> basis,temp_basis;
int ans[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

int get_high(int val){
	for (int i=20;i>=0;--i){
		if (val&(1<<i))
			return i;
	}
	return -1;
}

vector<int> add_basis(vector<int> basis,int val){
	for (int i=0;i<basis.size();i++){
		int Q=get_high(basis[i]);
		if (val&(1<<Q)){
			val^=basis[i];
		}
	}
	if (val!=0){
		basis.push_back(val);
		sort(basis.begin(),basis.end());
		reverse(basis.begin(),basis.end());
	}
	return basis;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>tests;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for (int test=1;test<=tests;test++){
		cin>>l[test]>>x[test];
		entries[l[test]].push_back(test);
	}

	for (int i=1;i<=n;i++){
		basis=add_basis(basis,ar[i]);
		for (int j=0;j<entries[i].size();j++){
			int test_id=entries[i][j];
			temp_basis=add_basis(basis,x[test_id]);
			if (temp_basis.size()!=basis.size()){ // independent
				ans[test_id]=0;
			}
			else
			{
				ans[test_id]=pw(2,i-basis.size());
			}
		}
	}

	for (int i=1;i<=tests;i++){
		cout<<ans[i]<<"\n";
	}

//	cin.get(); cin.get();
	return 0;
}