/*
I don't care if my lady's gone
as long as you give me just what I want.
I've been losin' my direction,
got to find a new connection.

You have wasted the love I tasted,
now I'm really gettin' hungry more and more.
Been a long time, had a bad sign.
Tell me what am I fighting for?

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.

Lookin' for trouble, I guess that's right.
When I was young I was taught to fight.
It's been long gone since I had known,
now I'm headin' for some more.

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
Lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.

Let me know you feel it,
you know I really need it.
Keep on pushin' for more,
lay down, stay down.
I got something to find,
there's one thing I really need.
I'm gonna tell you right now,
lay down, stay down.
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

const int N = 1100031;

string s;
string t;
int cnt[N];
int ans;

long long H[N];
pair<long long, long long> S[N];

long long pw1[N],pw2[N];

long long get_hash(int l,int r){
	long long v1=S[r].first-S[l].first;
	v1%=bs;
	if (v1<0)
		v1+=bs;
	v1*=pw1[N-31-l];
	v1%=bs;
	long long v2=S[r].second-S[l].second;
	v2%=bs;
	if (v2<0)
		v2+=bs;
	v2*=pw2[N-31-l];
	v2%=bs;
	return v1*bs+v2;
}

bool solver(int size0,int size1){
	int ptr=0;
	H[0]=-1;
	H[1]=-1;
	for (int i=0;i<s.size();i++){
		if (s[i]=='0'){
			long long Q=get_hash(ptr,ptr+size0);
			if (Q!=H[0]&&H[0]!=-1)
				return false;
			H[0]=Q;
			ptr+=size0;
		}
		else
		{
			long long Q=get_hash(ptr,ptr+size1);
			if (Q!=H[1]&&H[1]!=-1)
				return false;
			H[1]=Q;
			ptr+=size1;
		}
	}
	return (H[0]!=H[1]);
}

string S1="akdfhashasfasdgashadfhshuqeioquwepityqpwietyqpoiweytopqwietyqiwopetyiwqpeotyqwepoityqwpoetiyqweipohgajklsdhgakjwepoityqwpoetiyqweipwepoityqwpoetiwepoityqwpoetiyqweipohgajkoityqwpoetiyqweipohgajkqweipohgajkpoityqwpoetiyqweipohgajkwepoityqwpoetiyqweipohgajkwepoityqwpoetiyqweipohgajklsjdglakjsdbgvg,qwierytqwoeutyqwelkjgahsdgb,gnqwejhtrqegwtdgljkadshgljkahiuewq";
string S2="ieuqwpiwutpoweqiwtpiqoweytpoqiwyetpoiqwhgaksdgkjaoethqowiuetqwejthqutjhlqiweuothqewiothqweoiuthqewoituhqewoituhqwoeithqweuoithqoituhqwoeithqweuoithqoituhqwoeithqweuoithqoituhqwouoithqoituuoithqoituuoithqoituuoithqoituuoithqoitueithqweuoithqoituhqwoeithqweuoithqwteitpoqwoietupiqowet";

bool is_prime(int val){
	if (val<2)
		return false;
	for (int i=2;i*i<=val;i++){
		if (val%i==0)
			return false;
	}
	return true;
}

int get_magic_prime(string S){
	long long C=0;
	for (int i=0;i<S.size();i++){
		C=C*173+S[i];
		C%=bs;
	}
	for (int i=C;;i++){
		if (is_prime(i))
			return i;
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int p1=get_magic_prime(S1);
	int p2=get_magic_prime(S2);
	//cout<<p1<<" "<<p2<<endl;

	pw1[0]=pw2[0]=1;
	for (int i=1;i<N;i++){
		pw1[i]=pw1[i-1]*p1%bs;
		pw2[i]=pw2[i-1]*p2%bs;
	}

	cin>>s;
	cin>>t;
	for (int i=1;i<=t.size();i++){
		S[i].first=S[i-1].first+t[i-1]*pw1[i];
		S[i].second=S[i-1].second+t[i-1]*pw2[i];
		S[i].first%=bs;
		S[i].second%=bs;
	}

	for (int i=0;i<s.size();i++){
		cnt[s[i]-'0']++;
	}

	for (int size0=1;size0<=t.size();size0++){
		long long already_used=1ll*size0*cnt[0];
		long long rem=t.size();
		rem-=already_used;
		if (rem<=0)
			continue;
		if (rem%cnt[1])
			continue;
		int size1=rem/cnt[1];
		if (solver(size0,size1))
			++ans;
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}