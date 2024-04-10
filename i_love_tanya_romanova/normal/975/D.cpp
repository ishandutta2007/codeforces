/*
Call me by my astral name
Breeding fear through wordless tongue
Heavenly thirst - unspeakable pain
Emptied from all human motion
Confront the faceless wrath

Beckoning silent from a sphere behind space
Through twisted ruins of uncompleted dreams
Sights of towers reaching for the moon
Clawing at the skies - they gonna pull it down

Intensity - I feel the lava rushing through my veins
Stars are reforming - to enter the fourth dimension

Beyond all galaxies
Through timeless aeons of frost
Unearthly hunger - angels descent

We are entering dimensions behind space
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

const int N = 300031;

int n,a,b;
long long x[N],vx[N],vy[N],ans;

vector<pair<long long, long long> > order;

map<long long, long long> cnt;

void add_item(int id){
	long long here=a*vx[id]-vy[id];
	cnt[here]++;
}

long long solver(int id){
	long long V=a*vx[id]-vy[id];
	return cnt[V];
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>a>>b;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>vx[i]>>vy[i];
		order.push_back(make_pair(vx[i],i));
	}

	sort(order.begin(),order.end());
	for (int i=0;i<order.size();i++){
		if (i>0&&order[i].first!=order[i-1].first){
			int j=i-1;
			while (j>=0&&order[j].first==order[i-1].first){
				add_item(order[j].second);
				--j;
			}
		}
		ans+=solver(order[i].second)*2;
	}

	/*for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if ((vx[i]-vx[j])==a*(vy[i]-vy[j])&&vx[i]!=vx[j]){
				ans+=2;
				cout<<i<<"%"<<j<<endl;
			}
		}
	}*/
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}