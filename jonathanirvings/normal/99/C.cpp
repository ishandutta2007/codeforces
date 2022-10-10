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

bool sama(string a,string b)
{
	return (a == b);
}

string putaratas(string a)
{
	char tmp;
		tmp = a[0];
		a[0] = a[4];
		a[4] = a[5];
		a[5] = a[1];
		a[1] = tmp;
	return a;
}

string putarbawah(string a)
{
	char tmp;
		tmp = a[0];
		a[0] = a[1];
		a[1] = a[5];
		a[5] = a[4];
		a[4] = tmp;
	return a;
}

string putarkiri(string a)
{
	char tmp;
		tmp = a[0];
		a[0] = a[2];
		a[2] = a[5];
		a[5] = a[3];
		a[3] = tmp;
	return a;
}

string putarkanan(string a)
{
	char tmp;
		tmp = a[0];
		a[0] = a[3];
		a[3] = a[5];
		a[5] = a[2];
		a[2] = tmp;
	return a;
}

string puter(string a)
{
	char tmp;
	tmp = a[1];
	a[1] = a[2];
	a[2] = a[4];
	a[4] = a[3];
	a[3] = tmp;
	return a;
}

char x[10];
string s;

int main()
{
	int ans = 0;
	scanf("%s",x);
	s = x;
	vector <string> sudah;
	sort(s.begin(),s.end());
	ans++;
	sudah.pb(s);
	while (next_permutation(s.begin(),s.end()))
	{
		//printf("%s %d\n",s.c_str(),ans);
		bool bisa = 1;
		FOR(i,0,ans)
		{
			string c1 = s;
			string c2 = sudah[i];
			FOR(i,0,4) 
			{
				FOR(j,0,4)
				{
					FOR(k,0,4)
					{
						if (c1 == c2) bisa = 0;
						if (!bisa) break;
						c1 = putaratas(c1);
					}
					if (!bisa) break;
					c1 = puter(c1);
				}
				if (!bisa) break;
				c1 = putarkiri(c1);
			}
			if (!bisa) break;
		}
		if (bisa)
		{
			ans++;
			sudah.pb(s);
		}
	}
	printf("%d\n",ans);
	//FOR(i,0,ans) printf("%s\n",sudah[i].c_str());
	return 0;
}