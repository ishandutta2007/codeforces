#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n;
char a[N],b[N];
int get(int a,int b,int c,int d){
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	char str[5];
	scanf("%s",str);
	return str[0]=='Y';
}
int main(){
    scanf("%d",&n);
	int x=1,y=1;
	for(int i=1;i<n;i++){
		if(get(x+1,y,n,n))++x,a[i]='D';else ++y,a[i]='R';
	}
	x=y=n;
	for(int i=1;i<n;i++){
		if(get(1,1,x,y-1))--y,b[n-i]='R';else --x,b[n-i]='D';
	}
	printf("! %s%s",a+1,b+1);
    return 0;
}