/*
Lost in a world
A guided eye to strengthen weakness
Throat in noose pain
Feel it constricting a lost love
Welcome to war
And it grows
Ocean lure
Fire of mankind
Universe
Throw it away
Destroyer of worlds found pain
Welcome to war
And it grows
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

const int N = 200031;

int n;
string S[N];
vector<pair<string,int> > order;

int ans[N];
vector<string> candidates;

bool is_valid(string A,string B){
	string temp=A;
	temp+=B[B.size()-1];
	vector<pair<string,int> > V;
	string P="";
	for (int i=0;i+1<temp.size();i++){
		P+=temp[i];
		V.push_back(make_pair(P,0));
	}
	P="";
	for (int i=temp.size()-1;i>0;--i){
		P=temp[i]+P;
		V.push_back(make_pair(P,1));
	}
	sort(V.begin(),V.end());
	sort(order.begin(),order.end());
	for (int i=0;i<order.size();i++){
		if (order[i].first!=V[i].first)
			return false;
		ans[order[i].second]=V[i].second;
	}
	return true;
}

void show_answer(){
	for (int i=1;i<=n*2-2;i++){
		if (ans[i])
			cout<<"S";
		else
			cout<<"P";
	}
	cout<<endl;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n;
	for (int i=1;i<=n*2-2;i++){
		cin>>S[i];
		order.push_back(make_pair(S[i],i));
		if (S[i].size()+1==n){
			candidates.push_back(S[i]);
		}
	}

	for (int i=0;i<candidates.size();i++){
		for (int j=0;j<candidates.size();j++){
			if (is_valid(candidates[i],candidates[j])){
				show_answer();
				return 0;
			}
		}
	}
//    cin.get(); cin.get();
    return 0;
}