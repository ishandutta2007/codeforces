/*
All that she wanna do is break my heart
Seems to me we were laughing while apart
Time was waitin', you took a pile and put me down
Well I've some news for you, it's gonna turn you around
I got no time for those crazy letters
Any games you want to play
'Cause a love like mine, it's gonna take some time
You can't save it for a rainy day

Do you know, do you know, do you know
What I'm trying to say
Love's not a game
It's never the same
You've got to live your life from day to day

Lonely days are sad it starts me black
Can I get right down, maybe I take you back
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

vector<int> moves;
int SG[N];
map<vector<int> ,int> sg_memo;

int precalc_sg(int val)
{
	if (val==0)
		return 0;
	vector<int> cur;
	cur.push_back(val);
	for (int i=0;i<moves.size();i++)
	{
		cur.push_back(moves[i]);
	}
	sort(cur.begin()+1,cur.end());
	if (sg_memo.find(cur)!=sg_memo.end())
		return sg_memo[cur];
	vector<int> reach;
	reach.resize(65);
	vector<int> ban;
	ban.resize(65);
	for (int j=0;j<reach.size();j++)
	{
		reach[j]=0;
		ban[j]=0;
	}
	for (int j=1;j<cur.size();j++)
	{
		ban[cur[j]]=1;
	}
	for (int j=1;j<=val;j++)
	{
		if (ban[j])
			continue;
		moves.push_back(j);
		int v=precalc_sg(val-j);
		moves.pop_back();
		reach[v]=1;
	}
	int q=0;
	while (reach[q])
		++q;
	sg_memo[cur]=q;
	return q;
}

int n;
int ANS[100500];

void parse_ans(string st)
{
	for (int i=0;i<st.size();i++)
	{
		if (st[i]>='0'&&st[i]<='9')
			continue;
		st[i]=' ';
	}
	stringstream s(st);
	for (int i=1;i<=60;i++)
	{
		s>>ANS[i];
	}
}

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*for (int i=1;i<=60;i++)
	{
		moves.clear();
		int here=precalc_sg(i);
		cout<<i<<" "<<here<<endl;
	}

	for (int i=1;i<=60;i++)
	{
		vector<int> here;
		here.push_back(i);
		SG[i]=sg_memo[here];
		cout<<SG[i]<<",";
	}
*/

	parse_ans("1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10");

	int res=0;

	scanf("%d",&n);
	for (;n;--n)
	{
		int val;
		scanf("%d",&val);
		res^=ANS[val];
	}

	if (res==0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}