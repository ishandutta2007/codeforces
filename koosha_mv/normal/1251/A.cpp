#include<iostream>
using namespace std;
int a[130]={0};
int main(){
	string s;
	int n;
	cin>>n;
	for(int p1=0;p1<n;p1++){
		cin>>s;
		s+='?';
		int t=1;char gh=s[0];
		for(int i=0;i<130;i++)
			a[i]=0;
		if(s[0]!=s[1])
			a[int(s[0])]=1;
		
		for(int i=1;i<s.size();i++){
			if(s[i]==gh)
				t++;
			else{
				if(t%2==1)
					a[int(gh)]=1;
				t=1;
			}
			gh=s[i];
		}
		//if(t%2==1)
		//	a[int(s[s.size()-1])];
		for(int i=0;i<130;i++){
			if(a[i]==1)
				cout<<char(i);
		}
		cout<<endl;
		}
}