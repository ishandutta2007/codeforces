#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
map<string,bool> mp2;
string s[100500];

bool chk(string s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	return s1==s;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		mp2.clear();
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>s[i];
		}
		for(i=1;i<=n;i++){
			if(chk(s[i])){
				cout<<"YES\n";goto aaa;
			}
			string NMSL=s[i],NMSL2;
			reverse(NMSL.begin(),NMSL.end());
			for(j=0;j<=NMSL.size();j++){
				for(k=1;k<=4;k++){
					NMSL2=NMSL.substr(j,k);
					if(chk(NMSL2+s[i])&&mp2.count(NMSL2)){
						cout<<"YES\n";goto aaa;
					}
				}
			}
			for(j='a';j<='z';j++){
				if(chk(NMSL+(char)j+s[i])&&mp2.count(NMSL+(char)j)){
					cout<<"YES\n";goto aaa;
				}
			}
			mp2[s[i]]=1;
		}
		cout<<"NO\n";
		aaa:;
	}
}