#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
pair<int,int>s[N];
int t[N];//pos,idx;
int l[N],r[N],d[N];
int n,q;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)s[i].second=i+1;
	for(int i=0;i<n;++i)cin>>s[i].first;
	for(int i=0;i<n;++i)cin>>t[i];
	sort(s,s+n);
	sort(t,t+n);
	ll pref=0;
	for(int i=0;i<n;++i)if((pref+=(s[i].first=t[i]-s[i].first))<0){cout<<"NO\n";return 0;}
	if(pref){cout<<"NO\n";return 0;}
	vector<pair<int,int>>plus;
	for(int i=0;i<n;++i){
		if(s[i].first>0){plus.push_back(s[i]);continue;}
		while(s[i].first){
			auto p=plus.back();plus.pop_back();
			l[q]=p.second;r[q]=s[i].second;d[q]=min(p.first,-s[i].first);
			s[i].first+=d[q];p.first-=d[q];++q;
			if(p.first)plus.push_back(p);
		}
	}
	cout<<"YES\n"<<q<<'\n';
	for(int i=0;i<q;++i)cout<<l[i]<<" "<<r[i]<<" "<<d[i]<<'\n';
}