/*
Why don't you ask the kids at Tienanmen square?
Was fashion the reason why they were there?

They disguise it, hypnotize it
Television made you buy it

I'm just sitting in my car and waiting for my

She's scared that I will take her away from there
Dreams that her country left with no one there

Mesmerize the simple minded
Propaganda leaves us blinded

I'm just sitting in my car and waiting for my girl
I'm just sitting in my car and waiting for my girl

I'm just sitting in my car and waiting for my girl
I'm just sitting in my car and waiting for my girl
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

int n,k;
int p[N];
int root;
vector<int> sons[N];
int x[N],y[N];
vector<int> in_rules[N],out_rules[N];
vector<int> ans;
int comp_root[N];
int shit;

int get_comp_root(int i, int dep){

	if (dep>=N){
		shit=1;
		return 0;
	}

	if (comp_root[i])
		return comp_root[i];

	if (in_rules[i].size()==0)
		comp_root[i]=i;
	else
	{
		int id=in_rules[i][0];
		int v=x[id];
		comp_root[i]=get_comp_root(v,dep+1);
	}
	return comp_root[i];
}

vector<int> below[N];
int IND[N];
set<int> leaves;
set<int>::iterator it;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>p[i];
    	if (p[i]==0)
    		root=i;
    	else
    		sons[p[i]].push_back(i);
    }

    for (int i=1;i<=k;i++){
    	cin>>x[i]>>y[i];
    	out_rules[x[i]].push_back(i);
    	in_rules[y[i]].push_back(i);
    	below[x[i]].push_back(y[i]);
    	IND[y[i]]++;
    }

    for (int i=1;i<=n;i++){
    	if (in_rules[i].size()>1||out_rules[i].size()>1){
    		cout<<0<<endl;
    		return 0;
    	}
    }

    for (int i=1;i<=n;i++){
    	comp_root[i]=get_comp_root(i,0);
    	if(shit){
    		cout<<0<<endl;
    		return 0;
    	}
    }

    for (int i=1;i<=n;i++){
    	for (int j=0;j<sons[i].size();j++){
    		int to=sons[i][j];
    		to=comp_root[to];
    	//	cout<<i<<" "<<sons[i][j]<<"#"<<to<<" "<<comp_root[i]<<"@@@"<<comp_root[to]<<endl;
    		if (comp_root[to]==comp_root[i])
    		{
    			below[i].push_back(sons[i][j]);
    			IND[sons[i][j]]++;
    		}
    		else
    		{
    			below[i].push_back(to);
    			IND[to]++;
    		}
    	}
    }

    for (int i=1;i<=n;i++){
    	if (IND[i]==0){
    		leaves.insert(i);
    	}
    }

    int magical=0;
    int cur;

    while (leaves.size()){
    //	cout<<magical<<"@@@"<<leaves.size()<<endl;
    	//if (ans.size())
    	//	cout<<ans.back()<<endl;

    	if (magical){
    		if (leaves.find(magical)==leaves.end()){
    			cout<<0<<endl;
    			return 0;
    		}
    	}
    	if (magical==0)
    	{
    		it=leaves.begin();
    		magical=(*it);
    	}
    	leaves.erase(magical);
    	cur=magical;

    	ans.push_back(cur);
    	magical=0;

    	if (out_rules[cur].size()){
    		magical=y[out_rules[cur][0]];
    	}
    	else
    		magical=0;

    	for (int i=0;i<below[cur].size();i++){
    		int to=below[cur][i];
    		IND[to]--;
    		if (IND[to]==0)
    			leaves.insert(to);
    	}
    }

    if (ans.size()<n){
    	cout<<0<<endl;
    }
    else
    {
    	for (int i=0;i<ans.size();i++){
    		if (i)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}