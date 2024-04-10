//Time Complexity : O(N*L)
//Space Complexity : O(N*L)
#include<bits/stdc++.h>
using namespace std;
const int N=1000,L=1000;
int main(){
	int n=0,l=0,c=0;
	string s[N+1],a;
	while(getline(cin,a)){
		s[++n]=a;
		l=max(l,int(a.length()));
	}
	for(int i=1;i<=l+2;++i){
		printf("*");
	}
	puts("");
	for(int i=1;i<=n;++i){
		printf("*");
		int l1,l2;
		l1=(l-s[i].length())/2;
		l2=l1;
		if((l-s[i].length())%2==1){
			if(c==0){
				++l2;
			}else{
				++l1;
			}
			c=c^1;
		}
		for(int j=1;j<=l1;++j){
			printf(" ");
		}
		cout<<s[i];
		for(int j=1;j<=l2;++j){
			printf(" ");
		}
		puts("*");
	}
	for(int i=1;i<=l+2;++i){
		printf("*");
	}
	puts("");
	return 0;
}