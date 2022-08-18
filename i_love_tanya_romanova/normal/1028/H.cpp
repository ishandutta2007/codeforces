/*
Leave when I ask you to leave, Lucy
Please fall away from me, Lucy
Oh, go, little girl

See that I'm so broken up about you, Lucy
Mean treatin' me and done me harm, Lucy
Been in love with you and your charms, Lucy
Oh, go, little girl

I'm in love with you, Lucy
You got my heart, you got my heart, oh no
You tear me apart, you just won't let me go
You hold on so tight, so tight I just can't breathe
Now Lucy leave, Lucy

Leave when I ask you to leave, little girl
Please fall away from me, little girl
Yeah, go, little girl

See that I'm so broke up about you, Lucy
Yeah, girl
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

const int MX = 6000000;

const int N = 200000;

const int Q = 1200000;

int n,tests;

int pr[MX];
int ar[N];

int last_entry[MX][8];

int le[N][15];

vector<pair<int,int> > events[N];
vector<int> queries[N];

int t[N*4];

int ans[Q];

void build(int v,int tl,int tr){
	t[v]=1e9;
	if (tl==tr){
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

int get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 1e9;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return min(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int ps,int val)
{
	if (tl==tr){
		t[v]=min(t[v],val);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=min(t[v*2],t[v*2+1]);
}

vector<int> get_primes(int val){
	vector<int> ret;
	while (val>1){
		int x=pr[val];
		int cnt=0;
		while (val%x==0){
			val/=x;
			cnt++;
		}
		if (cnt%2)
			ret.push_back(x);
	}
	return ret;
}

int l[Q],r[Q];

int naive(int l,int r){
	int res=1e9;
	for (int i=l;i<=r;i++){
		for (int j=0;j<15;j++){
			if (le[i][j]>=l)
				res=min(res,j);
		}
	}
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	// 2*3*5*7*11*13*17 -> 5e5; *19 is overflow, so <=7 bits
	scanf("%d",&n);
	scanf("%d",&tests);

	pr[1]=1;
	for (int i=2;i<MX;i++){
		if (pr[i]==0){
			for (int j=i;j<MX;j+=i){
				pr[j]=i;
			}
		}
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
	}

	for (int i=1;i<MX;i++){
		for (int j=0;j<=7;j++){
			last_entry[i][j]=-1;
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=0;j<=15;j++){
			le[i][j]=-1;
		}

		vector<int> v=get_primes(ar[i]);

		// get
		for (int mask=0;mask<(1<<v.size());mask++){
			int val=1;
			int pc=0;
			for (int j=0;j<v.size();j++){
				if (mask&(1<<j)){
					val*=v[j];
					pc++;
				}
			}
			for (int q=pc;q<=7;q++){
				if (last_entry[val][q]==-1)
					continue;
				int cost=q+v.size()-2*pc;
				le[i][cost]=max(le[i][cost],last_entry[val][q]);
			}
		}

		// update
		for (int mask=0;mask<(1<<v.size());mask++){
			int val=1;
			int pc=0;
			for (int j=0;j<v.size();j++){
				if (mask&(1<<j)){
					val*=v[j];
					pc++;
				}
			}
			last_entry[val][v.size()]=i;
		}
	}

	/*for (int i=1;i<=n;i++){
		for (int j=0;j<15;j++){
			cout<<le[i][j]<<" ";
		}
		cout<<endl;
	}*/

	for (int test=1;test<=tests;test++){
		scanf("%d",&l[test]);
		scanf("%d",&r[test]);
	//	printf("%d\n",naive(l[test],r[test]));
	}

	for (int i=1;i<=n;i++){
		for (int j=0;j<15;j++){
			if (le[i][j]!=-1){
				int ps=le[i][j];
				events[ps].push_back(make_pair(i,j));
			}
		}
	}

	for (int i=1;i<=tests;i++){
		queries[l[i]].push_back(i);
	}

	build(1,1,n);

	for (int i=n;i>=1;--i){
		for (int j=0;j<events[i].size();j++){
			int ps=events[i][j].first;
			int val=events[i][j].second;
			update(1,1,n,ps,val);
		}
		for (int j=0;j<queries[i].size();j++){
			int id=queries[i][j];
			int here=get(1,1,n,l[id],r[id]);
			ans[id]=here;
		}
	}

	for (int i=1;i<=tests;i++){
		printf("%d\n",ans[i]);
	}

//	cin.get(); cin.get();
	return 0;
}