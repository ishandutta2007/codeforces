#include<bits/stdc++.h>
using namespace std;
int t,x,l,y,i;
char s[10000];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		l=strlen(s+1);
		x=0;
		for(i=1;i<=l;++i){
			x+=s[i]-'0';
		}
		if(x==0||x==l){
			for(i=1;i<=l;++i){
				cout<<s[i];
			}
			cout<<"\n";
		}
		else{
		if(s[1]=='0')cout<<'1';
		cout<<s[1];
		for(i=2;i<=l;++i){
			if(s[i-1]=='0'&&s[i]=='0'){
				cout<<'1';
			}
			if(s[i-1]=='1'&&s[i]=='1'){
				cout<<'0';
			}
			cout<<s[i];
		}
		cout<<"\n";
		
		}
	}
	return 0;
}