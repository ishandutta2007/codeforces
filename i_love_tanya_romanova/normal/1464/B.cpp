/*
Raging to a level of inebriated bliss
Pounding to the speed of the metal with our fists
Relentless is the force crushing through the earth's domain
Beer shoots down your throat while it's punishing your brain

Can you survive the ultimate chug?
Or will you choke then puke on the rug?
Or will you last this beer-bonging task?
Intoxicate!
For the final blast

Inebriate it's the way to go we never want to drink it slow!

Fucked up at top speed we got us a tool
Leaving you pissed in a puddle of drool

It's claimed many lives but not yours yet
One step in its path you're going to be next
Now drop to one knee, your mouth to the tube
Just tilt your head back and just wait for the spew!

Blast's through the chest
It pounds through your gut
It rips through your skin
You're getting tore up!

Your stomach flies open
It splat's to the floor
Another victim
The Inebriator!

Inebriate it's the way to go we never want to drink it slow!
Inebriate it's the way go!

Raging to a level of inebriated bliss
Pounding to the speed of the metal with our fists
Relentless is the force crushing through the earth's domain
Beer shoots down your throat while it's punishing your brain

You can't survive one thing is for sure
Another victim!
The Inebriator!
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

int bst;
vector<string> ans_vec;
int A,B;

int eval(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		for (int j=i+1;j<st.size();j++){
			if (st[i]=='0'&&st[j]=='1')
				res+=A;
			if (st[i]=='1'&&st[j]=='0')
				res+=B;
		}
	}
	return res;
}

bool match(string st,string st2){
	for (int i=0;i<st.size();i++){
		if (st[i]!='?'&&st[i]!=st2[i])
			return false;
	}
	return true;
}

string filter(string st1,string st2){
	string ret="";
	for (int i=0;i<st1.size();i++){
		if (st1[i]=='?')
			ret+=st2[i];
	}
	return ret;
}

void naive(string st){
	bst=1e9;
	ans_vec.clear();
	for (int mask=0;mask<(1<<(st.size()));mask++){
		string st2="";
		for (int i=0;i<st.size();i++){
			if (mask&(1<<i))
				st2+='1';
			else
				st2+='0';
		}
		if (!match(st,st2))
			continue;
		long long here=eval(st2);
		if (here>bst){
			continue;
		}
		if (here<bst)
			ans_vec.clear();
		bst=here;
		ans_vec.push_back(filter(st,st2));
	}
	cout<<st<<endl;
	cout<<bst<<endl;
	for (int i=0;i<ans_vec.size();i++){
		cout<<ans_vec[i]<<endl;
	}
}

string generate_random(){
	string ret="";
	for (int i=0;i<18;i++){
		int here=rand()%100;
		if (here<30)
			ret+="?";
		else if (here<65)
			ret+="0";
		else
			ret+="1";
	}
	return ret;
}

string st;
long long x,y;
long long ans_val;
string ans_st;

string strat01(string st,int cnt){
	for (int i=0;i<st.size();i++){
		if (st[i]=='?'){
			if (cnt>0){
				st[i]='0';
			}
			else
			{
				st[i]='1';
			}
			--cnt;
		}
	}
	return st;
}

string strat10(string st,int cnt){
	for (int i=0;i<st.size();i++){
		if (st[i]=='?'){
			if (cnt>0){
				st[i]='1';
			}
			else
			{
				st[i]='0';
			}
			--cnt;
		}
	}
	return st;
}

long long smart_ev(string st){
	long long ret=0;
	int cnt0=0;
	int cnt1=0;
	for (int i=0;i<st.size();i++){
		if (st[i]=='0'){
			ret+=cnt1*y;
			cnt0++;
		}
		else
		{
			ret+=cnt0*x;
			cnt1++;
		}
	}
	return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

   /* while (true){
    	string S=generate_random();
    	A=rand()%10+1;
    	B=rand()%10+1;
    	naive(S);
    	cin.get();
    }*/

    cin>>st;
    cin>>x>>y;
    int cnt=0;
    for (int i=0;i<st.size();i++){
    	if (st[i]=='?')
    		cnt++;
    }

    int l=0;
    int r=cnt;
    while (l+3<=r){
    	int mid1=l*2+r;
    	int mid2=l+r*2;
    	mid1/=3;
    	mid2/=3;
    	string temp1=strat01(st,mid1);
    	string temp2=strat01(st,mid2);
    	if (smart_ev(temp1)<smart_ev(temp2))
    		r=mid2;
    	else
    		l=mid1;
    }

    ans_val=1e18;

    for (int i=l;i<=r;i++){
    	string temp=strat01(st,i);
    	long long here=smart_ev(temp);
    	if (here<ans_val){
    		ans_val=here;
    		ans_st=temp;
    	}
    }

    l=0;
    r=cnt;
    while (l+3<=r){
    	int mid1=l*2+r;
    	int mid2=l+r*2;
    	mid1/=3;
    	mid2/=3;
    	string temp1=strat10(st,mid1);
    	string temp2=strat10(st,mid2);
    	if (smart_ev(temp1)<smart_ev(temp2))
    		r=mid2;
    	else
    		l=mid1;
    }

    for (int i=l;i<=r;i++){
    	string temp=strat10(st,i);
    	long long here=smart_ev(temp);
    	if (here<ans_val){
    		ans_val=here;
    		ans_st=temp;
    	}
    }

    cout<<ans_val<<endl;

    //cin.get(); cin.get();
    return 0;
}