/*
Clouds roll by
Reeling is what they say
Or is it just my way?
Wind blows by, low light
Side-tracked, low light
Can't see my tracks, your scent-way back

Can I be here all alone?
Clear a path to my home
Blood runs dry
Books and jealousy tell me wrong
All I feel, calm
Voice blows by, low light
Car crash, low light
Can't wear my mask, your first, my last

Voice goes by
Two birds is what they'll see
Getting lost upon their way
Wind rolls by, low light
Eye sight, low light
I need the light
I'll find my way from wrong, what's real?
The dream I see
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

int n;
vector<int> ans;

int get_sum(int x){
	if (x==0)
		return x;
	return get_sum(x/10)+x%10;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=200;i++){
		if (n-i<=0)
			continue;
		int candidate=n-i;
		if (candidate+get_sum(candidate)==n)
			ans.push_back(candidate);
	}

	sort(ans.begin(),ans.end());

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}

	cin.get(); cin.get();
	return 0;
}