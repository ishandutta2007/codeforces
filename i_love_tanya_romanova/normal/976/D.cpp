/*
Join in my quest to leave life overturned
Spanning the world wave of doom
Spewing out death with the evil I've churned
Awaken the dead from their tombs
Love turns to lust the sensations I've felt
Exploring the pleasures of sin
Making the best of the cards I've been dealth
Adjusting the odds so I win

Unleash all my burning wrath
Potential killing machine
Take down all who block my path
Enjoying all that's obscene... born of fire

Prince of all darkness initiation
Ritually baptized in flames
Next to the throne my abomination
Spreads horror throughout the domain
Master the art that controls the impure
Inherit the infamous keys
Thousands of centuries I will endure
Tyrant of all the prophecies

Some have called me Satan's son
A name I cannot deny
Wielding fury that's second to none
Far to vile to confine... born of fire

All things dead must rise again
When twilight's blanket falls
Splattered red you'll find my den
Blood dripping from the walls

Dreams born of desire
Shaped and forged within the fire
Twisted, warped, deranged I see
The world's corrupt insanity

Dreams possess nightmarish figures
Burning can't escape the embers
Lost are those who trust the Liar
Satan's son I'm born of fire
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

int n;
vector<pair<int,int> > v;
int d[N];
vector<pair<int,int> > ans;

int cnt[N],rem;

int ptr,deg[N];
vector<pair<int,int> > order;
int dd[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>d[i];
		dd[i]=d[i];
	}

	int l,r;
	l=1;
	r=n;
	rem=d[n]+1;
	while (l<=r){

		if (l==r){
			cnt[l]=cnt[r]=d[l]+1;
			//cout<<l<<"@"<<r<<" "<<d[l]<<endl;
		}
		else
		{
			cnt[r]=d[l];
			//cout<<l<<" "<<r<<" "<<d[l]<<endl;

			for (int i=l;i<=r;i++){
				d[i]-=cnt[r];
			}
			rem-=cnt[r];
			int ohead=rem-(d[r-1]+1);
			if (l+1==r)
				ohead++;
			//cout<<l<<"@"<<r<<" "<<ohead<<" "<<d[r-1]<<" "<<cnt[r]<<endl;
			cnt[l]=ohead;
			rem=d[r-1]+1;
		}
		++l;
		--r;
	}
	/*for (int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
*/

	for (int i=1;i<=n;i++){
		for (int j=1;j<=cnt[i];j++){
			++ptr;
			deg[ptr]=dd[i];
		}
	}

	/*for (int i=1;i<=ptr;i++){
		cout<<deg[i]<<" ";
	}
	cout<<endl;
*/
	for (int iter=1;iter<=ptr;iter++){
		order.clear();
		for (int i=1;i<=ptr;i++){
			order.push_back(make_pair(deg[i],i));
		}
		sort(order.begin(),order.end());
		reverse(order.begin(),order.end());
		for (int i=1;i<=order[0].first;i++){
			int a=order[0].second;
			int b=order[i].second;
			deg[a]--;
			deg[b]--;
			ans.push_back(make_pair(a,b));
		}
	}

	printf("%d\n",(int)ans.size());

	for (int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
//	cin.get(); cin.get();
	return 0;
}