/*
The day is gone
when the angels come to stay
And all the silent whispers
will be blown away
And lying in the corner
a pair of high heel shoes
Hanging on the wall
gold and silver for the blues

One too many wasted sunsets
One too many for the road
And after dark the door is always open
Hoping someone else will show

Someone is waiting behind
an unlocked door
Grey circles overhead empties
on the floor
The cracks in the walls have
grown too long
The slow hand is dragging on
afraid to meet the dawn

One too many wasted sunsets
One too many for the road
And after dark the door is always open
Hoping someone else will show
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

const int N = 400031;

int vertCnt;
string st;
int done[10031][131];
pair<int,int> memo[10031][131];
int is_leaf[10031];
pair<int,int> sons[10031];
int cntPlus,cntMinus;
int minusFlag;
int value[10031];
int size[10031];

int parse(int l,int r){
	if (l==r){
		++vertCnt;
		is_leaf[vertCnt]=1;
		value[vertCnt]=st[l]-'0';
		done[vertCnt][0]=1;
		memo[vertCnt][0]=make_pair(value[vertCnt],value[vertCnt]);
		return vertCnt;
	}
	int bal=0;
	for (int i=l;i<r;i++){
		if (st[i]=='(')
		{
			++bal;
			continue;
		}
		if (st[i]==')'){
			--bal;
			continue;
		}
		if (st[i]=='?'){
			if (bal==1){
				int left_son=parse(l+1,i-1);
				int right_son=parse(i+1,r-1);
				++vertCnt;
				sons[vertCnt]=make_pair(left_son,right_son);
				size[vertCnt]=size[left_son]+size[right_son]+1;
				//cout<<left_son<<"@@"<<right_son<<endl;
				return vertCnt;
			}
		}
	}
}

pair<int,int> solver(int v_id,int cntPlus,int cntMinus){
	int secondVar=cntPlus;
	//cout<<v_id<<cntPlus<<"%"<<cntMinus<<endl;
	if (minusFlag)
		secondVar=cntMinus;
	if (done[v_id][secondVar])
		return memo[v_id][secondVar];
	done[v_id][secondVar]=1;
	memo[v_id][secondVar]=make_pair(1e9,-1e9);

	int left_son=sons[v_id].first;
	int right_son=sons[v_id].second;

	for (int midSign=0;midSign<=1;midSign++){
		if (cntPlus==0&&midSign==0)
			continue;
		if (cntMinus==0&&midSign==1)
			continue;
		int remPlus=cntPlus-(midSign==0);
		int remMinus=cntMinus-(midSign==1);
		for (int plusInFirst=0;plusInFirst<=remPlus;plusInFirst++){
			int plusInSecond=remPlus-plusInFirst;
			int minusInFirst=size[left_son]-plusInFirst;
			int minusInSecond=size[right_son]-plusInSecond;
			if (plusInSecond<0||minusInSecond<0||plusInFirst<0||minusInFirst<0)
				continue;
			pair<int,int> left_side=solver(left_son,plusInFirst,minusInFirst);
			pair<int,int> right_side=solver(right_son,plusInSecond,minusInSecond);
			if (midSign==0) // plus
			{
				memo[v_id][secondVar].first=min(memo[v_id][secondVar].first,left_side.first+right_side.first);
				memo[v_id][secondVar].second=max(memo[v_id][secondVar].second,left_side.second+right_side.second);
			}
			else
			{
				memo[v_id][secondVar].first=min(memo[v_id][secondVar].first,left_side.first-right_side.second);
				memo[v_id][secondVar].second=max(memo[v_id][secondVar].second,left_side.second-right_side.first);
			}
		}
	}
	return memo[v_id][secondVar];
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	cin>>cntPlus;
	cin>>cntMinus;

	if (cntMinus<100)
		minusFlag=1;

	int root=parse(0,st.size()-1);

	pair<int,int> res=solver(root,cntPlus,cntMinus);

	cout<<res.second<<endl;

//	cin.get(); cin.get();
	return 0;
}