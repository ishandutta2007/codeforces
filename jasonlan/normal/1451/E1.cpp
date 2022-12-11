#include<iostream>
#include<cstdio>
using namespace std;
int n;
int num[(1<<16)+100];
int ain(string s,int a,int b){
	cout<<s<<' '<<a<<' '<<b<<endl;
	cout.flush();
	scanf("%d",&a);
	return a;
}
bool check(int p,int x12,int x13,int x23,int a12,int a13,int a23){
	int x1=p>>2,x2=(p>>1)&1,x3=p&1;
	if((x1^x2)!=x12||(x2^x3)!=x23||(x1^x3)!=x13)return false;
	if((x1&x2)!=a12||(x2&x3)!=a23||(x1&x3)!=a13)return false;
	return true;
}
int main(){
	scanf("%d",&n);
	int x12=ain("XOR",1,2),x13=ain("XOR",1,3),x23=x12^x13;
	int a12=ain("AND",1,2),a13=ain("AND",1,3),a23=ain("AND",2,3); 
	for(register int i=0;i<16;++i){
		for(register int j=0;j<8;++j)
			if(check(j,(x12>>i)&1,(x13>>i)&1,(x23>>i)&1,(a12>>i)&1,(a13>>i)&1,(a23>>i)&1)){
				num[1]|=((j>>2)<<i);
				num[2]|=(((j>>1)&1)<<i);
				num[3]|=((j&1)<<i);
			}
	}
	for(register int i=4,x;i<=n;++i){
		x=ain("XOR",1,i);
		num[i]=(num[1]^x);
	}
	cout<<"!";
	for(register int i=1;i<=n;++i)
		cout<<' '<<num[i];
	return 0;
}