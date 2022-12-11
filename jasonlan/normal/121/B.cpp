#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k;
int num[101000],head,nxt[101000];
void input(){
	int cnt=1;
	char ch;
	while(cnt<=n){
		ch=getchar();
		if(ch>='0'&&ch<='9'){
			num[cnt]=ch-'0';
			++cnt;
		}
	}
}
void output(){
	for(register int i=1;i<=n;++i)
		putchar('0'+num[i]);
}
bool change(){
	if(!head)return false;
	if((head%2==0)&&num[head-1]==4&&num[head+1]==7)
		k=k%2;
	if(!k)return false;
	if(head%2==1){	
		num[head]=num[head+1]=4;
		if(num[head+2]==7){
			nxt[head+1]=nxt[head];
			head=head+1;
		}
		else head=nxt[head];
	}
	else{
		num[head]=num[head+1]=7;
		if(num[head-1]==4){
			nxt[head-1]=nxt[head];
			head=head-1;
		}
		else head=nxt[head];
	}
	--k;
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	input();
	for(register int i=n-1;i;--i)
		if(num[i]==4&&num[i+1]==7){
			nxt[i]=head;head=i;
		}
	while(k)
		if(change()==false)break;
	output();
	return 0;
}