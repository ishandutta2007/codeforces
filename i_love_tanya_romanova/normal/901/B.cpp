/*
When I was born the seed was sown
I will not obey, my life is my own
Battle rose, which do enslave me
Exposed lies that enrage me

I don't believe in heaven, I don't believe in hell
Never joined the herd, could not adjust well
Slave and master, it's not for me
I chose my own path, set myself free

I, I go my own way
I swim against the stream
Forever I will fight the powers that be

I, I go my own way
I swim against the stream
Forever I will fight the pwers that be
The eagle flies alone

Reject the system that dictates the norm
This world is full of lies and deceit
I have felt betrayal, cut so deep
Suffered defeat only to rise again

I, I go my own way
I swim against the stream
Forever I will fight the powers that be
I, I go my own way
I swim against the stream
Forever I will fight the powers that be
The eagle flies alone

Alone!

I, I go my own way
I swim against the stream
Forever I will fight the powers that be
I, I go my own way
I swim against the stream
Forever I will fight the powers that be
The eagle flies alone
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

const int N = 510031;

vector<int> P[200];

vector<int> add(vector<int> a,vector<int> b){
	for (int i=0;i<a.size();i++){
		if (i<b.size())
			a[i]+=b[i];
	}
	return a;
}

vector<int> subs(vector<int> a,vector<int> b){
	for (int i=0;i<a.size();i++){
		if (i<b.size()){
			a[i]-=b[i];
		}
	}
	return a;
}

bool is_valid(vector<int> v){
	for (int i=0;i<v.size();i++){
		if (abs(v[i])>1)
			return false;
	}
	return true;
}

void show_vec(int x){
	cout<<P[x].size()-1<<endl;
	for (int i=0;i<P[x].size();i++){
		if (i)
			cout<<" ";
		cout<<P[x][i];
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

	P[0].push_back(1);
	P[1].push_back(0);
	P[1].push_back(1);

	for(int i=2;i<=150;i++){
		P[i]=P[i-1];
		reverse(P[i].begin(),P[i].end());
		P[i].push_back(0);
		reverse(P[i].begin(),P[i].end());

		vector<int> P1=add(P[i],P[i-2]);
		if (is_valid(P1)){
		//	cout<<"OK i"<<endl;
			P[i]=P1;
			continue;
		}
		vector<int> P2=subs(P[i],P[i-2]);
		if (is_valid(P2)){
			P[i]=P2;
		//	cout<<"OK i"<<endl;
			continue;
		}
		//cout<<"SHIT"<<endl;
		break;
	}

	int n;
	cin>>n;
	show_vec(n);
	show_vec(n-1);

	cin.get(); cin.get();
	return 0;
}