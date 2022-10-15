#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int wid[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,W;
		cin>>n>>W;
		for(int i=0;i<n;i++)
			cin>>wid[i];
		int lev=0;
		multiset<int> rst;
		for(int i=0;i<n;i++)
			rst.insert(W);
		sort(wid,wid+n);
		reverse(wid,wid+n);
		for(int i=0;i<n;i++)
		{
			multiset<int>::iterator it=rst.lower_bound(wid[i]);
			int tmp=*it-wid[i];
			rst.erase(it);
			rst.insert(tmp);
		}
		for(multiset<int>::iterator it=rst.begin();it!=rst.end();it++)
			if(*it<W)
				lev++;
		cout<<lev<<endl;
	}
	return 0;
}