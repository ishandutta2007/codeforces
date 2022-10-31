#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,yes;
string s[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<string,int> mp;
		string res;
		for(i=1;i<=n;i++){
			cin>>s[i];
			mp[s[i]]=1;
		}
		for(i=1;i<=n;i++){
			m=s[i].size();
			string l,r;
			yes=0;
			for(j=0;j<m-1;j++){
				l=r="";
				for(k=0;k<=j;k++)l+=s[i][k];
				for(k=j+1;k<=m-1;k++)r+=s[i][k];
				if(mp[l]&&mp[r])yes=1;
			}
			if(yes)res+="1";
			else res+="0";
		}
		cout<<res<<endl;
	}
}