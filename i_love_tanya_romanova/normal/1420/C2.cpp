/*
Running my way towards oblivion
Inside my head electric insomnia
In your mind i'm fed with distrust
Heading for anything better than this

I want to be forgotten
I want you to forgive
How i'm losing all this
It's just the way i live

Running my way towards oblivion
Inside my head smokescreen's gone
Leaving all this to be undone
Heading for anything better than this

Running my way towards oblivion
Outside my head only the dark
In your mind i'm the end of it all
Heading for anything better than this
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

int tests;
int n,q,ar[N];
long long sum_of_min,sum_of_max;
set<int> maxi,mini;
set<int>::iterator it;

bool is_min(int ps){
	if (n==1)
		return false;
	if (ps>1&&ar[ps]>ar[ps-1])
		return false;
	if (ps<n&&ar[ps]>ar[ps+1])
		return false;
	return true;
}

bool is_max(int ps){
	if (ps>1&&ar[ps]<ar[ps-1])
		return false;
	if (ps<n&&ar[ps]<ar[ps+1])
		return false;
	return true;
}

int get_first_min()
{
	if (mini.size()==0)
		return 1e9;
	it=mini.begin();
	return (*it);
}

int get_first_max(){
	if (maxi.size()==0)
		return 1e9;
	it=maxi.begin();
	return *it;
}

int get_last_max(){
	if (maxi.size()==0)
		return -1;
	it=maxi.end();
	--it;
	return (*it);
}

int get_last_min(){
	if (mini.size()==0)
		return -1;
	it=mini.end();
	--it;
	return *it;
}

long long eval(){
	long long baseline=sum_of_max-sum_of_min;
	int fi_min=get_first_min();
	int fi_max=get_first_max();
	if (fi_min<fi_max)
	{
		int ps=fi_min;
		baseline+=ar[ps];
	}
	int la_min=get_last_min();
	int la_max=get_last_max();
	if (la_min>la_max){
		int ps=la_min;
		baseline+=ar[ps];
	}
	return baseline;
}

int minimap[N],maximap[N];

void reconsider(int ps){
	if (ps<1||ps>n)
		return ;
	if (mini.find(ps)!=mini.end()){
		sum_of_min-=minimap[ps];
		mini.erase(ps);
	}
	if (maxi.find(ps)!=maxi.end()){
		sum_of_max-=maximap[ps];
		maxi.erase(ps);
	}
	if (is_min(ps)){
		mini.insert(ps);
		sum_of_min+=ar[ps];
		minimap[ps]=ar[ps];
	}
	if (is_max(ps)){
		maxi.insert(ps);
		sum_of_max+=ar[ps];
		maximap[ps]=ar[ps];
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cin>>q;
    	for (int i=1;i<=n;i++){
//    		cin>>ar[i];
    		scanf("%d",&ar[i]);
    	}

    	maxi.clear();
    	mini.clear();
    	sum_of_max=0;
    	sum_of_min=0;

    	for (int i=1;i<=n;i++){
    		if (is_max(i))
    			maxi.insert(i),
				maximap[i]=ar[i],
				sum_of_max+=ar[i];
    		if (is_min(i))
    			mini.insert(i),
				minimap[i]=ar[i],
				sum_of_min+=ar[i];
    	}

//    	cout<<eval()<<endl;
    	printf("%lld\n",eval());
    	for (;q;--q){
    		int l,r;
//    		cin>>l>>r;
    		scanf("%d",&l);
    		scanf("%d",&r);
    		swap(ar[l],ar[r]);
    		reconsider(l-1);
    		reconsider(l);
    		reconsider(l+1);
    		reconsider(r-1);
    		reconsider(r);
    		reconsider(r+1);
    		printf("%lld\n",eval());
//    		cout<<eval()<<"\n";
    	}
    }

    //cin.get(); cin.get();
    return 0;
}