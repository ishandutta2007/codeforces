#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

const int N=1e6+5;
int num[N];
map <int,int> mapp;
typedef pair<int,int> pii;
set <pii> seet;
vector <int> vec;

int main()
{
	int t,n,m;
    scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&num[i]);
	    mapp[num[i]]++;
	}
	map<int,int>::iterator it;
	for(it=mapp.begin(); it!=mapp.end();it++) seet.insert(pii(it->second,it->first));
    while(seet.size()>=3)
	{
		pii ans[3];
		for(int i=0;i<3;i++)
		{
			ans[i]=*--seet.end();
			seet.erase(--seet.end());
			vec.push_back(ans[i].second);
		}
		for(int i=0;i<3;i++) if(--ans[i].first) seet.insert(ans[i]);
		sort(vec.rbegin(),vec.rbegin()+3);
	}
	printf("%d\n",vec.size()/3);
	for(int i=0; i<vec.size(); i+=3)
		printf("%d %d %d\n",vec[i],vec[i+1],vec[i+2]);
    return 0;
}