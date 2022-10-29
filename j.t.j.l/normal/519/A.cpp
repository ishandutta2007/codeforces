#include<iostream>
#include<cmath> 
#include<cstring> 
#include<cstdio>
#include<algorithm>
#define N 120007
#define INF 2147483647
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int W,B;
char ch;

int main(){
	W=0;
	B=0;
	while (scanf("%c",&ch)!=EOF){
		if (ch=='Q')
			W+=9;
		if (ch=='R')
			W+=5;
		if (ch=='B')
			W+=3;
		if (ch=='N')
			W+=3;
		if (ch=='P')
			W+=1;
		if (ch=='q')
			B+=9;
		if (ch=='r')
			B+=5;
		if (ch=='b')
			B+=3;
		if (ch=='n')
			B+=3;
		if (ch=='p')
			B+=1;
	}
	if (W>B)
		printf("White\n");
	else
		if (W==B)
			cout<<"Draw"<<endl;
		else
			cout<<"Black"<<endl;
	return 0;
}