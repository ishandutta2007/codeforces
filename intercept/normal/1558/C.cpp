#include<bits/stdc++.h>
using namespace std;
int n;
int a[3009];
void change(int p){
	for(int i=1;i<=p/2;++i)swap(a[i],a[p-i+1]);
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(a[i]%2!=i%2){
			puts("-1");
			return;
		}
	}
	printf("%d\n",n/2*5);
	for(int o=n;o>1;o-=2){
		for(int i=1;i<=o;++i){
			if(a[i]==o){
				change(i);
				for(int j=1;j<=o;++j){
					if(a[j]==o-1){
						change(j-1);
						change(j+1);
						change(3);
						change(o);
						printf("%d %d %d 3 %d ",i,j-1,j+1,o);
						break;
					}
				}
				break;
			}
		}
	}
	puts("");
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}