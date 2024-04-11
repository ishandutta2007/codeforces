#include<iostream>
using namespace std;
int a[102],num[102];;
int main(){
	int n,x,ty=0,b=0,aa=0,bb=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]++;
		num[i]=x;
	}
	for(int i=0;i<102;i++){
		if(a[i]==1)
			ty++;
		if(a[i]>2)
			b++;
	}
	if(ty%2==1 && b==0){cout<<"NO"; return 0;}
	cout<<"YES"<<endl;
	if(ty%2==0){
		bb=ty/2;
		aa=ty/2;
		x=0;
	}
	else{
		aa=ty/2;bb=ty/2+1;x=1;}
	for(int i=0;i<n;i++){
		if(a[num[i]]==1){
			if(aa>0){
				cout<<'A';
				aa--;
			}
			else
				cout<<'B';
		}
		else{
			if(a[num[i]]>2){
				if(x==1){
					x=0;
					cout<<'A';
				}
				else{
					cout<<'B';
				}
			}
			else
				cout<<'B';
		}
	}
}