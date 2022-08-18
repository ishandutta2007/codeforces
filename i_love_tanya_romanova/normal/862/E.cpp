/*
I had a dog he was a mix
He loved me like God
But I was just a kid
The kind mother likes
Now I'm big like the sky
And I'm down sized inside
I'll put this all to rest
I'm just a baby who looks like a boy
I'm getting all depressed
I'm just a baby who looks like a boy

I got my father's sense
And my big brother's pants
And I look like a man
And I feel like an ant
Just speck on the ground
Growing like a weed
A fleck of a seed

I'll put my hands in flames
I'm just a baby who looks like a boy
Feels like I'm born again
I'm just a baby who looks like a boy
I'm just a baby who looks like a boy

And I'll keep hanging from your hair
And I'll keep playing the sand
Just as long as I can
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m,q,a[N],b[N];
long long S[N][2];
long long total_sum;

vector<long long> V;

int count_odd(int x){
	return x/2+x%2;
}
int count_even(int x){
	return x/2;
}

long long make_query(long long val){
	long long res=1e18;
	int id=lower_bound(V.begin(),V.end(),val)-V.begin();
	if (id!=V.size())
		res=min(res,V[id]-val);
	if (id!=0){
		--id;
		res=min(res,val-V[id]);
	}
	return res;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>q;

	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
	}

	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
			total_sum+=a[i];
		else
			total_sum-=a[i];
	}

	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<=1;j++)
		{
			S[i][j]=S[i-1][j];
		}
		S[i][i%2]+=b[i];
	}

	//cout<<"@"<<total_sum<<endl;

	for (int i=0;i<=m-n;i++){
		long long cur_sum=0;
		cur_sum+=S[i+n][1-i%2];//with + sign
		cur_sum-=S[i][1-i%2];
		//cout<<cur_sum<<endl;
		cur_sum-=S[i+n][i%2];
		cur_sum+=S[i][i%2]; // with - sign
		//cout<<cur_sum<<endl;
		V.push_back(cur_sum);
	}

	sort(V.begin(),V.end());

	cout<<make_query(total_sum)<<"\n";

	for (int i=1;i<=q;i++){
		int l,r,val;
		cin>>l>>r>>val;
		int cnt_odd=count_odd(r)-count_odd(l-1);
		int cnt_even=count_even(r)-count_even(l-1);
		total_sum+=cnt_odd*1ll*val;
		total_sum-=cnt_even*1ll*val;
		cout<<make_query(total_sum)<<"\n";
	}
	cin.get(); cin.get();
	return 0;
}