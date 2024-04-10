/*
Darkness falls upon my mind
Recalls all the sleepless nights
Shadows of my faceless pain
Feelings of the deep dark rain

Will my sad memories wash away with my shame?
Will the rain wash away the demons in my eyes?

Dreams of solitude that can't be found
Will the rain wash away?

All I remember was the pain coming back
The rope choking my neck
Nightfall all around

All I remember was the pain coming back
The rope choking my neck
Nightfall all around

Darkness falls upon my mind
Recalls all the sleepless nights
Shadows of my faceless pain
Feelings of the deep dark rain

Will my sad memories wash away with my shame?
Will the rain wash away the demons in my mind?
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 200031;

int pr[N];
int cur_degree[N];
map<int,int> per_prime[N];
long long ans;
int n,q;
int ar[N];

vector<int> factorize(int x){
	vector<int> ret;
	while (x!=1){
		ret.push_back(pr[x]);
		x/=pr[x];
	}
	return ret;
}

void do_multiply(int ps,int val){
	if (per_prime[ps][val]==0)
		++cur_degree[val];
	per_prime[ps][val]++;
	if (cur_degree[val]==n){
		ans*=val;
		ans%=bs;
		cur_degree[val]=0;
		for (int i=1;i<=n;i++){
			--per_prime[i][val];
			if (per_prime[i][val])
				cur_degree[val]++;
		}
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    pr[1]=1;
    for (int i=2;i<N;i++){
    	if (pr[i]==0){
    		for (int j=i;j<N;j+=i){
    			pr[j]=i;
    		}
    	}
    }

    for (int i=2;i<N;i++){
    	cur_degree[i]=0;
    }

    ans=1;

    cin>>n>>q;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	vector<int> V=factorize(ar[i]);
    	for (int j=0;j<V.size();j++){
    		do_multiply(i,V[j]);
    	}
    }

    for (;q;--q){
    	int ps,val;
    	cin>>ps>>val;
    	vector<int> V=factorize(val);
    	for (int j=0;j<V.size();j++){
    		do_multiply(ps,V[j]);
    	}
    	cout<<ans<<"\n";
    }

    //cin.get(); cin.get();
    return 0;
}