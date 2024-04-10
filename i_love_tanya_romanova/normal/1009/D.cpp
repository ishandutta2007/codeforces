/*
Could not have foreseen
What the lies of the bearer would bring
Trailing the marks of his errors
Trace the original sin

Fallen I cling to deception
This talk of madness is in me
Come now as the drapery falls

From homes that take the foul in hand
Mind cloven Sweet spoken
With words that led us off the track
Truth altered blind-sighted, oh

Thrive on the illusion
And the image of a life to be
Unmount the shielding facade

Fallen I cling to deception
This talk of madness is in me
Come now as the drapery falls

Uh-I!

Fallen I cling to deception

Endure the spit of others
Locked inside the pretence cage
Where the cause will be certain
Fallen I'll see you inside
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

int n,m;
vector<pair<int,int> > ans;

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	if (m+1<n){
		cout<<"Impossible"<<endl;
		return 0;
	}

	for (int i=1;i<n;i++){
		ans.push_back(make_pair(i,i+1));
		--m;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+2;j<=n;j++){
			if (m==0)
				break;
			if (gcd(i,j)==1){
				ans.push_back(make_pair(i,j));
				--m;
			}
		}
	}

	if (m){
		cout<<"Impossible"<<endl;
		return 0;
	}

	cout<<"Possible"<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}