/*
As the night is closing in
Unresolved and undefined
Denies the need and challenges necessity
Deprivation in a chaos of words
The hours break the sinews of resistance
The endline blurs
Where the impossible and outsized
Never learn to coexist

Not for meaning
Not for need
Not for want alone
Not for want alone
Not for meaning
Not for need
Not for want alone
How can we silence what is never said
How can we scream away the noise

It's burning from the inside out
The restless tries not to remember
This useless insight that sheds more light on the pain
Must remain in the unbroken dark

In stages of infinite time
It lies and it waits
The nerve endings touch
The surface of my dreams
And what seems like life
Stretches out eternally
I took on too much
The hours fled
And I was left here
Stranded in doubt

Not for meaning
Not for need
Not for want alone
Not for want alone
Not for meaning
Not for need
Not for want alone
How can we kill what is never given
How can we scream away the night

It's burning from the inside out
The restless tries not to remember
This useless insight that sheds more light on the pain
Must remain in the unbroken dark

Not for meaning
Not for need
Not for want alone
How can we silence what is never said
How can we scream away the noise

It burns on the inside
As I try to not remember
These endless, useless insights
Not for meaning
Not for need
Not for want alone
How can we keep what is never spoken
Here in the unbroken dark
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
const int CUT = 200;

int tests;
vector<int> heavy,light;
int n;
vector<int> vec[N];
int ans1,ans2;
int last_oc[N];
int C;

vector<int > V[N];

vector<int> vals;
map<int,int> mapp;

void compress_all_shit(){
	vals.clear();
	for (int i=1;i<=n;i++){
		for (int j=0;j<vec[i].size();j++){
			vals.push_back(vec[i][j]);
		}
	}
	sort(vals.begin(),vals.end());
	mapp.clear();
	int cnt=0;
	for (int i=0;i<vals.size();i++){
		if (i==0||vals[i]!=vals[i-1]){
			mapp[vals[i]]=cnt;
			++cnt;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<vec[i].size();j++){
			vec[i][j]=mapp[vec[i][j]];
		}
	}
}

int intersect_heavy_heavy(int id1,int id2){
	int cnt=0;
	int l=0;
	int r=0;
	while (l<vec[id1].size()&&r<vec[id2].size()){
		if (vec[id1][l]<vec[id2][r])
			++l;
		else if (vec[id1][l]>vec[id2][r]){
			++r;
		}
		else
		{
			++cnt;
			++l;
			++r;
		}
	}
	return cnt;
}

int count_with[N];

void further_compress(){
	for (int i=1;i<=n;i++){
		vector<int> temp;
		for (int j=0;j<vec[i].size();j++){
			if (count_with[vec[i][j]]==1)
				continue;
			temp.push_back(vec[i][j]);
		}
		vec[i]=temp;
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	heavy.clear();
    	light.clear();

    	for (int i=1;i<=n;i++){
    		vec[i].clear();
    		int sz;
    		cin>>sz;
    		for (int j=0;j<sz;j++){
    			int val;
    			cin>>val;
    			vec[i].push_back(val);
    		}
    	}

    	compress_all_shit();

    	for (int i=1;i<=mapp.size();i++){
    		count_with[i]=0;
    	}

    	for(int i=1;i<=n;i++){
    		for (int j=0;j<vec[i].size();j++){
    			count_with[vec[i][j]]++;
    		}
    	}

    	further_compress();

    	for (int i=1;i<=n;i++){
    		if (vec[i].size()>=CUT)
    			heavy.push_back(i);
    		else
    			light.push_back(i);
    		sort(vec[i].begin(),vec[i].end());
    	}

    	ans1=ans2=-1;

    	// heavy with heavy


    	for (int a=0;a<heavy.size();a++){
    		for (int b=a+1;b<heavy.size();b++){
    			int intersect_size=intersect_heavy_heavy(heavy[a],heavy[b]);
    			if (intersect_size>1){
    				ans1=heavy[a];
    				ans2=heavy[b];
    				break;
    			}
    		}
    		if (ans1!=-1)
    			break;
    	}
    	// heavy with light

    	for (int a=0;a<heavy.size();a++){
    		int id=heavy[a];
    		++C;
    		for (int i=0;i<vec[id].size();i++){
    			int val=vec[id][i];
    			last_oc[val]=C;
    		}
    		for (int b=1;b<=n;b++){
    			if (vec[b].size()>=CUT)
    				continue;
    			int total_in_common=0;
    			for (int i=0;i<vec[b].size();i++){
    				if (last_oc[vec[b][i]]==C)
    					++total_in_common;
    			}
    			if (total_in_common>1){
    				ans1=id;
    				ans2=b;
    				break;
    			}
    		}
    		if (ans1!=-1)
    			break;
    	}

    	// light with light
    	for (int i=0;i<=mapp.size();i++){
    		V[i].clear();
    	}

    	if (ans1==-1)
    	for (int i=1;i<=n;i++){
    		if (vec[i].size()>=CUT)
    			continue;
    		for (int j=0;j<vec[i].size();j++){
    			for (int q=j+1;q<vec[i].size();q++){
    				//cout<<vec[i][j]<<"@@@"<<vec[i][q]<<endl;
    				V[vec[i][j]].push_back(vec[i][q]);
    			}
    		}
    	}

    	pair<int,int> INTER=make_pair(-1,-1);

    	for (int id=0;id<=mapp.size();id++){
    		sort(V[id].begin(),V[id].end());
    		for (int i=1;i<V[id].size();i++){
    			if (V[id][i]==V[id][i-1]){
    				INTER=make_pair(id,V[id][i]);
    				break;
    			}
    		}
    	}
    	if (INTER!=make_pair(-1,-1)){
    		//cout<<INTER.first<<"@@@"<<INTER.second<<endl;
    		vector<int> QQ;
    		for (int i=1;i<=n;i++){
				if (vec[i].size()>=CUT)
					continue;
				for (int j=0;j<vec[i].size();j++){
					if (vec[i][j]==INTER.first)
					for (int q=j+1;q<vec[i].size();q++){
						if (vec[i][q]==INTER.second)
							QQ.push_back(i);
					}
				}
			}
    		ans1=QQ[0];
    		ans2=QQ[1];
    	}

    	if (ans1==-1){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<ans1<<" "<<ans2<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}