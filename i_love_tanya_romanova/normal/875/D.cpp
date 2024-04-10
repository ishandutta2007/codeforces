/*
Night will come and I will follow
For my victims, no tomorrow
Make it fast, your time of sorrow
On his trail, I'll make you follow

Quarters for the criminally insane
The sentence read for life I must remain
The path I chose has led me to my grave
To try again I'd have no other way

Quarters for the criminally insane
Escape for me has fast become a game
Soon to be, I'll leave without a trace
Endangered species end the human race

Branded in pain
Marked criminally insane
Locked away and kept restrained
Disapprobation, but what have I done
I have yet only just begun
To take your fuckin' lives!

(Night will come and I will follow
For my victims, no tomorrow
Make it fast, your time of sorrow
On his trail, I'll make you follow)
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

const int N = 200031;

int n,ar[N];
int first_right[N][33];
int sparse[22][N];
int L[N];
vector<pair<int,int> > order;
long long ans;

int get_max(int l,int r){
	int span=r-l+1;
	int lev=L[span];
	return max(sparse[lev][l],sparse[lev][r-(1<<lev)+1]);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
	}

	L[1]=0;

	for (int i=2;i<=n;i++)
	{
		L[i]=L[i/2]+1;
	}

	for (int i=0;i<=30;i++)
		first_right[n+1][i]=n+1;

	for (int i=n;i>=1;--i){
		for (int j=0;j<=30;j++){
			first_right[i][j]=first_right[i+1][j];
			if (ar[i]&(1<<j))
				first_right[i][j]=i;
		}
	}

	for (int i=1;i<=n;i++)
		sparse[0][i]=ar[i];

	for (int lev=1;lev<=20;lev++){
		for (int i=1;i+(1<<lev)-1<=n;i++){
			sparse[lev][i]=max(sparse[lev-1][i],sparse[lev-1][i+(1<<lev)/2]);
		}
	}

	for (int i=1;i<=n;i++){
		order.clear();
		for (int j=0;j<=30;j++){
			order.push_back(make_pair(first_right[i][j],j));
		}
		sort(order.begin(),order.end());
		int ptr=i;
		int cur_or=0;
		for (int j=0;j<order.size();j++){
			cur_or|=(1<<(order[j].second));
			int seg_start=order[j].first;
			int seg_end;
			if (j+1==order.size())
				seg_end=n;
			else
				seg_end=order[j+1].first-1;
			if (seg_start>seg_end)
				continue;
			if (get_max(i,seg_start)>=cur_or)
				continue;
			int l,r;
			l=seg_start;
			r=seg_end;
			while (l<r){
				int mid=l+r+1;
				mid/=2;
				if (get_max(i,mid)<cur_or)
					l=mid;
				else
					r=mid-1;
			}
			ans+=l-seg_start+1;
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}