/*
To remain objective
To a closer call, uh
Secretly rejected
And to mediocrity fall
Caught on the down lopes of life

The patted shoulder remembers
The elbowed side resists
Encircled ad nauseum
An enemy to define ourselves
An enemy to refine our hate

Encouraging on the negative scale, uh
Bent out of shape is the measuring norm
In words and in writing
No one knows my enemy like I do

A social repellant
Merely an adversary
Lost to the falling words
Kept the last of all
Understood glances
To work against

The patted shoulder remembers
The elbowed side resists
Encircled ad nauseum

An enemy to define ourselves
An enemy to refine our hate
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

#define bs 1000000007

const int N = 100031;

string st;

int n,m;
long long ans;

long long solver(long long ps){
	long long res=0;
	for (int i=1;i<=n;i++){
		res+=abs(ps-i);
	}
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;

	long long Q1=solver(1);
	long long Q2=solver((n+1)/2);

	for (int i=1;i<=m;i++){
		long long a,b;
		cin>>a>>b;
		ans+=a*n;
		ans+=max(Q1*b,Q2*b);
	}

	cout.precision(12);

	cout<<fixed<<ans*1.0/n<<endl;

//	cin.get(); cin.get();
	return 0;
}