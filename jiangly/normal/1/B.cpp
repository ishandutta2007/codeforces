#include<bits/stdc++.h>
using namespace std;
int n;
char a[20];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",a+1);
		int l=strlen(a+1);
		int type=2;
		for(int j=1;j<l;++j){
			if(isdigit(a[j])&&isalpha(a[j+1])){
				type=1;
				break;
			}
		}
		int x,y,z;
		stack<char>st;
		switch(type){
			case 1:
				for(int j=3;j<=l;++j){
					if(a[j]=='C'){
						x=j;
						break;
					}
				}
				y=0;
				for(int j=x+1;j<=l;++j){
					y=y*10+a[j]-'0';
				}
				z=1;
				for(int j=26;j<y;y=y-j,j=j*26,++z);
				y=y-1;
				for(int j=1;j<=z;++j){
					st.push(y%26);
					y=y/26;
				}
				while(!st.empty()){
					putchar('A'+st.top());
					st.pop();
				}
				for(int j=2;j<x;++j){
					putchar(a[j]);
				}
				putchar('\n');
				break;
			case 2:
				for(int j=1;j<l;++j){
					if(isdigit(a[j+1])){
						x=j;
						break;
					}
				}
				putchar('R');
				for(int j=x+1;j<=l;++j){
					putchar(a[j]);
				}
				putchar('C');
				y=0;
				for(int j=1;j<=x;++j){
					y=y*26+a[j]-'A';
				}
				y=y+1;
				for(int j=1,k=26;j<x;y=y+k,++j,k=k*26);
				printf("%d\n",y);
				break;
		}
	}
	return 0;
}