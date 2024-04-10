/*
Momma loves her baby
And Daddy loves you too
And the sea may look warm to you, babe
And the sky may look blue

Ooh, babe
Ooh, baby blue
Ooh, babe

If you should go skating
On the thin ice of modern life
Dragging behind you the silent reproach
Of a million tear-stained eyes

Don't be surprised,
When a crack in the ice
Appears under your feet
You slip out of your depth and out of your mind
With your fear flowing out behind you
As you claw the thin ice
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

const int N = 600031;

int n;
set<int> low,unknown,high;
set<int>::iterator it;

int get_lowest_in_high(){
	if (high.size()==0)
		return 1e9;
	it=high.begin();
	return (*it);
}

int get_highest_in_low(){
	if (low.size()==0)
		return -1e9;
	it=low.end();
	--it;
	return (*it);
}

int solve(){

	int ans=1;

	for (int i=1;i<=n;i++){
		string tp;
		int price;
		cin>>tp>>price;
		if (tp=="ADD"){
			int highest_in_low=get_highest_in_low();
			int lowest_in_high=get_lowest_in_high();
			if (price<highest_in_low){
				low.insert(price);
			}
			else if (price>lowest_in_high){
				high.insert(price);
			}
			else
			{
				unknown.insert(price);
			}
		}
		else
		{
			if (high.find(price)!=high.end()&&get_lowest_in_high()<price)
				return 0;
			if (low.find(price)!=low.end()&&get_highest_in_low()>price)
				return 0;

			if (high.find(price)!=high.end())
				high.erase(price);
			if (low.find(price)!=low.end())
				low.erase(price);
			if (unknown.find(price)!=unknown.end()){
				unknown.erase(price);ans=(ans*2)%bs;
			}
			while (unknown.size()>0){
				int val=(*unknown.begin());
				unknown.erase(val);
				if (val<price)
					low.insert(val);
				else
					high.insert(val);
			}
		}
	}

	ans=1ll*ans*(unknown.size()+1)%bs;
	return ans;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	cout<<solve()<<endl;

//	cin.get(); cin.get();
	return 0;
}