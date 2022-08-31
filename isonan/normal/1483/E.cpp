#include <cstdio>
#include <algorithm>

typedef unsigned long long ull;
int t;
ull x,M;
char str[21];
int cnt=0;
bool query(ull y){
	if(y>100000000000000ull){
		return 0;
	}
	++cnt;
	printf("? %llu\n",y);
	fflush(stdout);
#ifdef ISONAN
	if(y<=M)str[1]='L';
	else str[1]='F';
#else
	scanf("%s",str+1);
#endif
	if(str[1]=='L'){
		x+=y;
		return 1;
	}
	else{
		x-=y;
		return 0;
	}
}
void fill(ull y,ull z){
	while(x<y)query(z);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
#ifdef ISONAN
		scanf("%llu",&M);
#endif 
		x=1;
		ull l=-1;
		for(;;){
			++l;
			if(!query(1ull<<l))break;
		}
		--l;
		if(!~l){
			puts("! 0");
			fflush(stdout);
			continue;
		}
		ull L=1ull<<l,R=std::min(100000000000000ull,(1ull<<(l+1))-1);
		int c=0;
		while(R>L){
			ull mid=(L*3+R*(c+1))/(c+4);
			fill(mid+1,L);
			if(query(mid+1))L=mid+1,++c;else R=mid,c=std::max(c-1,0);
		}
		printf("! %llu\n",L);
		fflush(stdout);
	}
#ifdef ISONAN
	printf("%d\n",cnt);
#endif
}