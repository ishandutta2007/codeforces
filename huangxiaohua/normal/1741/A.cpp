#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int x,y;

int fuck(string s){
	int i,j,k;
	k=s.size()*100;
	if(s.back()=='S'){
		k*=-1;
	}
	else if(s.back()=='M'){
		k=1;
	}
	return k;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		if(fuck(s1)<fuck(s2)){
			cout<<"<\n";
		}
		else if(fuck(s1)==fuck(s2)){
			cout<<"=\n";
		}
		else if(fuck(s1)>fuck(s2)){
			cout<<">\n";
		}
	}
}