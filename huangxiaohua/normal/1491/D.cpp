#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m1,m2,s1[40],s2[40],u,v,t;
bitset<40> b1,b2;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&u,&v);
		b1=u;b2=v;
		m1=m2=0;
		for(i=0;i<=30;i++){
			if(b1[i]==1){s1[++m1]=i;}
			if(b2[i]==1){s2[++m2]=i;}
		}
		if(m2>m1){puts("NO");goto aaa;}
		if(m1==m2){
			while(m2){
				i=s1[m1];j=s2[m2];m1--;m2--;
				if(i>j){puts("NO");goto aaa;}
			}
			puts("YES");
		}
		else{
			while(m2){
				i=s1[m1];j=s2[m2];m1--;m2--;
				if(i>j){puts("NO");goto aaa;}
				if(i<j){
					if(m1>m2){m1=m2;}
				}
			}
			if(m1==m2){puts("YES");}
			else{puts("NO");}
		}
		aaa:;
	}
}