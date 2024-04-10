#include<bits/stdc++.h>
using namespace std;
vector<int> seqh,seqt,target;
void print(vector<int> v)
{
	int len=v.size();
	for(int i=0;i<len;i++)
		cout<<v[i]<<" ";
	puts("");
}
void head(vector<int> &p,vector<int> q)
{
	int len=p.size();
	vector<int> t(len);
	for(int i=0;i<len;i++)
		t[i]=p[q[i]];
	p=t;
//	print(p);
}
void tail(vector<int> &p,vector<int> q)
{
	int len=p.size();
	vector<int> t(len);
	for(int i=0;i<len;i++)
		t[q[i]]=p[i];
	p=t;
//	print(p);
}
void die(string s)
{
	puts(s.c_str());
	exit(0);
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> q;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		x--;
		q.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		target.push_back(x);
	}
	for(int i=0;i<n;i++)
		seqh.push_back(i+1);
	seqt=seqh;
	int chead=0,ctail=0;
//	puts("heads:");
	for(int i=0;i<=k+1;i++)
	{
		if(seqh==target)
			break;
		head(seqh,q);
		chead++;
	}
//	puts("tails:");
	for(int i=0;i<=k+1;i++)
	{
		if(seqt==target)
			break;
		tail(seqt,q);
		ctail++;
	}
	if(k<chead&&k<ctail)
		die("NO");
	if(k==chead||k==ctail)
		die("YES");
	if(!chead||!ctail)
		die("NO");
	if(chead==1&&ctail==1)
		die("NO");
	if(chead==1)
	{
		if(k%2)
			die("YES");
		if(ctail<=k&&(k-ctail)%2==0)
			die("YES");
		die("NO");
	}
	if(ctail==1)
	{
		if(k%2)
			die("YES");
		if(chead<=k&&(k-chead)%2==0)
			die("YES");
		die("NO");
	}
	if(((k-chead)%2==0&&chead<=k)||((k-ctail)%2==0&&ctail<=k))
		die("YES");
	die("NO");
	return 0;
}