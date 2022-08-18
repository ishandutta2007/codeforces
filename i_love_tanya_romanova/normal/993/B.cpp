/*
Stop your screaming, get out of my way
Your lips are moving they got nothing to say
Always steaming but you're cold to the bone
So negative, just leave me alone

No more crying, no more dying
No more bleeding me
No more screaming, no deceiving
No more bleeding me

You smell the bleeding, moving in for the kill
The way you treat me, you make me ill
Push me to the maximum, do it again and again
But I won't let you suck me in
Look at your mother, your father too
Same damn same shit that you put me through
But I'm stronger and I got the balls
I ain't sticking around for it all

Something's coming over me tonight
It's time to take this wrong and make it right
No time to lose before I die
This is my very last good bye

You say you loved me, you say that you cared
But what you need is a billionaire
You sat on your ass and now you wonder why
You need some money but you bled me dry
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int n,m,for1[100][100][15],for2[100][100][15],votes_for[1000];
int has[5][100][100];

bool bad_pairs(int a,int b,int c,int d){
	vector<int> v;
	if (a==c||a==d)
		v.push_back(a);
	if (b==c||b==d)
		v.push_back(b);
	return (v.size()!=1);
}

int common(int a,int b,int c,int d){
	vector<int> v;
	if (a==c||a==d)
		v.push_back(a);
	if (b==c||b==d)
		v.push_back(b);
	return (v[0]);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		if (a>b)
			swap(a,b);
		has[1][a][b]=1;
	}
	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if (a>b)
			swap(a,b);
		has[2][a][b]=1;
	}

	for (int v1=1;v1<=9;v1++){
		for (int v2=v1+1;v2<=9;v2++){
			for (int v3=1;v3<=9;v3++){
				for (int v4=v3+1;v4<=9;v4++){
					if (bad_pairs(v1,v2,v3,v4))
						continue;
					if (has[1][v1][v2]==0)
						continue;
					if (has[2][v3][v4]==0)
						continue;
					int T=common(v1,v2,v3,v4);
					++votes_for[T];
					for1[v1][v2][T]++;
					for2[v3][v4][T]++;
				}
			}
		}
	}

	int candidates=0;
	int solution;
	for (int i=1;i<=9;i++){
		if (votes_for[i])
			++candidates,
			solution=i;
	}

	if (candidates==1){
		cout<<solution<<endl;
		return 0;
	}

	for (int i=1;i<=9;i++){
		for (int j=1;j<=9;j++){
			int s=0;
			for (int q=1;q<=9;q++){
				if (for1[i][j][q])
					++s;
			}
			if (s>1)
			{
				cout<<-1<<endl;
				return 0;
			}
			s=0;
			for (int q=1;q<=9;q++){
				if (for2[i][j][q])
					++s;
			}
			if (s>1){
				cout<<-1<<endl;
				return 0;
			}
		}
	}

	cout<<0<<endl;

//	cin.get(); cin.get();
	return 0;
}