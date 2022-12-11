#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A,B,num1,num2;
int pd[8],sign;
int main(){
	scanf("%d%d",&A,&B);
	num1=1; num2=1;
	int preA=A,preB=B;
	A--; B--; A/=7; B/=7;
	while (A) num1++,A/=7;
	while (B) num2++,B/=7;
//	cout<<num1<<" "<<num2<<endl;
	if (num1+num2>7){
		printf("0\n"); return 0;
	}
	int ans=0;
	for (int i=0;i<preA;i++)
		for (int j=0;j<preB;j++){
			sign++; int flag=0;
			int k1=i;
			for (int k=1;k<=num1;k++){
				if (pd[k1%7]==sign) flag=1;
				pd[k1%7]=sign; k1/=7;
			}
			k1=j;
			for (int k=1;k<=num2;k++){
				if (pd[k1%7]==sign) flag=1;
				pd[k1%7]=sign; k1/=7;
			}
			ans+=1-flag;
		}
	cout<<ans<<endl;
	return 0;
}