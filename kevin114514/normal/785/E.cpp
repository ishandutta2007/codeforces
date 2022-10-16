#include<bits/stdc++.h>
#define PART 500
using namespace std;
vector<int> MS[PART];
int Seq[200200];
int N;
long long Sum;
long long Count(int L,int R,int X,bool mod)
{
	int PL=L/PART,PR=R/PART;
	long long Res=0;
	if(PL==PR)
	{
		for(int i=L;i<=R;i++)
			if((X>Seq[i])^mod)
				Res++;
		return Res;
	}
	for(int i=L;i<min((PL+1)*PART,R);i++)
		if((X>Seq[i])^mod)
			Res++;
	for(int i=PL+1;i<PR;i++)
	{
		int pos=lower_bound(MS[i].begin(),MS[i].end(),X)-MS[i].begin();
		if(mod)
			pos=PART-pos;
		Res+=pos;
	}
	for(int i=max(L,PR*PART);i<=R;i++)
		if((X>Seq[i])^mod)
			Res++;
	return Res;
}
int main()
{
	int K;
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		MS[i/PART].push_back(i);
		Seq[i]=i;
	}
	for(int i=0;i<PART;i++)
		sort(MS[i].begin(),MS[i].end());
	while(K--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(a>b)
			swap(a,b);
		if(a==b)
		{
			cout<<Sum<<endl;
			continue;
		}
		Sum-=Count(a+1,b,Seq[a],0);
		Sum-=Count(a,b-1,Seq[b],1);
		MS[a/PART].erase(lower_bound(MS[a/PART].begin(),MS[a/PART].end(),Seq[a]));
		MS[b/PART].erase(lower_bound(MS[b/PART].begin(),MS[b/PART].end(),Seq[b]));
		MS[a/PART].push_back(Seq[b]);
		MS[b/PART].push_back(Seq[a]);
		sort(MS[a/PART].begin(),MS[a/PART].end());
		sort(MS[b/PART].begin(),MS[b/PART].end());
		swap(Seq[a],Seq[b]);
		Sum+=Count(a+1,b,Seq[a],0);
		Sum+=Count(a,b-1,Seq[b],1);
		if(Seq[a]<Seq[b])
			Sum++;
		else	Sum--;
		cout<<Sum<<endl;
	}
	return 0;
}