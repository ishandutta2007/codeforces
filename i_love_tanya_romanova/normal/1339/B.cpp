/*
Power is a Human syndrome no-one can avoid
Trying to defend it won't do you any good
Why live your life in abstinence when wealth is to prefer
This is the only life you got so like it now and here

I love this life in sin believe me
And all the freedom that it gives to me

Let out your desires and I feel the breath of lust
Do it for your own sake no matter what it costs
Spit on the preachers tolkjve and kick him in the ass
Make him eat his bible that has filled him up with trash

I love this life in sin believe me
And all the freedom that it gives to me

Damned are all religion they are only thieves of life
Would you like another Jesus watch an angel fuck your wife

If God and Satan are fighting then let them fight alone
If God strong he will survive, if not he will get blown

Are you gonna hang around and watch this world go by
Don't you act so foolish it's a case of do or die
Lies and cheatings stole your life and your identity
Better reach out for it now, I'm here to set you free

I love this life in sin believe me
And all the freedom that it gives to me.
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

const long long N = 200031;

vector<int> order;
int tests,n;
int ar[N];
vector<int> ans;
int ptrl,ptrr;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		order.push_back(ar[i]);
    	}
    	sort(order.begin(),order.end());

    	ptrl=0;
    	ptrr=order.size()-1;
    	ans.clear();
    	while (ptrl<=ptrr){
    		if (ans.size()%2==0){
    			ans.push_back(order[ptrl]);
    			++ptrl;
    		}
    		else{
    			ans.push_back(order[ptrr]);
    			--ptrr;
    		}
    	}
    	reverse(ans.begin(),ans.end());
    	for (int i=0;i<ans.size();i++)
    	{
    		if (i)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}