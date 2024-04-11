#include<bits/stdc++.h>
using namespace std;

int f(string s,string n){
	int p1=s.size()-1,p2=n.size()-1;
	int num=0;
	while(p1>=0&&p2>=0){
		if(s[p1]==n[p2]){
			p1--;p2--;
		}
		else{
			p1--;
			num++;
		}
	}
	if(p2==-1)return num;
	return 50;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<min({f(s,"00"),f(s,"25"),f(s,"50"),f(s,"75")})<<endl;
	}
}