#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5*2+5;
string oper;
long long dam[MAXN];
long long use[MAXN];
inline int search(int start_pos,char c)
{
	for(;oper[start_pos]==c;start_pos++);
	return start_pos-1;
}
long long maxnum(int start_pos,int end_pos,int k)
{
	long long sum=0;
	int len=end_pos-start_pos+1;
	for(int i=start_pos;i<=end_pos;i++)
		sum+=dam[i],use[i-start_pos]=dam[i];
	sort(use,use+len);
	for(int i=0;i<len-k;i++)
		sum-=use[i];
	return sum;
}
int main()
{
	int pos=0;
	long long cnt=0;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%I64d",&dam[i]);
	cin>>oper;
	while(pos<n)
	{
		int x=pos;
		pos=search(pos+1,oper[pos]);
		cnt+=maxnum(x,pos,k);
		pos++;
	}
	printf("%I64d\n",cnt);
	return 0;
}