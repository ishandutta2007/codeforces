/*
Honesty repentence 'til the grave
Will our prayer obsessed
Intentions not sustained

Am I dreaming?
A sinner soon to die
Am I dreaming?
The sentence you decide
Crucify

Dying flame
Sweetness in such grace
Without a caring glance
The regret not to change

Am I dreaming?
Transcending you deny
Am I dreaming?
The sentence you decide
Crucify

Crucify

Am I dreaming?
A sinner soon to die
Am I dreaming?
The sentence you decide
Crucify
Crucify
For eternity you're my sentence
Crucify
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

int n;

void show(vector<int> v){
	for (int i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
}

vector<vector<int> > normalize(vector<vector<int> > v){
	sort(v.begin(),v.end());
	vector<vector<int> > ret;
	for (int i=0;i<v.size();i++){
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

vector<vector<int> > generate(int len){
	vector<vector<int> > ret;
	if (len==1){
		vector<int> temp;
		temp.push_back(0);
		ret.push_back(temp);
		return ret;
	}
	for (int cut=1;cut<len;cut++){
		vector<vector<int> > left_side=generate(cut);
		vector<vector<int> > right_side=generate(len-cut);
		for (int i=0;i<left_side.size();i++){
			for (int j=0;j<right_side.size();j++){
				vector<int> temp;
				for (int q=0;q<left_side[i].size();q++){
					temp.push_back(1^left_side[i][q]);
				}
				for (int q=0;q<right_side[j].size();q++){
					temp.push_back(1^right_side[j][q]);
				}
				ret.push_back(temp);
			}
		}
	}
	return normalize(ret);
}

long long C[100][100];

long long magic(){
	long long res=0;
	int start=0;
	start=0;
	for (int i=2;i<=n;i++){
		start--;
		if (start<0)
			start+=3;
	}
	for (int i=start;i<=n;i+=3){
		res+=C[n][i];
	}
	return res;
}

long long ar[N];
vector<pair<long long, long long> > order;
long long pref_sum[N];
int used[N];

long long more_magic(){

	int start=0;
	for (int i=2;i<=n;i++){
		start--;
		if (start<0)
			start+=3;
	}

	order.clear();
	for (int i=1;i<=n;i++){
		order.push_back(make_pair(ar[i],i));
	}
	sort(order.begin(),order.end());
	long long ans=-1e18;

	for (int i=1;i<=n;i++){
		pref_sum[i]=pref_sum[i-1]+order[i-1].first;
	}

	for (int i=start;i<=n;i+=3){
		//cout<<start<<"@@"<<endl;
		long long here=-pref_sum[i]+(pref_sum[n]-pref_sum[i]);
		if (n==1||n%2==0||i!=n/2){
			ans=max(ans,here);
			continue;
		}
		// magic continues.
		for (int j=1;j<=n;j++){
			used[j]=0;
		}
		for (int j=0;j<i;j++){
			used[order[j].second]=1;
		}
		int ok=0;
		for (int j=2;j<=n;j+=2){
			if (used[j]==0)
				ok=1;
		}
		if (ok){
			ans=max(ans,here);
			continue;
		}
		long long sum_fi=pref_sum[i];
		long long sum_se=(pref_sum[n]-pref_sum[i]);
		sum_fi+=(order[i].first-order[i-1].first);
		sum_se-=(order[i].first-order[i-1].first);
		here=-sum_fi+sum_se;
		ans=max(ans,here);
	}
	return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    for (int i=0;i<=20;i++){
    	for (int j=0;j<=i;j++){
    		if (j==0||j==i){
    			C[i][j]=1;
    		}
    		else
    		{
    			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
    		}
    	}
    }

    cin>>n;
   // vector<vector<int> > v=generate(n);

    /*cout<<v.size()<<endl;

    for (int i=0;i<v.size();i++){
    	show(v[i]);
    }

    cout<<magic()<<endl;
*/
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }
    cout<<more_magic()<<endl;

    //cin.get(); cin.get();
    return 0;
}