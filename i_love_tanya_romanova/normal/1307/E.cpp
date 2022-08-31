/*
Look around
Where do you belong
Don't be afraid
You are not the only one

Don't let the day go by
Don't let it end
Don't let a day go by in doubt
The answer lies within

Life is short, so learn from your mistakes
And stand behind, the choices that you made
Face each day with both eyes open wide
And try to give, don't keep it all inside

Don't let the day go by
Don't let it end
Don't let a day go by, in doubt
The answer lies within

You've got the future on your side
You've gonna be fine now
I know whatever you decide
You are gonna shine (shine)

Don't let the day go by
Don't let it end
Don't let a day go by, in doubt
You re ready to begin

Don't let a day do by in doubt
The answer lies within
*/

#pragma GCC optimize("O3")
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m;
int s[N];
int f[N],h[N];
int L[N],R[N];

vector<int> entries[5031];
int C1[5031],C2[5031];

// ways, times

pair<int,int> one_side_solver(){
	pair<int,int> ret;
	ret.first=1;
	ret.second=0;
	for (int i=1;i<=5000;i++){
		if (entries[i].size()){
			ret.first=1ll*ret.first*entries[i].size()%bs;
			ret.second++;
		}
	}
	return ret;
}

void update(pair<int,int> &cur, pair<int,int> &othr){
	if (cur.second<othr.second)
		cur.first=0;
	if (cur.second>othr.second)
		return;
	cur.second=othr.second;
	cur.first=(cur.first+othr.first)%bs;
}

pair<int,int> fancy_solver(int r_id){
	pair<int,int> ret=make_pair(1,0);

	for (int i=1;i<=n;i++){
		if (i!=f[r_id]){ // ordinary case

			int one_side_count=0;
			int two_side_count=0;
			for (int j=0;j<entries[i].size();j++){
				int id=entries[i][j];
				int sides_here=0;
				if(L[id]<R[r_id])
					++sides_here;
				if (R[id]>R[r_id])
					++sides_here;
				if (sides_here==1)
					one_side_count++;
				if (sides_here==2)
					two_side_count++;
			}
			int mx=one_side_count+two_side_count;
			mx=min(mx,2);
			if (two_side_count==0)
				mx=min(mx,1);
			if (mx==0)
				continue;
			if (mx==1){
				int ways_here=one_side_count+2*two_side_count;
				ret.first=ret.first*1ll*ways_here%bs;
				ret.second+=1;
			}
			else
			{
				int ways_here=0;
				ways_here+=C2[two_side_count]*2; // 2 2
				ways_here+=C1[one_side_count]*C1[two_side_count];
				ways_here%=bs;
				ret.first=ret.first*1ll*ways_here%bs;
				ret.second+=2;
			}
		}
		else // special crap; right side already fixed, check left
		{
			int count_of_good=0;
			for (int j=0;j<entries[i].size();j++){
				int id=entries[i][j];
				if (id==r_id)
					continue;
				if (L[id]<R[r_id])
					++count_of_good;
			}
			if (count_of_good){
				ret.first=1ll*ret.first*count_of_good%bs;
				ret.second+=2;
			}
			else
				ret.second+=1;
		}
	}

	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int i=0;i<=5000;i++){
    	C1[i]=i;
    	C2[i]=i*(i-1)/2;
    }

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>s[i];
    }

    for (int i=1;i<=m;i++){
    	cin>>f[i]>>h[i];
    }

    for (int id=1;id<=m;id++){
    	int found=-1;
    	int cnt=0;
    	for (int i=1;i<=n;i++){
    		if (s[i]==f[id]){
    			++cnt;
    			if (cnt==h[id])
    			{
    				found=i;
    				break;
    			}

    		}
    	}

    	L[id]=found;

    	if (found==-1){
    		R[id]=-1;
    		continue;
    	}

    	cnt=0;
    	for (int i=n;i>=1;--i){
    		if (s[i]==f[id]){
    			++cnt;
    			if (cnt==h[id]){
    				found=i;
    				break;
    			}
    		}
    	}
    	R[id]=found;
    	if (R[id]!=-1){
    		entries[f[id]].push_back(id);
    	}
    }

    pair<int,int> base=one_side_solver();

    for (int i=1;i<=m;i++){
    	if (R[i]==-1)
    		continue;
    	pair<int,int> here=fancy_solver(i);
    	update(base,here);
    }

    cout<<base.second<<" "<<base.first<<endl;

    //    cin.get(); cin.get();
    return 0;
}