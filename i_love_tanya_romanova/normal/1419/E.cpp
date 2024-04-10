/*
I'm drowning in the bottom of a bottle
Running from a man I swore I'd never be
No one ever has to face tomorrow
But I'm the one that has to face me

It's the demons I've created for myself
The tragic truth
It's hard for me to understand myself
So it has to be hard as hell for you
For you

Are we born to be broken, sinners, and thieves
Someone tell the heavens I'm ready to escape
This is not what I wanted not what I need
Take it all tear it all
Rip it all away

I can't say the Devil made me do it
I chose to be the one I am, the way I am today
I wish there was but there's no way around it
In the end I made the choice and will not die ashamed
It's the voices screaming in my head
The tragic truth
It's hard for me to understand myself
So it has to be hard as hell for you
You

Are we born to be broken, sinners, and thieves
Someone tell the heavens I'm ready to escape! (You!)
This is not what I wanted not what I need
Take it all, tear it all, rip it all away!
Take it all, tear it all, take it all, tear it all away!

Are we born to be broken, sinners, and thieves?
Someone tell the heavens I'm ready to escape! (You!)
This is not what I wanted not what I need!
Take it all, tear it all, rip it all away! (Away!)

Are we born to be broken, sinners, and thieves?
Someone tell the heavens I'm ready to escape! (You!)
This is not what I wanted not what I need!
Take it all, tear it all, rip it all away!
Take it all, tear it all, rip it all, tear it all! (It all away)
Someone tell the heavens to take it all, tear it all away!
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

#define bs 1000000007

const int N = 100031;

int tests,n;
vector<int> primes;
vector<int> ans;
int BAN;
vector<int> divs;
int GLOBAL_BAN;

vector<int> get_primes(int n){
	vector<int> ret;
	for (int i=2;i*i<=n;i++){
		if (n%i)
			continue;
		ret.push_back(i);
		while (n%i==0)
			n/=i;
	}
	if (n>1)
		ret.push_back(n);
	return ret;
}

int get_mask(int val){
	int ret=0;
	for (int i=0;i<primes.size();i++){
		if (val%primes[i]==0)
			ret|=(1<<i);
	}
	return ret;
}

void filter_it(int mask){
	for (int i=0;i<divs.size();i++){
		if (get_mask(divs[i])==mask)
			ans.push_back(divs[i]);
	}
}

int OLD_BAN;

void filter_everything(int val){
	vector<int> new_leftovers;
	for (int i=0;i<divs.size();i++){
		if (divs[i]==val||divs[i]==BAN||divs[i]%val>0||divs[i]==OLD_BAN){
			new_leftovers.push_back(divs[i]);
			continue;
		}
		else{
			ans.push_back(divs[i]);
		}
	}
	divs=new_leftovers;
}

set<int> seen;

void generate_divs(int val){
	if (seen.find(val)!=seen.end())
		return;
	seen.insert(val);
	if (val>1)
		divs.push_back(val);
	for (int i=0;i<primes.size();i++){
		if (n%(1ll*val*primes[i]))
			continue;
		generate_divs(val*primes[i]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		primes=get_primes(n);
		seen.clear();
		divs.clear();
		generate_divs(1);

		if (primes.size()==1){
			for (int i=0;i<divs.size();i++){
				if (i)
					cout<<" ";
				cout<<divs[i];
			}
			cout<<endl;
			cout<<0<<endl;
			continue;
		}

		if (primes.size()==2){
			if (divs.size()==3){
				cout<<primes[0]<<" "<<primes[1]<<" "<<primes[0]*primes[1]<<endl;
				cout<<1<<endl;
				continue;
			}
			else{
				ans.clear();
				filter_it(1);
				for (int i=0;i<divs.size();i++){
					if (get_mask(divs[i])!=3)
						continue;
					if (divs[i]==primes[0]*primes[1])
						continue;
					ans.push_back(divs[i]);
				}
				filter_it(2);
				ans.push_back(primes[0]*primes[1]);
				for (int i=0;i<ans.size();i++){
					if (i)
						cout<<" ";
					cout<<ans[i];
				}
				cout<<endl;
				cout<<0<<endl;
				continue;
			}
		}

		ans.clear();

		BAN=primes[0]*primes.back();

		for (int i=0;i<primes.size();i++){
			OLD_BAN=BAN;
			if (i+1<primes.size())
				BAN=primes[i]*primes[i+1];
			else
				BAN=primes[0]*primes.back();
			if (i>0)
				ans.push_back(primes[i-1]*primes[i]);
			ans.push_back(primes[i]);
			if (i+1<primes.size())
				filter_everything(primes[i]);
		}

		ans.push_back(primes[0]*primes.back());

		for (int i=0;i<ans.size();i++){
			if (i)
				cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
		cout<<0<<endl;

	}

	//cin.get(); cin.get();
	return 0;
}