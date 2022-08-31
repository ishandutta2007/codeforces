/*
I remember the beauty, I remember the youth
I remember illusions, I remember the truth

I remember the mirror, deep inside I feel the pain
I remember the reason, suffering unto the change
I remember the mirror, deep inside I feel the pain

I remember the beast, I remember the wild
I remember visions and hating the lie

I remember the mirror, deep inside I feel the pain
I remember the reason, suffering unto the change
I remember the mirror, deep inside I feel the pain

spring follows winter, the blooming will start
spring follows winter, the blooming will start

I remember the beast, I remember the wild
I remember visions and hating the lie

I remember the reason, suffering unto the change
I remember the mirror, deep inside I feel the pain
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

const int N = 500031;

int n;
string st;
int cur_cnt;
vector<pair<int,int> > INC;
long long PROG[N];

long long eval(string s){
	int mx=0;
	int cur=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='0')
			cur=0;
		else
			cur++;
		mx=max(mx,cur);
	}
	return mx;
}

long long brute(){
	long long res=0;
	for (int i=0;i<st.size();i++){
		string temp="";
		for (int j=i;j<st.size();j++){
			temp+=st[j];
			res+=eval(temp);
		}
	}
	return res;
}

long long solve(){

    cur_cnt=0;

    long long ans=0;

    for (int i=st.size()-1;i>=0;--i){
    	if (st[i]=='1'){
    		++cur_cnt;
    	}
    	else
    		cur_cnt=0;
    	while (INC.size()>0&&INC.back().second<=cur_cnt)
    		INC.pop_back();
    	if (cur_cnt>0){
    		INC.push_back(make_pair(i,cur_cnt));
    	}
    	if (INC.size()==0)
    		continue;
    	int sz=INC.size();
    	int cur_covered;
    	int cur_max=0;
    	int all_the_same;
    	for (int id=sz-1;id>=0;--id){
    		ans+=PROG[INC[id].second]-PROG[cur_max];
    		cur_covered=INC[id].first+INC[id].second-1;
    		if (id==0)
    			all_the_same=n-1;
    		else
    			all_the_same=INC[id-1].first+INC[id].second-1;
    		//cout<<INC[id].second<<"@@@"<<all_the_same<<" "<<cur_covered<<"  @"<<ans<<endl;
    		ans+=(all_the_same-cur_covered)*1ll*INC[id].second;
    		//cout<<"and now: "<<ans<<endl;
    		cur_max=INC[id].second;
    	}
    	//cout<<i<<"@@@"<<ans<<endl;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    cin>>st;
//    n=st.size();

    for (int i=1;i<=n;i++){
    	PROG[i]=PROG[i-1]+i;
    }

   // cout<<brute()<<endl;
    cout<<solve()<<endl;


    //cin.get(); cin.get();
    return 0;
}