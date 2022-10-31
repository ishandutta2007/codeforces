#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,res;

map<string,int> mp;
string s="..........";

void dfs(string s,int x){
	if(mp.count(s))return;
	mp[s]=x;
	
	if(s[1]=='0'&&s[2]=='0'&&s[3]=='0'){mp[s]=2;return;}
	if(s[1]=='X'&&s[2]=='X'&&s[3]=='X'){mp[s]=1;return;}
	
	if(s[4]=='0'&&s[5]=='0'&&s[6]=='0'){mp[s]=2;return;}
	if(s[4]=='X'&&s[5]=='X'&&s[6]=='X'){mp[s]=1;return;}
	
	if(s[7]=='0'&&s[8]=='0'&&s[9]=='0'){mp[s]=2;return;}
	if(s[7]=='X'&&s[8]=='X'&&s[9]=='X'){mp[s]=1;return;}
	
	if(s[1]=='0'&&s[4]=='0'&&s[7]=='0'){mp[s]=2;return;}
	if(s[1]=='X'&&s[4]=='X'&&s[7]=='X'){mp[s]=1;return;}
	
	if(s[2]=='0'&&s[5]=='0'&&s[8]=='0'){mp[s]=2;return;}
	if(s[2]=='X'&&s[5]=='X'&&s[8]=='X'){mp[s]=1;return;}
	
	if(s[3]=='0'&&s[6]=='0'&&s[9]=='0'){mp[s]=2;return;}
	if(s[3]=='X'&&s[6]=='X'&&s[9]=='X'){mp[s]=1;return;}
	
	if(s[1]=='0'&&s[5]=='0'&&s[9]=='0'){mp[s]=2;return;}
	if(s[1]=='X'&&s[5]=='X'&&s[9]=='X'){mp[s]=1;return;}
	
	if(s[3]=='0'&&s[5]=='0'&&s[7]=='0'){mp[s]=2;return;}
	if(s[3]=='X'&&s[5]=='X'&&s[7]=='X'){mp[s]=1;return;}
	
	if(s.find('.',1)==s.npos){
		mp[s]=-1;return;
	}
	
	for(int i=1;i<=9;i++){
		if(s[i]!='.')continue;
		if(x==1024)s[i]='X',dfs(s,x^1);
		else s[i]='0',dfs(s,x^1);
		s[i]='.';
	}
}

int main(){
	dfs(s,1024);
	string s=".",sb;
	cin>>sb;s+=sb;cin>>sb;s+=sb;cin>>sb;s+=sb;
	if(mp[s]==0){
		cout<<"illegal";
	}
	if(mp[s]==1024){
		cout<<"first";
	}
	if(mp[s]==1025){
		cout<<"second";
	}
	if(mp[s]==1){
		cout<<"the first player won";
	}
	if(mp[s]==2){
		cout<<"the second player won";
	}
	if(mp[s]==-1){
		cout<<"draw";
	}
}