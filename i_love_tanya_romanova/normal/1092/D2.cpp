/*
All the love I've shown
Given to the ones I've known
All the love I make
Is equal to the love I take
All the life I've known
Given to the life I've shown
Along the way

Free from it all
Breathe in the darkest fall
We laugh and cry through a brother's eyes for now

Through fire embers glow
Haunted I lift the stone
Letting go your spirit flies

All the love I've shown
Given to the ones I've known
All the love I make
Is equal to the love I take
The light is fading fast
Be careful of the ones you left
Along the way

Free from it all
Breathe in the darkest fall
We laugh and cry through a brother's eyes for now

Through fire embers glow
Haunted I lift the stone
Letting go your spirit flies

The thorns are on the road
The thorns are on the road

In the morning light
The sparrow flies
When the moon devours us
The planet dies

Free from it all
Breathe in the darkest fall
We laugh and cry through a brother's eyes for now

Through fire embers glow
Haunted I lift the stone
Letting go your spirit flies
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,ar[N],shit;

set<pair<int,pair<int,int> > >S;
set<pair<int,pair<int,int> > >::iterator it;
int l_ptr[N],r_ptr[N];

int get_val(int ps){
	if (ps<1||ps>n)
		return 2e9;
	return ar[ps];
}

// p1 is on the left
pair<int,pair<int,int> > run_merge(pair<int,pair<int,int> > p1,pair<int,pair<int,int> >p2,int new_val){
	S.erase(p1);
	S.erase(p2);
	r_ptr[p1.second.first]=p2.second.second;
	l_ptr[p2.second.second]=p1.second.first;
	ar[p1.second.first]=ar[p2.second.second]=new_val;
	S.insert(make_pair(new_val,make_pair(p1.second.first,p2.second.second)));
	return make_pair(new_val,make_pair(p1.second.first,p2.second.second));
}

// left end
pair<int,pair<int,int> > get_pair(int ps){
	return make_pair(ar[ps],make_pair(ps,r_ptr[ps]));
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	int cur_l=1;

	for (int i=1;i<=n;i++){
		if (i>1&&ar[i]!=ar[i-1]){
			S.insert(make_pair(ar[i-1],make_pair(cur_l,i-1)));
			l_ptr[i-1]=cur_l;
			r_ptr[cur_l]=i-1;
			cur_l=i;
		}
	}
	S.insert(make_pair(ar[n],make_pair(cur_l,n)));
	l_ptr[n]=cur_l;
	r_ptr[cur_l]=n;

	while (S.size()>1){
		it=S.begin();
		pair<int,pair<int,int> > P=(*it);
		if (P.second.second%2==P.second.first%2){
			shit=1;
		}
		//cout<<P.first<<" "<<P.second.first<<" "<<P.second.second<<endl;
		//cin.get();
		int val_left=get_val(P.second.first-1);
		int val_right=get_val(P.second.second+1);
		int nw=min(val_left,val_right);
		//cout<<get_val(P.second.first-1)<<" "<<nw<<" "<<l_ptr[P.second.first-1]<<endl;
		if(get_val(P.second.first-1)==nw){
			pair<int,pair<int,int> > temp=get_pair(l_ptr[P.second.first-1]);
			//cout<<l_ptr[1]<<" "<<temp.first<<" "<<temp.second.first<<" "<<temp.second.second<<endl;
			P=run_merge(get_pair(l_ptr[P.second.first-1]),P,nw);
		}
		//cout<<get_val(P.second.second+1)<<"@"<<endl;
		//cin.get();
		if (get_val(P.second.second+1)==nw){
			run_merge(P,get_pair(P.second.second+1),nw);
		}
	}

	if (shit){
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}

	/*int cnt=0;
	for (int i=1;i<=n;i++){
		if (i>1&&ar[i]%2!=ar[i-1]%2){
			if (cnt%2)
				shit=1;
			cnt=0;
		}
		++cnt;
	}
	if (cnt%2==1&&cnt!=n)
		shit=1;

	if (shit)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
*/

//    cin.get(); cin.get();
    return 0;
}