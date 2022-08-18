/*
We sail through endless skies
Stars shine like eyes
The black night sighs
The Moon in silver dreams
Falls down in beams
Light of the night
The Earth a purple blaze
Of sapphire haze
In orbit always

While down below the trees
Bathed in cool breeze
Silver starlight breaks
Dawn from night
And so we pass on by
The crimson eye
Of great god Mars
As we travel the universe
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

const int N = 200031;

int n;
string st;
int ar[N];
int cnt;
int ans;
int L[N],R[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>st;
	for (int i=1;i<=n;i++){
		ar[i]=(st[i-1]=='G');
		cnt+=ar[i];
	}

	for (int i=1;i<=n;i++){
		L[i]=L[i-1]+1;
		if (ar[i]==0)
			L[i]=0;
	}

	for (int i=n;i>=1;--i){
		R[i]=R[i+1]+1;
		if (ar[i]==0)
			R[i]=0;
	}

	for (int i=1;i<=n;i++){
		ans=max(ans,L[i]);
		ans=max(ans,L[i-1]+R[i+1]+1);
	}
	ans=min(ans,cnt);
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}