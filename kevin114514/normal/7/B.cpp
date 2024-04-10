#include<bits/stdc++.h>
#define Oper string
using namespace std;
vector<int> Memo;
int Q,M,Memory_Identifier;
int get_int()
{
	int x;
	scanf("%d",&x);
	return x;
}
bool Segment_Empty(int Begin,int Length)
{
	for(int i=Begin;i<Begin+Length;i++)
		if(Memo[i])
			return false;
	return true;
}
void Segment_Alloc(int Begin,int Length,int Identifier)
{
	for(int i=Begin;i<Begin+Length;i++)
		Memo[i]=Identifier;
}
void Alloc(int x)
{
	for(int i=0;i<=M-x;i++)
		if(Segment_Empty(i,x))
		{
			Segment_Alloc(i,x,++Memory_Identifier);
			cout<<Memory_Identifier<<endl;
			return ;
		}
	puts("NULL");
}
void Erase(int x)
{
	const Oper Wrong="ILLEGAL_ERASE_ARGUMENT";
	if(!x)
	{
		puts(Wrong.c_str());
		return ;
	}
	int cnt=0;
	for(int i=0;i<M;i++)
		if(Memo[i]==x)
			cnt++,
			Memo[i]=0;
	if(!cnt)
	{
		puts(Wrong.c_str());
		return ;
	}
}
void Defragment()
{
	int i=0;
	while(i<Memo.size())
	{
		if(!Memo[i])
			Memo.erase(Memo.begin()+i);
		else	i++;
	}
	Memo.resize(M);
}
int main()
{
	cin>>Q>>M;
	for(int i=0;i<M;i++)
		Memo.push_back(0);
	while(Q--)
	{
		Oper O;
		cin>>O;
		if(O=="alloc")
			Alloc(get_int());
		else if(O=="erase")
			Erase(get_int());
		else	Defragment();
	}
}