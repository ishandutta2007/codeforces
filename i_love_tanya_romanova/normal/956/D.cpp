/*
We are delusional
To go against mortality
Still we fight, love and create
As the only creatures
In on life's grand secret
We sense the pointlessness beyond

There is a void between our hands
That drown the sounds of night
An arrow laced with liquid darkness
For every sungods heart

It has always been right here
Like a shadow in our blood
It waits for you and me
The shadow in our blood

We are delusional
From fictional reality
To prayers for prosperity
Loneliness
Can we resist your pale attraction
Give in to the dream with open eyes

How will this world within a world live on
Another page torn from the book of strangers
Who says "I" when all voices fear their own sound
And who remembers the hours

It has always been right here
Like a shadow in our blood
It waits for you and me
The shadow in our blood

Here in the barren and still
Far from the shores of real
Dreams borne beyond borders
On weave of thought and want
Here were invincible

It has always been right here
Like a shadow in our blood
It waits for you and me
The shadow in our blood
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

const int N = 400031;

int t[N*4];
int n,W;
int x[N],w[N];
vector<int> order;

long long ans;

int ps_in_first[N];

void add(int v,int tl,int tr,int ps,int val){
	if (tl==tr)
	{
		t[v]+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	t[v]=t[v*2]+t[v*2+1];
}

int get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}

int WIND_SPEED;

bool same_at_zero(int a,int b){
	int cur_speed_a=w[a]+WIND_SPEED;
	int cur_speed_b=w[b]+WIND_SPEED;
	int cur_ps_a=x[a];
	int cur_ps_b=x[b];
	return 1ll*cur_speed_a*cur_ps_b==1ll*cur_speed_b*cur_ps_a;
}

bool cmp(int a,int b){ // check if time to get to zero is smaller for a
	if (same_at_zero(a,b))
		return false;
	long double cur_speed_a=w[a]+WIND_SPEED;
	long double zero_for_a=-(x[a]/cur_speed_a);
	long double cur_speed_b=w[b]+WIND_SPEED;
	long double zero_for_b=-(x[b]/cur_speed_b);
	return zero_for_a<zero_for_b;
}


vector<vector<int> > get_split(vector<int> v){
	vector<vector<int> > ret;
	vector<int> cur;
	for (int i=0;i<v.size();i++){
		if (cur.size()>0&&same_at_zero(v[i],cur.back())){
			cur.push_back(v[i]);
		}
		else{
			ret.push_back(cur);
			cur.clear();
			cur.push_back(v[i]);
		}
	}
	if (cur.size())
		ret.push_back(cur);
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>W;

	for (int i=1;i<=n;i++){
		cin>>x[i]>>w[i];
		order.push_back(i);
	}

	WIND_SPEED=-W;

	sort(order.begin(),order.end(),cmp);

	vector<vector<int> > V=get_split(order);

	int cnt=0;

	if (W==0){
		for (int i=0;i<V.size();i++){
			int sz=V[i].size();
			ans+=1ll*sz*(sz-1)/2;
		}
		cout<<ans<<endl;
		return 0;
	}

	for (int i=0;i<V.size();i++){
		for (int j=0;j<V[i].size();j++)
			ps_in_first[V[i][j]]=cnt;
		cnt+=V[i].size();
		int sz=V[i].size();
		ans+=1ll*sz*(sz-1)/2;
	}

	WIND_SPEED=W;

	sort(order.begin(),order.end(),cmp);

	V=get_split(order);

	for (int i=0;i<V.size();i++){
		for (int j=0;j<V[i].size();j++){ // add groups strictly after in first,
											//which are strictly before in second
			int id=V[i][j];
			ans+=get(1,0,n,ps_in_first[id]+1,n);
		}
		int sz=V[i].size();
		ans+=1ll*sz*(sz-1)/2;
		for (int j=0;j<V[i].size();j++){
			int id=V[i][j];
			add(1,0,n,ps_in_first[id],1);
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}