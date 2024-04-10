#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
string S;
bool vis[26];
int cnt[26];
void solve()
{
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	cin>>S;
	rev(S);
	string T;
	for(int i=0;i<S.length();i++)
		if(!vis[S[i]-'a'])
		{
			T+=S[i];
			vis[S[i]-'a']=1;
		}
	rev(S);
	rev(T);
	for(int i=0;i<S.length();i++)
		cnt[S[i]-'a']++;
	for(int i=0;i<T.length();i++)
		cnt[T[i]-'a']/=(i+1);
	string u;
	for(int i=0;i<S.length();i++)
	{
		u+=S[i];
		cnt[S[i]-'a']--;
		if(*min_element(cnt,cnt+26)<0)
		{
			puts("-1");
			return ;
		}
		if(*max_element(cnt,cnt+26)==0)
			break;
	}
	string v=u,w;
	for(int i=0;i<T.length();i++)
	{
		w+=v;
		string x;
		for(int j=0;j<v.length();j++)
			if(v[j]!=T[i])
				x+=v[j];
		v=x;
	}
	if(w!=S)
		puts("-1");
	else	cout<<u<<" "<<T<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}