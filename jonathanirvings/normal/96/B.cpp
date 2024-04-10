//start of jonathanirvings' template

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
jonathan ganteng banget;

typedef long long LL;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair<int,int> pii;

double EPS = 1e-6;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;

#define DEBUG printf("====TESTING====\n")
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)

//end of jonathanirvings' template

bool lebihbesar(string a,string b)
{
	char x[20];
	char y[20];
	FOR(i,0,a.length()) x[i] = a[i];
	FOR(i,0,b.length()) y[i] = b[i];
	LL tmp1,tmp2;
	sscanf(x,"%I64d",&tmp1);
	sscanf(y,"%I64d",&tmp2);
	return (tmp1>tmp2);
}

int main()
{
	string s;
	string ans = "";
	cin >> s;
	int n = s.length();
	if (n % 2)
	{
		int m = (n+1)/2;
		FORN(i,1,m) ans = ans + '4';
		FORN(i,1,m) ans = ans + '7';
	} else 
	{
		string cek = "";
		FORN(i,1,n/2) cek = cek + '7';
		FORN(i,1,n/2) cek = cek + '4';
		if (lebihbesar(s,cek))
		{
			int m = (n+2)/2;
			FORN(i,1,m) ans = ans + '4';
			FORN(i,1,m) ans = ans + '7';
		} else 
		{
			cek = "";
			FORN(i,1,n/2) cek = cek + '4';
			FORN(i,1,n/2) cek = cek + '7';
			//printf("%s %s\n",s.c_str(),cek.c_str());
			while (lebihbesar(s,cek))
			{
				next_permutation(cek.begin(),cek.end());
			}
			ans = cek;
		}
	}
	printf("%s\n",ans.c_str());
	return 0;
}