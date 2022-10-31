#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,a[2050],b[2050],res1,res2;

void op2(){
	m=n/2;
	for(int i=1;i<=m;i++){swap(a[i],a[i+m]);}
}

void op1(){
	for(int i=1;i<n;i+=2){swap(a[i],a[i+1]);}
}

void op3(){
	m=n/2;
	for(int i=1;i<=m;i++){swap(b[i],b[i+m]);}
}

void op4(){
	for(int i=1;i<n;i+=2){swap(b[i],b[i+1]);}
}

bool chk1(){
	for(int i=1;i<=n;i++){if(a[i]!=i){return 0;}}return 1;
}

bool chk2(){
	for(int i=1;i<=n;i++){if(b[i]!=i){return 0;}}return 1;
}

int main(){
	scanf("%d",&n);n*=2;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	if(chk1()){puts("0");return 0;}
	for(i=1;i<=4000;i++){
		op1();op3();
		
		if(chk1()||chk2()){printf("%d",i*2-1);return 0;}
		op2();op4();
		if(chk1()||chk2()){printf("%d",i*2);return 0;}
	}
	puts("-1");
}