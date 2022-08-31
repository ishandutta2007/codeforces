#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

/*
 Another can of worms
Another stomach turns
Yeh yr ghetto burns
It's the song I hate, it's the song I hate

You got a stupid man
You got a Ku Klux Klan
Yr fuckin' battle plan
It's the song I hate, it's the song I hate

A sieg heil-in' squirt
You're an impotent jerk
Yeh a fascist twerp
It's the song I hate, it's the song I hate

Black robe and swill
I believe Anita Hill
Judge will rot in hell
It's the song I hate, it's the song I hate

Yeah a cross on fire
By a christian liar
A black attack on fire
It's the song I hate, it's the song I hate

Yeah the president sucks
He's a war pig fuck
His shit is out of luck
It's the song I hate, it's the song I hate

Another nazi attack
A skinhead is cracked
My blood is black
It's the song I hate, it's the song I hate

We're banging pots and pans
To make you understand
We gonna bury you man
It's the song I hate, it's the song I hate

I'm a human wreck
A redneck in check
I killed the teacher's pet
It's the song I hate, it's the song I hate
It's the song I hate, it's the song I hate
It's the song I hate, it's the song I hate
It's the song I hate, it's the song I hate
It's the song I hate, it's the song I hate
It's the song I hate, it's the song I hate

*/

int n, d, e, g, a[200005];
multiset<int> s;

void sort3(int &a, int &b, int &c){
	int t[3] = {a, b, c};
	sort(t, t+3);
	a = t[0], b = t[1], c = t[2];
}

void input(){
	scanf("%d %d %d %d",&n,&d,&e,&g);
	sort3(d, e, g);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(a[n-1] > d+e+g){
		puts("-1");
		exit(0);
	}
	for(int i=0; i<n; i+=3){

	}
}

bool sweep(int a, int b, int c){
	sort3(a, b, c);
	auto it1 = s.upper_bound(a);
	auto it2 = s.upper_bound(b);
	auto it3 = s.upper_bound(c);
	if(it1 == it2){
		if(it1 == s.begin()) return 0;
		it1--;
	}
	if(it2 == it3){
		if(it2 == s.begin()) return 0;
		it2--;
	}
	if(it1 == it2){
		if(it1 == s.begin()) return 0;
		it1--;
	}
	if(it1 == s.begin() || it2 == s.begin() || it3 == s.begin()) return 0;
	it1--;
	it2--;
	it3--;
	s.erase(it1);
	s.erase(it2);
	s.erase(it3);
	return 1;
}

int cnt;

bool sweep2(int a, int b){
	if(a > b) swap(a, b);
	auto it1 = s.upper_bound(a);
	auto it2 = s.upper_bound(b);
	if(it1 == it2){
		if(it1 == s.begin()) return 0;
		it1--;
	}
	if(it1 == s.begin() || it2 == s.begin()) return 0;
	it1--;
	it2--;
	s.erase(it1);
	s.erase(it2);
	cnt++;
	return 1;
}

int main(){
	input();
	for(int i=0; i<n; i++){
		s.insert(a[i]);
	}
	int ret = 0;
	while(!s.empty() && *s.rbegin() > e + g){
		s.erase(--s.end());
		ret++;
	}
	while(!s.empty() && *s.rbegin() > g){
		int t1 = *s.rbegin();
		s.erase(--s.end());
		if(t1 > d + g){
			auto t = s.upper_bound(d);
			if(t != s.begin()) t--, s.erase(t);
		}
		else if(t1 > d + e){
			auto t = s.upper_bound(e);
			if(t != s.begin()) t--, s.erase(t);
		}
		else{
			auto t = s.upper_bound(g);
			if(t != s.begin()) t--, s.erase(t);
		}
		ret++;
	}
	while(sweep(d, e, g)) ret++;
	while(sweep2(d, e+g) || sweep2(e, d+g) || sweep2(g, d+e));
	ret += cnt;
	ret += s.size();
	cout << ret;
}