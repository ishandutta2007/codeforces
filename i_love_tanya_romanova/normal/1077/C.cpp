/*
Whoever appeals to the law against his fellow man is either a fool or a coward
Whoever cannot take care of themselves without that law is both
For a wounded man shall say to his assailant
'If I live, I will kill you. If I die, You are forgiven'
Such is the rule of honour

Broken the paradigm an example must be set
Invoke the Siren's song and sign the death warrant
This is what has been wrought for 30 pieces of silver
The tongues of men and angels bought by a beloved betrayer
I am the result what's better left unspoken
Violence begins to mend what was broken
You've been talking, I've been all ears
Words meant to dwell in darkness shall never see the light of day
Words can be broken, so can bones
Execute the mandate
Mouth full of dirt
Your name is removed from the registry
St. Peter greets with empty eyes then turns and locks the gate
I am the result what's better left unspoken
Violence begins to mend what was broken
You've been talking, I've been all ears
Omerta
Cheaply venal, stupidly verbose
A slip of the tongue, a slit of the throat
Six feet under with no marker
Keep my name from your mouth forever
Free speech for the living, dead men tell no tales
Your laughing finger will never point again
Omerta
Sing for me now
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

const int N = 300031;

int n,ar[N];
vector<int> ans;

multiset<int> S;
long  long cur_sum;
multiset<int>::iterator it;

bool good(){
	it=S.end();
	--it;
	long long mx=(*it);
	return (mx*2==cur_sum);
}

void add(int val){
	S.insert(val);
	cur_sum+=val;
}

void del(int val){
	S.erase(S.find(val));
	cur_sum-=val;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		add(ar[i]);
	}

	for (int i=1;i<=n;i++){
		del(ar[i]);
		if (good()){
			ans.push_back(i);
		}
		add(ar[i]);
	}

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}