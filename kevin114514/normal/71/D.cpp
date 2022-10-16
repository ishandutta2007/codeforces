#include<bits/stdc++.h>
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
char rank_[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
map<char,int> Number;
char suit[]={'C','D','H','S'};
int board[18][18],tmp[18][18];
int n,m;
bool used[54];
inline int index(string card)
{
	if(card[0]=='J'&&(card[1]=='1'||card[1]=='2'))
		return 52+card[1]-'1';
	return Number[card[0]]*4+Number[card[1]];
}
inline string card(int index)
{
	string ret;
	if(index>=52)
	{
		ret+='J';
		ret+=('1'+index-52);
		return ret;
	}
	ret+=rank_[index/4];
	ret+=suit[index%4];
	return ret;
}
inline bool check(int x,int y)
{
	bool f1=true,f2=true;
	bool app[13]={0};
	if(x+3>n||y+3>m)
		return false;
	for(int i=x;i<x+3;i++)
		for(int j=y;j<y+3;j++)
		{
			if(app[board[i][j]/4])
				f1=false;
			app[board[i][j]/4]=true;
			if(board[i][j]%4!=board[x][y]%4)
				f2=false;
		}
	return f1||f2;
}
inline bool inSquare(int sr,int sc,int x,int y)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int I=0;I<3;I++)
				for(int J=0;J<3;J++)
					if(sr+i==x+I&&sc+j==y+J)
						return true;
	return false;
}
inline vector<pair<int,int> > check()
{
	vector<pair<int,int> > ret;
	for(int i=0;i<n-2&&sz(ret)<2;i++)
		for(int j=0;j<m-2&&sz(ret)<2;j++)
		if(check(i,j))
		{
			bool f=true;
			for(int _=0;_<sz(ret);_++)
				f^=inSquare(ret[_].first,ret[_].second,i,j);
			if(f)
				ret.pb(mp(i,j));
		}
	return ret;
}
inline pair<int,int> Find(int index)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(board[i][j]==index)
				return mp(i,j);
	return mp(-1,-1);
}
inline void replace(pair<int,int> p,int index)
{
	board[p.first][p.second]=index;
	return ;
}
inline bool Find2(int index)
{
	pair<int,int> p=Find(index);
	return ~p.first;
}
int cnt;
void init()
{
//	cout<<inSquare(0,0,1,3)<<endl;
	for(int i=0;i<13;i++)
		Number[rank_[i]]=i;
	for(int i=0;i<4;i++)
		Number[suit[i]]=i;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			string S;
			cin>>S;
			board[i][j]=index(S);
			if(board[i][j]>51)
				cnt++;
			tmp[i][j]=board[i][j];
			used[board[i][j]]=1;
		}
}
int main()
{
	init();
	if(!cnt)
	{
		vector<pair<int,int> > sqr=check();
		if(sz(sqr)<2)
			die("No solution.");
		puts("Solution exists.");
		puts("There are no jokers.");
		printf("Put the first square to (%d, %d).\n",sqr[0].first+1,sqr[0].second+1);
		printf("Put the second square to (%d, %d).\n",sqr[1].first+1,sqr[1].second+1);
		return 0;
	}
	else if(cnt==1)
	{
		int joker=Find2(52)?52:53;
		pair<int,int> p=Find(joker);
		for(int i=0;i<52;i++)
			if(!used[i])
			{
				replace(p,i);
				vector<pair<int,int> > sqr=check();
				if(sz(sqr)==2)
				{
					puts("Solution exists.");
					string a=card(joker),b=card(i);
					printf("Replace %s with %s.\n",a.c_str(),b.c_str());
					printf("Put the first square to (%d, %d).\n",sqr[0].first+1,sqr[0].second+1);
					printf("Put the second square to (%d, %d).\n",sqr[1].first+1,sqr[1].second+1);
					return 0;
				}
			}
		puts("No solution.");
		return 0;
	}
	else
	{
		pair<int,int> p1=Find(52),p2=Find(53);
		for(int i=0;i<52;i++)
		for(int j=0;j<52;j++)
			if(!used[i]&&!used[j]&&i!=j)
			{
				replace(p1,i);
				replace(p2,j);
				vector<pair<int,int> > sqr=check();
				if(sz(sqr)==2)
				{
					puts("Solution exists.");
					string a=card(i),b=card(j);
					printf("Replace J1 with %s and J2 with %s.\n",a.c_str(),b.c_str());
					printf("Put the first square to (%d, %d).\n",sqr[0].first+1,sqr[0].second+1);
					printf("Put the second square to (%d, %d).\n",sqr[1].first+1,sqr[1].second+1);
					return 0;
				}
			}
		puts("No solution.");
		return 0;
	}
	return 0;
}