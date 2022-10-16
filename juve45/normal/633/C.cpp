#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int dp[100006];
string stringmap[100001];
int lgs;
char st[10001];

int n;
char s[1006];


char* strlwr1( char* s )
  {
  char* p = s;
  while (*p = tolower( *p )) p++;
  return s;
  }

int lgst;

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


struct nod
{
	int val;
	//int okdest;
	nod* next[30];
	nod()
	{
		val=-1;
		for(int i=0;i<=28;i++)
			next[i]=0;
	}

}Trie;


void TrieInsert(nod *p, char* s, int k, int lg, int val)
{
	if (k == lg)
	{
		p->val = val;
		return;
	}
	if(p->next[s[k] - 'a']==NULL)
		p->next[s[k] - 'a'] =new(nod);
	TrieInsert(p->next[s[k] - 'a'], s, k+1, lg, val);
}

void search(nod *p, char* s, int inceput, int sfarsit)
{

	if(p->val!=-1)
		dp[inceput]=p->val;
	if(inceput==sfarsit)
		return;

	if(p->next[s[inceput]-'a']!=NULL)
	search(p->next[s[inceput]-'a'], s, inceput+1, sfarsit);
}
vector <int> sol;

void solve()
{
    scanf("%s", &st);
    cin>>n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &s);
		stringmap[i]=s;
		int h=strlen(s);
        strlwr1(s);
        strrev(s);
		TrieInsert(&Trie, s, 0, h, i);
	}

    int g=0;

	lgst=strlen(st);
	search(&Trie, st, 0, lgst);
	for(int i=0;i<lgst;i++)
	{
		if(dp[i]!=0)
			search(&Trie, st, i, lgst);
	}

    int i=lgst;
    while(i!=0)
    {
    sol.push_back(dp[i]);
    i-=stringmap[dp[i]].size();
    }
    for(int i=sol.size()-1;i>=0;i--)
        cout<<stringmap[sol[i]]<<' ';
    cout<<'\n';

}


int main()
{
cin>>lgst;

solve();
return 0;
}