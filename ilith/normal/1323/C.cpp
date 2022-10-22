#include<bits/stdc++.h>
using namespace std;
int n;
int pre=-1,cnt,ans;
string str;
int main(){
	cin>>n>>str;
	str+=';';
	if(n&1){cout<<-1;return 0;}
	bool cho=str[0]==')';
	for(int i=0;i<n;++i){
		cnt+=str[i]=='('?1:-1;
		if(cnt==0){
			if(cho) ans+=i-pre;
			cho=str[i+1]==')',pre=i;
		}
	}
	if(cnt) cout<<-1;
	else cout<<ans;
	return 0;
}