#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
void die(string S){puts(S.c_str());exit(0);}
int pr[110];
int main()
{
	int n,m;
	cin>>n>>m;
	map<string,int> M;
	for(int i=0;i<n;i++)
		cin>>pr[i];
	while(m--)
	{
		string S;
		cin>>S;
		M[S]++;
	}
	vector<int> app;
	for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
		app.push_back(it->second);
	sort(pr,pr+n);
	srt(app);
	rev(app);
	int sz=app.size();
	int ans=0;
	for(int i=0;i<sz;i++)
		ans+=pr[i]*app[i];
	cout<<ans<<" ";
	reverse(pr,pr+n);
	ans=0;
	for(int i=0;i<sz;i++)
		ans+=pr[i]*app[i];
	cout<<ans<<endl;
	return 0;
}