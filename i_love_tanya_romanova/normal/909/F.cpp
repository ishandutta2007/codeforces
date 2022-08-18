/*
Lost in a dream
Nothing is what it seems
Searching my head
For the words that you said

Tears filled my eyes
As we said our last goodbyes
This sad scene replays
Of you walking away

My body aches from mistakes
Betrayed by lust
We lied to each other so much
That in nothing we trust

Time and again,
She repeats let's be friends
I smile and say yes
Another truth bends,
I must confess

I try to let go, but I know
We'll never end 'til we're dust
We lied to each other again
But I wish I could trust

My body aches from mistakes
Betrayed by lust
We lied to each other so much
That in nothing we trust

God help me please, on my knees
Betrayed by lust
We lied to each other so much
That in nothing we trust

How could this be happening to me
I'm lying when I say "Trust me"
I can't believe this is true
Trust hurts
Why does trust equal suffering

Absolutely nothing we trust
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

const int N = 200031;

bool check_condition_true(vector<int> v){
	for (int i=0;i<v.size();i++){
		if (v[i]==i+1)
			return false;
		if (!(v[i]&(i+1)))
			return false;
	}
	return true;
}

bool check_condition_false(vector<int> v){
	for (int i=0;i<v.size();i++){
		if (v[i]==i+1)
			return false;
		if (v[i]&(i+1))
			return false;
	}
	return true;
}

int n;
vector<int> order;

void show_true(vector<int> v){
	cout<<"True: "<<endl;
	for (int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void show_false(vector<int> v){
	cout<<"False: "<<endl;
	for (int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void show_solution_true(string st){
	cout<<"YES"<<endl;
	cout<<st<<endl;
}

void run_solver_true(){
	if (n<6){
		cout<<"NO"<<endl;
		return;
	}
	if (n==6){
		show_solution_true("3 6 1 5 4 2");
		return;
	}
	if (n==7){
		show_solution_true("5 3 1 6 4 7 2");
		return;
	}
	if ((n&(n-1))==0)
	{
		cout<<"NO"<<endl;
		return;
	}
	vector<int> ret;
	ret.push_back(5);
	ret.push_back(3);
	ret.push_back(1);
	ret.push_back(6);
	ret.push_back(4);
	ret.push_back(7);
	ret.push_back(2);
	for (int i=8;i<=n;i*=2){
		int thold=min(n,i*2-1);
		for (int j=i+1;j<=thold;j++)
			ret.push_back(j);
		ret.push_back(i);
	}
	cout<<"YES"<<endl;
	for (int i=0;i<ret.size();i++){
		if (i)
			cout<<" ";
		cout<<ret[i];
	}
	cout<<endl;
}

bool is_bad(vector<int>&v,int lev,int ps){
	return (v[ps]&(ps+1)&(1<<lev));
}

void resolve(vector<int>&v,int lev,int ps){
	swap(v[ps],v[ps-(1<<lev)]);
}

void run_solver_false(){
	if (n%2==1){
		cout<<"NO"<<endl;// don't ask me why
		return ;
	}
	vector<int> v;
	for (int i=1;i<=n;i++){
		v.push_back(i);
	}

	for (int i=0;i+1<v.size();i+=2){
		swap(v[i],v[i+1]);
	}

	for(int i=1;i<=30;i++){
		for (int j=0;j<v.size();j++){
			if (is_bad(v,i,j)){ // don't ask me why either
				resolve(v,i,j);
			}
		}
	/*	for (int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
		}
		cout<<endl;*/
	}

//	cout<<check_condition_false(v)<<endl;
	int here=check_condition_false(v);
	if (here==0){
		cout<<n<<" SHIT"<<endl;
		while (true);
	}

	cout<<"YES"<<endl;
	for (int i=0;i<v.size();i++){
		if (i)
			cout<<" ";
		cout<<v[i];
	}
	cout<<endl;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

/*	cin>>n;
	for (int i=1;i<=n;i++){
		order.push_back(i);
	}

	do{
		if (check_condition_true(order)){
		//	show_true(order);
		}
		if (check_condition_false(order)){
			show_false(order);
		}
	}while (next_permutation(order.begin(),order.end()));
*/

	/*for (int i=2;i<=1000;i+=2){
		n=i;
		run_solver_false();
	}*/
	cin>>n;

	run_solver_false();
	run_solver_true();

	cin.get(); cin.get();
	return 0;
}