#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

void read(bool &b,deque<int> &q)
{
	string s;
	cin>>s;
	char last=s[0];
	b=last=='b';
	q.push_back(1);
	rep(i,1,(int)s.size()-1)
	if(s[i]==last)++q.back();
	else 
	{
		last=s[i];q.push_back(1);
	}
}

vector<pii>ans;
void out()
{
	printf("%d\n",(int)ans.size());
	for(auto pr:ans)printf("%d %d\n",pr.first,pr.second);
	exit(0);
}
bool a;
void PB(int x,int y)
{
	if(a)swap(x,y);
	ans.push_back(pii(x,y));
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
#endif
	bool b[2];
	deque<int>q[2];
	rep(i,0,1)read(b[i],q[i]);
	a=q[1].size()>q[0].size();
	if(q[a].size()==1)out();
	if(b[0]==b[1])
	{
		if(q[a^1].size()>1&&(q[a].size()-q[a^1].size())%4==3)
		{
			PB(q[a][0]+q[a][1],q[a^1][0]);
			q[a^1][1]+=q[a][1];
			q[a][2]+=q[a^1][0];
			q[a^1][0]=q[a][0];
			q[a].pop_front();q[a].pop_front();
		}
		int k=((int)q[a].size()-1-(int)q[a^1].size() +1)/4;
		int x=0;
		per(i,2*k-1,0)
		{
			x+=q[a][i];
			q[a^1].push_front(q[a][i]);
		}
		rep(i,0,2*k-1)q[a].pop_front();
		PB(x+q[a][0],0);
		q[a^1][2*k]+=q[a][0];
		q[a].pop_front();
	}
	a=q[1].size()>q[0].size();
	if(q[a].size()==1)out();
	if(q[a^1].size()==1)
	{
		int k=((int)q[a].size()-(int)q[a^1].size()-1 +1)/4;
		int x=0;
		per(i,2*k-1,0)
		{
			x+=q[a][i];
			q[a^1].push_front(q[a][i]);
		}
		rep(i,0,2*k-1)q[a].pop_front();
		PB(x+q[a][0],q[a^1][2*k]);
		q[a][1]+=q[a^1][2*k];
		q[a^1][2*k]=q[a][0];
		q[a].pop_front();
	}
	else
	{
		int k=((int)q[a].size()-(int)q[a^1].size() +1)/4;
		int tmp=q[a^1][0];
		q[a^1].pop_front();
		
		int x=0;
		per(i,2*k-1,0)
		{
			x+=q[a][i];
			q[a^1].push_front(q[a][i]);
		}
		rep(i,0,2*k-1)q[a].pop_front();
		PB(x+q[a][0],tmp);
		q[a][1]+=tmp;
		q[a^1][2*k]+=q[a][0];
		q[a].pop_front();
	}
	a=q[1].size()>q[0].size();
	while(q[a^1].size()>1)
	{
		PB(q[a][0],q[a^1][0]);
		q[a][1]+=q[a^1][0];
		q[a^1][1]+=q[a][0];
		q[a].pop_front();q[a^1].pop_front();
	}
	while(q[a].size()>1)
	{
		PB(q[a][0],q[a^1][0]);
		q[a][1]+=q[a^1][0];
		q[a^1][0]=q[a][0];
		q[a].pop_front();
	}
	out();
}