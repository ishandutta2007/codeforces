/*
You belong, don't look back,
No excuses...
When you're down, face the crowd,
So illusive...

To be the same is always there for me
To feel constrained is always there for me

Can you see the light?
Can you question why?
I wonder how, eternally Im blind

When you're strong, have no doubts
So elusive...
When your thoughts face the shroud
Unobtrusive...

To be the same is always there for me
To feel constrained is always there for me

The seeds we never sow
Sedative god

Right way, there's a wrong way
And there's no way
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

const int N = 1100031;

int tests;
string st;
int edges_cnt[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	for (int i=-st.size();i<=st.size();i++){
    		edges_cnt[i+st.size()]=0;
    	}
    	int cur_bal=st.size();
    	for (int i=0;i<st.size();i++){
    		if (st[i]=='0')
    		{
    			edges_cnt[cur_bal-1]++;
    			--cur_bal;
    		}
    		else
    		{
    			edges_cnt[cur_bal]++;
    			++cur_bal;
    		}
    	}
    	string ret="";
    	cur_bal=st.size();
    	for (int i=0;i<st.size();i++){
    		if (edges_cnt[cur_bal-1]>1||(edges_cnt[cur_bal-1]==1&&edges_cnt[cur_bal]==0)){
    			ret+="0";
    			cur_bal--;
    			edges_cnt[cur_bal]--;
    		}
    		else
    		{
    			ret+="1";
    			edges_cnt[cur_bal]--;
    			cur_bal++;
    		}
    	}
    	cout<<ret<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}