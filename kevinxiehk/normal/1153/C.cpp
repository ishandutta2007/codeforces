#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2==1){
		cout<<":("<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)if(s[i]==')')cnt++;
	if(cnt>n/2){
		cout<<":("<<endl;
		return 0;
	}
	int t=n/2;
	t-=cnt;
	int now=n;
	while(t!=0&&now>=0){
		if(s[now]=='?'){
			s[now]=')';
			t--;
		}
		now--;
	}
	if(t!=0){
		cout<<":("<<endl;
		return 0;
	}
	cnt=0;
	for(int i=0;i<n;i++)if(s[i]=='?')s[i]='(';
	//cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(s[i]=='(')cnt++;
		else cnt--;
		if(cnt<=0&&i!=n-1){
			cout<<":("<<endl;
			return 0;
		}
	}
	cout<<s<<endl;
	return 0;
}