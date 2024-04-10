#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=10005;
int n,s[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)s[i]=0;
		while(1){
			int x=1;
			while(x<=n&&s[x])x++;
			if(x>n)break;
			int y,z,o;
			printf("? %d\n",x);
			fflush(stdout);
			scanf("%d",&y);
			o=y;
			while(1){
				printf("? %d\n",x);
				fflush(stdout);
				scanf("%d",&z);
				s[y]=z;
				if(z==o)break;
				y=z;
			}
		}
		putchar('!');
		for(int i=1;i<=n;i++)printf(" %d",s[i]);
		putchar('\n');
		fflush(stdout);
	}
}