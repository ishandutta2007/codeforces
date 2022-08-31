/*
I know you thought you're a real operator
But I don't know why
All you had was a bankroll, babe
And a glint in your eye
I'm a high-steppin' like an indian brave
I'm the one
Dancing on your grave

You know I'm a killer babe
Here's late news for you
You couldn't buy me with a million, babe
I'm too good for you
I'm know you think I'm real rough trade
Now I'm the one
Dancing on your grave

One time you was a real high-stepper
On the high trapeze
But you know you ran out of money
Wound up on your knees
I'm the one you never made
Now I'm the one
Dancing on your grave
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

int n,k,x;
long long ans;
map<int,int> cnt,C;
map<int,int>::iterator it;

int ar[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>x>>k;

	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
		cnt[ar[i]]++;
	}

	for (it=cnt.begin();it!=cnt.end();it++){
		int val=(*it).first;
		int am=(*it).second;
		int below_incl=val/x;
		int need=below_incl-k;
		//cout<<below_incl<<" "<<need<<endl;

		ans+=C[need]*1ll*am;
		int below=(val-1)/x;
		C[below]+=am;
		if (k==0&&val%x!=0)
			ans+=1ll*am*am;
		if (k==1&&val%x==0)
			ans+=1ll*am*am;
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}