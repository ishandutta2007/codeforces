/*
The judging eyes watching me
Is all I've ever known.
When I try to open up my heart
I am ridiculed and torn apart.
You tell jokes I'll never get to hear
Behind my back at my expense.

There's something inside me
And I know it's good.
I'm not evil, just misunderstood.

Do you see me now?
Do you hear me now?
You will know my name!
Do you see me now?
Do you fear me now?
You will know my name!

Today I break my silence
Strip you of your dignity.
Tear down your perfect world
Your perfect lies!

No more jokes I'll never get to hear
Behind my back at my expense.

There's something inside me
And I know it's good.
I'm not evil, I'm just misunderstood.

Do you see me now?
Do you hear me now?
You will know my name!
Do you see me now?
Do you fear me now?
You will know my name!

No longer invisible

You will know my name!

Do you see me now?
Do you hear me now?
You will know my name!
Do you see me now?
Do you fear me now?
You will know my name!

No longer invisible

You will know my name!
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

int n,ar[N];
vector<int> vertices[N],g[N];
vector<int> ans;
int C;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=0;i<=n;i++){
		cin>>ar[i];
	}

	int is_ok=0;
	for (int i=2;i<=n;i++){
		if (ar[i]>=2&&ar[i-1]>=2){
			is_ok=1;
		}
	}

	if (is_ok==0){
		cout<<"perfect"<<endl;
		return 0;
	}

	cout<<"ambiguous"<<endl;

	// print first

	for (int i=0;i<=200000;i++){
		g[i].clear();
		vertices[i].clear();
	}

	vertices[0].push_back(1);
	ans.push_back(0);
	C=1;

	for (int i=1;i<=n;i++){
		for (int j=0;j<ar[i];j++){
			ans.push_back(vertices[i-1][0]);
			++C;
			vertices[i].push_back(C);
		}
	}

	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	// print second
	for (int i=0;i<=200000;i++){
		g[i].clear();
		vertices[i].clear();
	}
	ans.clear();
	vertices[0].push_back(1);
	C=1;
	ans.push_back(0);

	for (int i=1;i<=n;i++){
		for (int j=0;j<ar[i];j++){
			if (j==0)
				ans.push_back(vertices[i-1][0]);
			else
				ans.push_back(vertices[i-1].back());
			++C;
			vertices[i].push_back(C);
		}
	}

	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}