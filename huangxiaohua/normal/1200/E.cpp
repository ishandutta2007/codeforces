#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,m1;
string s,res;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin>>t>>res;res="0"+res;t--;
	while(t--){
		cin>>s;s="0"+s;
		m=s.size();
		vector<int> vv(m);v=vv;k=0;
		for(i=2;i<m;i++){
			while(k&&s[k+1]!=s[i]){k=v[k];}
			if(s[k+1]==s[i]){k++;}
			v[i]=k;
		}
		k=0;m1=res.size();
		for(i=max(1,m1-m);i<m1;i++){
			while(k&&s[k+1]!=res[i]){k=v[k];}
			if(s[k+1]==res[i]){k++;}
			if(i!=m1-1&&k==m-1){k=v[k];}
		}
		res+=s.substr(k+1);
	}
	cout<<res.substr(1);
}