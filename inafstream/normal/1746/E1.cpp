#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int cnt=0,_;
bool flg=0;
int guess()
{
	char c;while((c=getchar())!='('&&c!=')');
	if(c==')') return 1; else return 0;
//	return 1;
}
int quest()
{
	char c;while((c=getchar())!='S'&&c!='O');
	if(c=='S') return 1; else return 0;
//	return _^=1;
}
int query(vector<int> v)
{
	cnt++;
	printf("? %d",(int)v.size());
	for(int u:v) printf(" %d",u);
	puts("");fflush(stdout);
	return quest();
/*	bool chk=0;for(int u:v) chk|=(u==5);
	if(flg){flg=0;return chk;}
	flg=rand()%2;if(flg) return !chk;else return chk;*/
}

int f[105][105];
int a[105][105],b[105][105];

void solve(vector<int> v)
{
	if(v.size()<=2)
	{
		for(int x:v)
		{
			printf("! %d\n",x);fflush(stdout);
			if(guess()) return;
		}
		assert(0);
	}

	if(v.size()==3)
	{
		if(query({v[0]}))
		{
			printf("! %d\n",v[0]);fflush(stdout);
			if(guess()) return;
			if(query({v[1]})) printf("! %d\n",v[1]);else printf("! %d\n",v[2]);fflush(stdout);
			assert(guess());return;
		}
		else
		{
			if(query({v[0]}))
			{
				printf("! %d\n",v[0]);fflush(stdout);
				if(guess()) return;
				if(query({v[1]})) printf("! %d\n",v[1]);else printf("! %d\n",v[2]);fflush(stdout);
				assert(guess());return;
			}
			else {v.erase(v.begin());solve(v);return;}
		}
	}
}

void solve(vector<int> vt,vector<int> vf)
{
	if(vt.size()+vf.size()<=3)
	{
		vector<int> v=vt;
		for(int u:vf) v.push_back(u);
		solve(v);
		return;
	}

	int x=vt.size()/2,y=vf.size()/2;
	if(vt.size()+vf.size()<=100) x=a[vt.size()][vf.size()],y=b[vt.size()][vf.size()];
	vector<int> vt0,vt1,vf0,vf1;
	for(int i=0;i<x;i++) vt0.push_back(vt[i]);
	for(int i=x;i<vt.size();i++) vt1.push_back(vt[i]);
	for(int i=0;i<y;i++) vf0.push_back(vf[i]);
	for(int i=y;i<vf.size();i++) vf1.push_back(vf[i]);

	vector<int> v0=vt0;for(int u:vf0) v0.push_back(u);
	vector<int> nvt,nvf;
	if(query(v0))
	{
		for(int u:vt0) nvt.push_back(u);
		for(int u:vf0) nvt.push_back(u);
		for(int u:vt1) nvf.push_back(u);
	}
	else
	{
		for(int u:vt1) nvt.push_back(u);
		for(int u:vf1) nvt.push_back(u);
		for(int u:vt0) nvf.push_back(u);
	}
	solve(nvt,nvf);
}

void solve()
{
	int n;
	scanf("%d",&n);
	vector<int> v0,v1;v1.clear();
	rep(i,n) v0.push_back(i);
	solve(v0,v1);
}

int main()
{
	unsigned int tt=time(NULL);
	srand(tt);cerr<<tt<<endl;

	for(int k=4;k<=100;k++)
	{
		for(int i=0,j=k;j>=0;i++,j--) f[i][j]=1e9;
		for(int i=0,j=k;j>=0;i++,j--)
		{
			for(int x=0;x<=i;x++)for(int y=0;y<=j;y++)
			{
				int val=max(f[x+y][i-x],f[i+j-x-y][x])+1;
				if(val<f[i][j]) f[i][j]=val,a[i][j]=x,b[i][j]=y;
			}
		}
	}

	int t=1;
	while(t--)
	{
		solve();
		cerr<<cnt<<endl;
	}
	return 0;
}