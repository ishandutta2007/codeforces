#include<bits/stdc++.h>
using namespace std;
int main()
{
	int L;
	cin>>L;
	string S,T;
	cin>>S>>T;
	multiset<int> M,N;
	for(int i=0;i<L;i++)
		if(S[i]=='1'&&T[i]=='0')
			M.insert(i);
		else if(S[i]=='0'&&T[i]=='1')
			N.insert(i);
	if((int)(M.size())!=(int)(N.size()))
	{
		puts("-1");
		return 0;
	}
	int Ans=0;
	while(!M.empty()&&!N.empty())
	{
		if(*N.begin()<*M.begin())
			swap(M,N);
		int x=0;
		while(true)
		{
			multiset<int>::iterator it1=M.lower_bound(x);
			if(it1==M.end())
				break;
			x=*it1;
			multiset<int>::iterator it2=N.lower_bound(x);
			if(it2==N.end())
				break;
			x=*it2;
			M.erase(it1);
			N.erase(it2);
		}
		Ans++;
	}
	cout<<Ans<<endl;
	return 0;
}