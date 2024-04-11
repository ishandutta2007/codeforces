#include<iostream>
using namespace std;
int a[1000000][2];
int main()
{
	int l1,l,sa=0,a1,a2,n,m;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='*'){
				a[sa][0]=i;a[sa][1]=j;sa++;
			}
		}
	}
	a1=a[0][0];a2=-1;l=0;l1=0;
	for(int i=1;i<sa;i++){
		if(a[i][0]!=a1){
			if(a2==-1)a2=a[i][1];
			else{
				if(a[i][1]!=a2){l=1;break;}}
		}
	}
	if(a2==-1)a2=0;
	if(l==0){cout<<"YES"<<endl<<a1+1<<" "<<a2+1;return 0;}
	a1=-1;a2=a[0][1];
	for(int i=1;i<sa;i++){
		if(a[i][1]!=a2){
			if(a1==-1)a1=a[i][0];
			else{
				if(a[i][0]!=a1){l1=1;break;}}
		}
	}
	if(a1==-1)a1=0;
	if(l1==0){cout<<"YES"<<endl<<a1+1<<" "<<a2+1;return 0;}
	cout<<"NO";
	
}