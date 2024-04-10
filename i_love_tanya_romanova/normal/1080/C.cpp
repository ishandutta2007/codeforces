/*
Bless me father
For you've sinned against me
It's been one week
since you've raped me
holy Father, your spirit inside me
Holy Father, robbed my virtue
Holy Mary, mother of Christ
The fruit of thy womb has poisoned me
Father, you're not a father
Rapist, selfish taker of youth
The fires you cast out
I promise you for eternity
Our father who aren't in heaven
Inside of me, my soul is lost
My manhood, so miniscule, was stolen
The Rosary has gripped tight around my neck
I hailed Mary...Over and over again
You've failed Mary
You've raped Mary...Over and over again
You've walked beside me, but I was alone
You've walked on top of me, crushing me
My innocence and my emotions
Were wiped away and you didn't care
You just hid behind your collar
The hardest time, I was helpless
And it was too late, much too late
Touch me I'm warm, but not alive
Feel my hot breath, but I'm not living
Dead inside, Alone forever
Father why...Father why
Father, you're not a father
Rapist, selfish taker of youth
The fires you cast out
I promise you for eternity
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

int tests;
long long n,m,x1,y1,x2,y2,x4,y4,x3,y3;
pair<long long, long long> ans;

long long get_area(long long x1,long long y1,long long x2,long long y2){
	if (x1>x2||y1>y2)
		return 0;
	return (x2-x1+1)*(y2-y1+1);
}

long long get_area(pair<pair<long long, long long>,pair<long long, long long> > p){
	return get_area(p.first.first,p.first.second,p.second.first,p.second.second);
}

pair<pair<long long, long long> ,pair<long long, long long> > get_inter(long long x1,long long y1,
		long long x2,long long y2,long long x3,long long y3,long long x4,long long y4){
	pair<pair<long long, long long> ,pair<long long, long long> > ret;
	ret.first.first=max(x1,x3);
	ret.first.second=max(y1,y3);
	ret.second.first=min(x2,x4);
	ret.second.second=min(y2,y4);
	return ret;
}

pair<long long, long long> add(pair<long long, long long> p1,pair<long long, long long> p2){
	p1.first+=p2.first;
	p1.second+=p2.second;
	return p1;
}

pair<long long, long long> sub(pair<long long, long long> p1,pair<long long, long long> p2){
	p2.first*=-1;
	p2.second*=-1;
	return add(p1,p2);
}

pair<long long, long long> trivial_calculate(long long x,long long y){
	long long white_lines=x/2+x%2;
	long long black_lines=x-white_lines;

	pair<long long, long long> ret=make_pair(0,0);

	ret.first+=white_lines*(y/2+y%2)+black_lines*(y/2);
	ret.second+=black_lines*(y/2+y%2)+white_lines*(y/2);
	return ret;
}

pair<long long, long long> calculate(long long x1,long long y1,long long x2,long long y2){
	pair<long long, long long> ret=make_pair(0,0);
	if (x1>x2||y1>y2)
		return ret;
	if (x1==1&&y1==1){
		return trivial_calculate(x2,y2);
	}
	ret=add(ret,calculate(1,1,x2,y2));
	ret=sub(ret,calculate(1,1,x1-1,y2));
	ret=sub(ret,calculate(1,1,x2,y1-1));
	ret=add(ret,calculate(1,1,x1-1,y1-1));
	return ret;
}


pair<long long, long long> calculate(pair<pair<long long, long long> ,pair<long long, long long> >p){
	return calculate(p.first.first,p.first.second,p.second.first,p.second.second);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>m;
		ans=make_pair(0,0);
		ans=add(ans,calculate(1,1,n,m));
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;

		ans=sub(ans,calculate(x1,y1,x2,y2));
		ans=sub(ans,calculate(x3,y3,x4,y4));
		ans=add(ans,calculate(get_inter(x1,y1,x2,y2,x3,y3,x4,y4)));
		ans.first+=get_area(x1,y1,x2,y2);
		ans.first-=get_area(get_inter(x1,y1,x2,y2,x3,y3,x4,y4));
		ans.second+=get_area(x3,y3,x4,y4);
		cout<<ans.first<<" "<<ans.second<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}