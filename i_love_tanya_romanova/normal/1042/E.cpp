/*
Like the poison running through your veins
You're addicted to the pain and the shame
Chasing the same game every day
Hooked on all your bullshit and your vanity

Blind decisions, no regrets
A bittersweet of toxic sweat

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, you're gonna say my name

A normal situation in disguise
Dragging me through your self-inflicted lies
Too bad you're never gonna win this game
Your misery's your only friend and you're to blame

Blind decisions, no regrets
A bittersweet of toxic sweat

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, you're gonna say my name

Bringing everybody down, down, down and turn it around
Into the same game, twisting it upside down
Another go around, you're gonna say my name
It's gonna come around... yeah!
Bringing everybody down, down, down and turn it around
Into the same game, twisting it upside down
Another go around, you're gonna say my name
You're gonna say my name, say my name

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, bitch! Say my name
You know you're gonna say my name
Oh, say my name
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

#define bs 998244353

const int N = 600000;

int n,m;
int ar[1031][1031];
vector<pair<int,pair<int,int> > > order;
vector<pair<int,pair<int,int> > > update_list;
int ans[1031][1031];

long long sum_of_x;
long long sum_of_y;

long long sum_of_squared_x;
long long sum_of_squared_y;

long long cnt_done;

long long sum_of_ans;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv (long long x){
	return pw(x,bs-2);
}

void update(int x,int y,int val){

	cnt_done++;

	sum_of_ans+=val;
	sum_of_ans%=bs;

	sum_of_x+=x;
	sum_of_x%=bs;

	sum_of_y+=y;
	sum_of_y%=bs;

	sum_of_squared_x+=1ll*x*x%bs;
	sum_of_squared_x%=bs;

	sum_of_squared_y+=1ll*y*y%bs;
	sum_of_squared_y%=bs;

	ans[x][y]=val;
}

int process(int x,int y){
	long long res=0;
	res+=sum_of_ans;
	res+=x*x%bs*cnt_done;
	res+=y*y%bs*cnt_done;
	res+=sum_of_squared_x;
	res+=sum_of_squared_y;
	res%=bs;

	res-=2*sum_of_x*x%bs;
	res-=2*sum_of_y*y%bs;
	res%=bs;
	if (res<0)
		res+=bs;
	if (cnt_done==0)
		res=0;
	else
		res=res*inv(cnt_done);
	res%=bs;
	return res;
}

void run_update(){
	for (int i=0;i<update_list.size();i++){
		update(update_list[i].second.first,update_list[i].second.second,update_list[i].first);
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>ar[i][j];
			order.push_back(make_pair(ar[i][j],make_pair(i,j)));
		}
	}

	sort(order.begin(),order.end());

	for (int i=0;i<order.size();i++){
		if (i>0&&order[i].first!=order[i-1].first){
			run_update();
			update_list.clear();
		}
		int here=process(order[i].second.first,order[i].second.second);
		//cout<<here<<endl;
		update_list.push_back(make_pair(here,order[i].second));
	}

	run_update();

	int a,b;
	cin>>a>>b;
	cout<<ans[a][b]<<endl;


//	cin.get(); cin.get();
	return 0;
}