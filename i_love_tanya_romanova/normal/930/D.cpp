/*
We were one in words
You finished my sentence
I could never attract tomorrow
It pushes me aside

I sink in waters deep
Your presence kept me floating far from depths where secrets lie
Maybe in another lifetime I can be the first you meet

I once read a poem
Held my breath but that moment's gone
First time I felt life somewhat hurts
I need an option, a reason and some hope

Yell at me, I want to be your light that shines
But my ground is shaking, and I might fall
I wish that I could say, I wish that I could be your evil in a closet

Yell at me, I want to be your light that shines
But my ground is shaking and I might fall
I wish that I could say, I wish that I could be your evil in a closet
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

int n;
struct pt{
	int x;
	int y;
};

pt normalize(pt p){
	p.x+=100000;
	p.y+=100000;
	return p;
}

pt p[N];
vector<pt> v1,v2;

struct event{
	int l;
	int r;
	int tp;
	int si;
};

event make_event(int l,int r,int tp, int si){
	event ret;
	ret.l=l;
	ret.r=r;
	ret.tp=tp;
	ret.si=si;
	return ret;
}

vector<event> events[N+31];

struct vert{
	int cnt[4];
	int with_mask[16];
};

vert t[N*4+31];

void build(int v,int tl,int tr){
	for (int i=0;i<4;i++){
		t[v].cnt[i]=0;
	}
	for (int i=0;i<16;i++)
		t[v].with_mask[i]=0;

	t[v].with_mask[0]=tr-tl+1;

	if (tl==tr)
		return;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

int Get(){
	return t[1].with_mask[15]; // t[1] itself is never full (I hope so)
}

void recombine(int v,int tl,int tr){
	int cur_mask=0;
	for (int i=0;i<4;i++){
		if (t[v].cnt[i])
			cur_mask|=(1<<i);
	}
	for (int i=0;i<16;i++){
		t[v].with_mask[i]=0;
	}
	if (tl==tr){ // leaf
		t[v].with_mask[cur_mask]=1;
		return;
	}
	for (int i=0;i<16;i++){
		int here=t[v*2].with_mask[i]+t[v*2+1].with_mask[i];
		int new_mask=(i|cur_mask);
//		cout<<v<<" "<<tl<<" "<<tr<<" "<<here<<" "<<new_mask<<endl;

		t[v].with_mask[new_mask]+=here;
	}
}

void apply(int v,int tl,int tr,event ev){
	t[v].cnt[ev.tp]+=ev.si;
	recombine(v,tl,tr);
}

void update(int v,int tl,int tr,event ev){ // return
	if (tl>=ev.l&&tr<=ev.r){
		apply(v,tl,tr,ev);
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (tm>=ev.l)
		update(v*2,tl,tm,ev);
	if (tm+1<=ev.r)
		update(v*2+1,tm+1,tr,ev);
	recombine(v,tl,tr);
}

void create_event(int x,int y,int dir){ // when scanning over (x+y -> incr), 0 and 1 are opening,
	// 2 and 3 are closing
	int xplusy=x+y; // 0.. 4e5
	int xminusy=x-y; // -2e5 .. 2e5
	xplusy/=2;
	xminusy/=2;
	xminusy+=100000;
	xplusy+=31;
	xminusy+=31;
	/*for (int i=0;i<16;i++){
		cout<<t[1].with_mask[i]<<" ";
	}
	cout<<endl;
*/
	// something like 0.. 2e5 at this point
	if (dir==0){
		events[xplusy].push_back(make_event(0,xminusy,0,1));
	}
	if (dir==1){
		events[xplusy].push_back(make_event(xminusy,N,1,1));
	}
	if (dir==2){
		events[xplusy+1].push_back(make_event(xminusy,N,2,-1));
		event temp=make_event(xminusy,N,2,1);
		update(1,0,N,temp);
	}
	if (dir==3){
		events[xplusy+1].push_back(make_event(0,xminusy,3,-1));
		event temp=make_event(0,xminusy,3,1);
		update(1,0,N,temp);
	}
}

void show_event(event ev){
	cout<<ev.l<<" "<<ev.r<<" "<<ev.tp<<" "<<ev.si<<endl;
	cout<<endl;
}

long long solve(vector<pt> v){ // 0.. 2e5 coords at this point, non-rotated, same parity
	if (v.size()==0)
		return 0;
	if (v[0].x%2==v[0].y%2){ // making different parity by shifting axis -
		// since we want to have same parity after +-1 shit
		for (int i=0;i<v.size();i++)
			v[i].x+=1;
	}
	// 0.. 2e5+1 at this point

	build(1,0,N);
	for (int i=0;i<N;i++){
		events[i].clear();
	}

	for (int i=0;i<v.size();i++){
		create_event(v[i].x+1,v[i].y,1);
		create_event(v[i].x,v[i].y+1,0);
		create_event(v[i].x-1,v[i].y,3);
		create_event(v[i].x,v[i].y-1,2);
	}

	/*for (int i=0;i<4;i++){
		event temp=make_event(0,N,i,1);
		update(1,0,N,temp);
	}*/

	long long ans=0;

	for (int i=0;i<N;i++){
		for (int j=0;j<events[i].size();j++){
		//	cout<<i<<"@ ";
		//	show_event(events[i][j]);
			update(1,0,N,events[i][j]);
		}
		/*if (i>=0&&i<=10){
			cout<<"@@@"<<i<<endl;
			for (int j=0;j<16;j++){
				cout<<j<<" "<<t[1].with_mask[j]<<endl;
			}
		}*/

		ans+=Get();
	}
	return ans;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		p[i]=normalize(p[i]);
		if (p[i].x%2==p[i].y%2)
			v1.push_back(p[i]);
		else
			v2.push_back(p[i]);
	}

//	cout<<v1.size()<<"@"<<v2.size()<<endl;

	cout<<solve(v1)+solve(v2)<<endl;

//	cin.get(); cin.get();
	return 0;
}