#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[10];
int n,A,B;
int main(){
	scanf("%d",&n);
	scanf("%s",ch);
	A=(ch[0]-'0')*10+(ch[1]-'0');
	B=(ch[3]-'0')*10+(ch[4]-'0');
	int ans=0;
	if (n==12){
		int k1=100,w=0;
		for (int i=1;i<=12;i++){
			int k2=0;
			if (i%10!=A%10) k2++;
			if (i/10!=A/10) k2++;
			if (k2<k1){
				k1=k2; w=i;
			}
		}
		A=w;
	} else {
		int k1=100,w=0;
		for (int i=0;i<=23;i++){
			int k2=0;
			if (i%10!=A%10) k2++;
			if (i/10!=A/10) k2++;
			if (k2<k1){
				k1=k2; w=i;
			}
		}
		A=w;
	}
		int k1=100,w=0;
		for (int i=0;i<=59;i++){
			int k2=0;
			if (i%10!=B%10) k2++;
			if (i/10!=B/10) k2++;
			if (k2<k1){
				k1=k2; w=i;
			}
		}
		B=w;
	cout<<A/10<<A%10<<":"<<B/10<<B%10<<endl;
	return 0;
}