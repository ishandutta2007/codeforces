#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;

pair<bool,string>tr(int k,string s){
	int i=1,j=1;
	while(j<n&&s[j]==s[0])++j;
	i+=k;
	if(i>=j)return{true,s};
	for(;j<n;++i,++j){
		swap(s[i],s[j]);
		i+=k;
		if(i>=j)return{true,s};
	}
//	cerr<<s<<endl;
	return{false,""};
}

void ProGamerMove(){
	string s;cin>>s;
	n=s.size();
	int cnts[256]={};
	vector<char>chars;
	char one,isone=0;
	for(int c='z';c>='a';--c)
		if((cnts[c]=count(s.begin(),s.end(),c))){
			chars.push_back(c);
			if(cnts[c]==1){
				isone=true;
				one=c;
			}
		}
	if(chars.size()==1){
		cout<<s<<"\n";return;
	}
	sort(s.begin(),s.end());
	if(isone){
		string res;res+=one;
		for(int it=chars.size()-1;it>=0;--it)if(chars[it]!=one)res+=string(cnts[chars[it]],chars[it]);
		cout<<res<<"\n";
		return;
	}
	for(int it=chars.size()-1;it>=0;--it){
		string t=string(cnts[chars[it]],chars[it]);
		for(int j=chars.size()-1;j>=0;--j)
			if(j!=it)t+=string(cnts[chars[j]],chars[j]);
		auto[pos,res]=tr(1,t);
		if(pos){
			cout<<res<<"\n";
			return;
		}
		if(chars.size()==2){
			t=string(1,chars.back())+string(cnts[chars[chars.size()-2]],chars[chars.size()-2])+string(cnts[chars.back()]-1,chars.back());
			cout<<t<<"\n";
			return;
		}
		t=string(1,chars.back())+string(1,chars[chars.size()-2])+string(cnts[chars.back()]-1,chars.back())+string(1,chars[chars.size()-3]);
		for(int j=(int)chars.size()-2;j>=0;--j)t+=string(cnts[chars[j]]-(j==chars.size()-2||j==chars.size()-3),chars[j]);
		cout<<t<<"\n";
		return;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}