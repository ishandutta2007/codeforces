#include <bits/stdc++.h>
using namespace std;

struct trie
{
	int ch[128],id;
}t[100005];
int cnt;

void ins(string s,int id)
{
	int x=1,i;
	for (i=0;i<s.length();i++)
	{
		if (!t[x].ch[s[i]]) t[x].ch[s[i]]=++cnt;
		x=t[x].ch[s[i]];
	}
	
	t[x].id=id;
	
}

int query(string s)
{
	int x=1,i;
	for (i=0;i<s.length();i++)
	{
		x=t[x].ch[s[i]];
	}
	
	return t[x].id;
	
}

string ans[100005],st;
int n,m,i,j,c;

int main()
{
	ios_base::sync_with_stdio(0);
	
	while (getline(cin,st)&&st!="\\begin{thebibliography}{99}")
	{
		for (i=0;i<st.length();i++)
		{
			if (st[i]=='\\')
			{
				i+=6;
				string s;
				while (st[i]!='}')
				{
					s.push_back(st[i++]);
				}
				
				//cerr<<s<<endl;
				ins(s,++c);
			}
			
		}
		
	}
	
	bool f=1;
	int cc=0;
	
	while (getline(cin,st)&&st!="\\end{thebibliography}")
	{
		i=9;
		string s;
		while (st[i]!='}')
		{
			s.push_back(st[i++]);
		}
		
		//cerr<<s<<endl;
		int t=query(s);
		if (t!=++cc) f=0;
		ans[t]=st;
		
	}
	
	if (f){puts("Correct");return 0;}
	
	puts("Incorrect");
	puts("\\begin{thebibliography}{99}");
	for (i=1;i<=c;i++) puts(ans[i].c_str());
	puts("\\end{thebibliography}");
	
	return 0;
}