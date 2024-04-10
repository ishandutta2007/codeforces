/*
I've turned down all devotion
I'm so far from being here
Can't bring forth more power
Than I have already done

Tonight I'm trying
And I see all dread in me

But then I lose again
All hope of being someone
This lack of devotion
Will put me to an end

So if you want to save me
And stop me when I run
Just tell me that I'll have now
A day less to live when I'm done
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

int tests;
int n,m,a,b;
int lifespan;
multiset<int> S;
multiset<int>::iterator it;
int val;
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>a>>b;
    	if (a<b)
    		lifespan=b-1;
    	else
    		lifespan=n-b;

    	S.clear();
    	for (int i=1;i<=m;i++){
    		cin>>val;
    		S.insert(val);
    	}

    	ans=0;
    	for (int i=1;i<=lifespan;i++){
    		int bound=lifespan-i;
    		it=S.upper_bound(bound);
    		if (it==S.begin())
    			break;
    		--it;
    		++ans;
    		S.erase(it);
    	}
    	ans=min(ans,abs(a-b)-1);
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}