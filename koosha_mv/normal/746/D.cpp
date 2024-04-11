#include<iostream>
using namespace std;
int tagh(int x,int y){
	if(x%y==0)
		return x/y;
	return x/y+1;}
void zarb(int x,char y){
	for(int i=0;i<x;i++)
		cout<<y;}
int main(){
	int n,k,aa,bb,a,b;char t1,t2;
	cin>>n>>k>>aa>>bb;
	if(tagh(max(aa,bb),k)>min(aa,bb)+1){
		cout<<"NO";
		return 0;
	}
	if(aa>bb){
		t1='G';t2='B';}
	else{
		t1='B';t2='G';}
	a=max(aa,bb);
	b=min(aa,bb);
	while(a>b){
		zarb(min(a,k),t1);
		a-=min(a,k);
		if(b!=0){
			cout<<t2;
			b--;
		}
	}
	if(a==b){
		for(int i=0;i<b;i++){
			cout<<t1<<t2;
		}
	}
	else{
		for(int i=0;i<b-a;i++)
			cout<<t2;
		for(int i=0;i<a;i++)
		{
			cout<<t1<<t2;
		}}
	}