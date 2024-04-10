/*
Your self control makes me feel alone
I've tried confidence, had it for breakfast today
I've lost the perfection, a mess without words
(And) As the seasons change I'll continue to ignore
The image I project - me without me
The picture that I scanned is borrowed

After the education you stopped making sense to me
Seems to me that it's all the same, time and time again
Slowly, all that I believed in, turning into a lie
To aim and miss, my supernatural art
Spending to much time with myself
Trying to explaining who I am

How come it's possible
I wish there was a way
(Suddenly) I feel so invincible
I'm the sculpture made out of clay

I need someone to break the silence
before it all falls apart
I need something to cling onto
before I break you in parts

So afraid of what you may think
And all the plastic people that surrounds me
I have to find the path to where it all begins
To teach the world my supernatural art
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 110031;

string st;
int n;
string res[N];

int ans[N];
string answ;

int get_bit(int val,int ps){
	for (int i=0;i<ps;i++){
		val/=26;
	}
	return val%26;
}

bool valid_move(int a,int b){
		for (int j=0;j<3;j++){
			int should_be=get_bit(a,j);
			if (res[j][b]!=should_be+'a')
				return false;
		}
	return true;
}

string get_qu(int n,int lev){
	string ret;
	for (int i=0;i<n;i++){
		int here=get_bit(i,lev);
		char c=here+'a';
		ret+=c;
	}
	return ret;
}

string make_query(string st){
	cout<<"? "<<st<<endl;
	string ret;
	cin>>ret;
	return ret;
}

void tell_answer(string st){
	cout<<"! "<<st<<endl;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 //   ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>st;

    n=st.size();

    for (int i=0;i<3;i++){
    	string qu_string=get_qu(n,i);
    	res[i]=make_query(qu_string);
    }

    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		if (valid_move(i,j))
    			ans[i]=j;
    	}
    }

    for (int i=0;i<st.size();i++){
    	answ+=st[ans[i]];
    }

    tell_answer(answ);


//    cin.get(); cin.get();
    return 0;
}