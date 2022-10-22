#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
char a[3][N];
inline void S(int x,int y){
	for(int i=1;i<=2*n;i++)swap(a[x][i],a[y][i]);
	return;
}
inline void solve(char x){
	int j=1;
	for(int i=1;i<=2*n;i++){
		if(j>2*n){putchar(a[0][i]);continue;}
		if(a[0][i]!=x){putchar(a[0][i]);continue;}
		while(a[1][j]!=x&&j<=2*n){putchar(a[1][j]);j++;}
		if(j<=2*n)putchar(a[1][j]),j++;
		else putchar(a[0][i]);
	}
	while(j<=2*n)putchar(a[1][j++]);
	puts("");return;
}
signed main(){
	int T=read();
	while(T--){
		n=read();
		scanf("%s%s%s",a[0]+1,a[1]+1,a[2]+1);
		int cnt1,cnt2,cnt3;cnt1=cnt2=cnt3=0;
		for(int i=1;i<=2*n;i++)if(a[0][i]=='0')cnt1++;
		for(int i=1;i<=2*n;i++)if(a[1][i]=='0')cnt2++;
		for(int i=1;i<=2*n;i++)if(a[2][i]=='0')cnt3++;
		if(cnt1>=n&&cnt3>=n)S(1,2),swap(cnt2,cnt3);
		if(cnt2>=n&&cnt3>=n)S(0,2),swap(cnt1,cnt3);
		if(cnt1>=n&&cnt2>=n){solve('0');continue;}
		cnt1=2*n-cnt1,cnt2=2*n-cnt2,cnt3=2*n-cnt3;
		if(cnt1>=n&&cnt3>=n)S(1,2),swap(cnt2,cnt3);
		if(cnt2>=n&&cnt3>=n)S(0,2),swap(cnt1,cnt3);
		if(cnt1>=n&&cnt2>=n)solve('1');
	}
	return 0;
}