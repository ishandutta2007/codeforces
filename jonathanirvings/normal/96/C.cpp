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

int n;
string s,terot[105];
char x[105];
bool besar[105];
bool ganti[105];
char letter;

string lower(string a)
{
	int tmp = a.length();
	FOR(i,0,tmp)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
	}
	return a;
}

int main()
{
	scanf("%d\n",&n);
	FORN(i,1,n)
	{
		scanf("%s",x);
		terot[i] = x;
		terot[i] = lower(terot[i]);
	}
	scanf("%s",x);
	s = x;
	scanf("\n%c",&letter);
	//FORN(i,1,n) printf("%s\n",terot[i].c_str());
	if (letter >= 'A' && letter <= 'Z')
	{
		letter = letter + 32;
	}
	int len = s.length();
	FOR(i,0,len)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') besar[i] = 1;
		else besar[i] = 0;
	}
	s = lower(s);
	FORN(i,0,100) ganti[i] = 0;
	FOR(i,0,len)
	{
		FORN(j,1,n)
		{
			string cek = "";
			if (i + terot[j].length() - 1 <= len)
			{
				FORN(k,i,i+terot[j].length()-1) cek = cek + s[k];
				//cout << j << cek << " " << terot[j] << endl;
				if (cek == terot[j])
					FORN(k,i,i+terot[j].length()-1) ganti[k] = 1;
			}
		}
	}
	string ans = "";
	FOR(i,0,len)
	{
		if (ganti[i]) 
		{
			if (s[i] == letter)
			{
				if (letter != 'a') ans = ans + 'a'; else
					ans = ans + 'b';
			} else ans = ans + letter;
		}
		else ans = ans + s[i];
	}
	FOR(i,0,len) if(besar[i]) ans[i] = ans[i] - 32;
	printf("%s\n",ans.c_str());
	//printf("%c\n",letter);
	return 0;
}