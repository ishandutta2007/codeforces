#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[666];
string s1,s2;

bool fuck(string &s,int sb){
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]=='B'){
			s.erase(i,1);
			f[sb]^=1;
			return 1;
		}
		if(s.substr(i,2)=="AA"||s.substr(i,2)=="CC"){
			s.erase(i,2);
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		f[1]=f[2]=0;
		
		while(fuck(s1,1)){
			//cout<<s1<<endl;
		}
		while(fuck(s2,2)){
			//cout<<s2<<endl;
		}
		cout<<(( (s1==s2) && (f[1]==f[2]) )?"YES":"NO")<<'\n';
	}
}