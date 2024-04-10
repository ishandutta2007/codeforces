/*
It's deaths intention
We pass through the certain awaits
Upholding the pleasures at hand
God-given traits

Living with scars

Through bleak accession
We task through disaster we face
In fear of rejection we stand
God given grace

To live again
Taken by the ones we force
Without a solitary reason
It's like solace from the shade

Don't see it any other way
It's deaths inception we must take

With dark intention
A passing the certain awaits
Withholding pleasures
At hand all that gods given drained
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

int tests,n;
vector<pair<int,int> > ans;

void solve(int len){
//	cout<<len<<endl;
//	cin.get();
	int Q=sqrt(len);
	if (Q*Q<len)
		++Q;
	for (int i=Q+1;i<len;i++){
		ans.push_back(make_pair(i,i+1));
	}
	ans.push_back(make_pair(len,Q));
	ans.push_back(make_pair(len,Q));
	if (Q>2)
		solve(Q);
}
int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	ans.clear();
    	solve(n);
    	cout<<ans.size()<<endl;
    	for (int i=0;i<ans.size();i++){
    		cout<<ans[i].first<<" "<<ans[i].second<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}