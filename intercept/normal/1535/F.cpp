#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ans=0,sum;
int p[200009];
string s,h;
map<string ,vector<string>>mp;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		m=s.length();
		h=s;
		sort(h.begin(),h.end());
		mp[h].push_back(s);
	}
	for(auto o:mp){
		auto v=o.second;
		int S=v.size();
		sort(v.begin(),v.end());
		for(int i=0;i<S;++i){
			for(int j=m-2;j>=0;--j)p[j]=v[i][j]<=v[i][j+1]?p[j+1]+1:0;
			for(int j=i+1;j<S;++j){
				int l=0,r=m-1;
				while(v[i][l]==v[j][l])l++;
				while(v[i][r]==v[j][r])r--;
				if(l+p[l]>=r)ans++;
				else ans+=2;
			}
		}
		ans+=1337ll*S*sum;
		sum+=S;
	}
	cout<<ans<<endl;
	return 0;
}