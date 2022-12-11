#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
const int mod=1e9+7;
int n,m;
int ah[26],bh[26],ord[26],dseg;
string a,b;
vector<int> ans;
int qmod(int x){
	return x>=mod?x-mod:x;
}
bool check(){
	for(register int i=0,flag;i<26;++i){
		flag=0;
		for(register int j=0;j<26;++j)
			if(ah[i]==bh[j]&&ah[j]==bh[i]){
				flag=1;break;
			}
		if(!flag)return false;
	}
	return true;
}
int main(){
	cin>>n>>m;
	cin>>a>>b;
	for(register int i=0;i<m;++i)
		for(register int j=0;j<26;++j){
			ah[j]=qmod((ah[j]<<1)+(a[i]-'a'==j));
			bh[j]=qmod((bh[j]<<1)+(b[i]-'a'==j));
		}
	dseg=1;
	for(register int i=1;i<m;++i)
		dseg=qmod(dseg<<1);
	for(register int i=m;i<=n;++i){
		if(check())ans.push_back(i-m+1);
		for(register int j=0;j<26;++j)
			if(a[i-m]-'a'==j)
				ah[j]=qmod(ah[j]-dseg+mod);
		if(i<n){
			for(register int j=0;j<26;++j)
				ah[j]=qmod((ah[j]<<1)+(a[i]-'a'==j));
		}
	}
	printf("%u\n",ans.size());
	for(register int i=0;i<ans.size();++i)
		printf("%d ",ans[i]);
	return 0;
}