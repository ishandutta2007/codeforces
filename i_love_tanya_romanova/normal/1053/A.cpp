/*
The sinners masquerade
An asylum for the weak
A feast for the wolf
Our faces lost in the deep
Empty space our souls to keep

The hour of twilight
As silent as sin
Drifting beyond dreaming
Erasing all therein
Into black nightmare
Cry in vain
The eyes set sail
Towards ebony rain

The mirror cease to live
Images all gone
Cutting through our hearts
A slice of ended life
Will our memories stain the knife
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

long long n,m,k;
vector<long long> divsa,divsb;

long long ansa,ansb;

bool found;

void tryy(long long a,long long b){
	if (a>n||b>m)
		return;
	if (a*b*k!=n*m*2)
		return;
	found=1;
	ansa=a;
	ansb=b;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;

	for (int i=1;i*i<=n;i++){
		if (n%i==0){
			divsa.push_back(i);
			divsa.push_back(n/i);
		}
	}

	for (int i=1;i*i<=m;i++){
		if (m%i==0){
			divsb.push_back(i);
			divsb.push_back(m/i);
		}
	}

	for (int i=0;i<divsa.size();i++){
		for (int j=0;j<divsb.size();j++){
			tryy(divsa[i],divsb[j]);
			tryy(divsa[i]*2,divsb[j]);
			tryy(divsa[i],divsb[j]*2);
			tryy(divsa[i]*2,divsb[j]*2);
		}
	}

	if (!found){
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		cout<<"0 "<<ansb<<endl;
		cout<<ansa<<" 0"<<endl;
	}
//	cin.get(); cin.get();
	return 0;
}