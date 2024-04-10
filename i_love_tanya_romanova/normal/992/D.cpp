/*
It is the evening of the day
I sit and watch the children play
Smiling faces I can see
But not for me
I sit and watch
As tears go by
My riches can't buy everything
I want to hear the children sing
All I hear is the sound
Of rain falling on the ground
I sit and watch
As tears go by
It is the evening of the day
I sit and watch the children play
Doin' things I used to do
They think are new
I sit and watch
As tears go by
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

const int N = 1200031;

long long n,k,ar[N];
long long S[N];

long long INF = 3e18;

vector<int> nonzero;

int next_big[N];

long long pref[N];
long long ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		if (ar[i]>1)
			nonzero.push_back(i);
		pref[i]=pref[i-1]+ar[i];
	}

	ar[n+1]=2;

	for (int i=1;i<=n+1;i++){
		if (ar[i]>1){
			for (int j=i-1;j>=0;--j){
				next_big[j]=i;
				if (ar[j]>1)
					break;
			}
		}
	}

	/*for (int i=1;i<=n;i++){
		cout<<next_big[i]<<" ";
	}
	cout<<endl;
*/
	for (int l=1;l<=n;l++){
		long long prod=1;
		long long S=0;
		int r=l-1;

		for (int iter=1;iter<=77;iter++){
			//cout<<l<<" "<<r<<" "<<prod<<" "<<S<<endl;

			int next_cut=next_big[r];
			if (prod%k==0){
				long long should_be=prod/k;
				long long max_S=S+(next_cut-r-1);
				if (max_S>=should_be&&S<=should_be)
					++ans;
			}
			if (next_cut>n)
				break;
			//cout<<next_cut<<endl;
			if (INF/ar[next_cut]<=prod)
				break;
			S=pref[next_cut]-pref[l-1];
			prod*=ar[next_cut];
			r=next_cut;
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}