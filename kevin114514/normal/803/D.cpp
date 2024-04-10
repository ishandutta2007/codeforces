#include<bits/stdc++.h>
using namespace std;
vector<int> len;
int N;
bool check(int x)
{
	int pos=0,tmp=x,ans=0;
	while(pos<len.size())
	{
		while(pos<len.size()&&tmp>=len[pos])
		{
			tmp-=len[pos];
			pos++;	
		}
		tmp=x;
		ans++;
	}
	return ans<=N;
}
int main()
{
	cin>>N;
	string S;
	getline(cin,S);
	getline(cin,S);
	int leng=0;
	for(int i=0;i<S.length();i++)
	{
		leng++;
		if(S[i]==' '||S[i]=='-')
		{
			len.push_back(leng);
			leng=0;
		}
	}
	len.push_back(leng);
	int L=*(max_element(len.begin(),len.end())),U=1000000;
	for(int i=0;i<1000;i++)
	{
		int mid=(L+U)/2;
		if(check(mid))
			U=mid;
		else	L=mid+1;
	}
	cout<<L<<endl;
	return 0;
}