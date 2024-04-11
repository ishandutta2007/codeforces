#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007

string nxt(string &s,int k){
	int sn=LLONG_MAX;
	for(int i=s.size();i>=0;i--){
		//cout<<i<<" "<<sn<<" "<<k<<endl;
		//checo se  possvel
		set<char> caras;
		for(int j=0;j<i;j++){
			caras.insert(s[j]);
		}
		if(i==s.size() && caras.size()<=k)return s;
		else if(i==s.size())continue;
		if(caras.size()<k){
			//cout<<"entrou"<<" "<<i<<endl;
			string s2=s;
			if(s2[i]=='9')continue;
			s2[i]=min(char('9'),char(s2[i]+1));
			caras.insert(char(s2[i]));
			for(int j=i+1;j<s.size();j++){
				if(caras.size()==k)s2[j]=*caras.begin();
				else s2[j]='0';
			}
			sn=min(sn,stoll(s2));
		}
		else if(caras.size()==k){
			string s2=s;
			if(caras.upper_bound(s2[i])==caras.end())continue;
			s2[i]=*caras.upper_bound(s2[i]);
			for(int j=i+1;j<s.size();j++)s2[j]=*caras.begin();
			sn=min(sn,stoll(s2));
		}
	}
	return to_string(sn);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		string s;
		int k;
		cin>>s>>k;
		cout<<nxt(s,k)<<endl;
	}
	
}