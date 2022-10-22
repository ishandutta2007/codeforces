#include<iostream>
using namespace std;
int a[110];
int main(){
	string s;int p1=0,p2=0,n,tb=0;
	cin>>s;
	if(s.size()<26){cout<<-1;return 0;}
	while(p2<26){
		if(int(s[p2])!=63){
		if(a[int(s[p2])]==1)
			tb++;
		a[int(s[p2])]++;
		}
		p2++;
	}
	while(p2<=s.size()){
		if(tb==0)
			break;
		if(int(s[p1])!=63){
		if((a[int(s[p1])])==2)
			tb--;
		a[int(s[p1])]--;
		}
		p1++;
		if(int(s[p2])!=63){
		if((a[int(s[p2])])==1)
			tb++;
		a[int(s[p2])]++;
		}
		p2++;}
	//cout<<p1<<" "<<p2<<endl;
	if(p2>s.size())
		cout<<-1;
	else{
		for(int i=0;i<p1;i++){
			if(int(s[i])==63)
				cout<<'A';
			else
				cout<<s[i];
		}
		for(int i=p1;i<p2;i++){
			if(int(s[i])==63){
				for(int j=65;j<96;j++){
					if(a[j]==0){
						a[j]=1;
						cout<<char(j);
						break;}}}
			else
				cout<<s[i];
		}
		for(int i=p2;i<s.size();i++){
			if(int(s[i])==63)
				cout<<'A';
			else
				cout<<s[i];
		}
		}
}