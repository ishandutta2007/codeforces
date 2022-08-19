#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

char a[200005], b[200005];
char c[200005], d[200005];

bool same(int s, int e, int ps, int pe){
	for(int i=s; i<=e; i++){
		if(b[ps++] != a[i]) return 0;
	}
	return 1;
}

bool func(int s, int e, int ps, int pe){
	if(same(s,e,ps,pe)) return 1;
	if((e - s + 1) % 2 == 1) return 0;
	int m = (s+e)/2;
	int pm = (ps + pe)/ 2;
	if(rand()&1) return (func(m+1,e,ps,pm) && func(s,m,pm+1,pe)) || (func(s,m,ps,pm) && func(m+1,e,pm+1,pe));
	return (func(s,m,ps,pm) && func(m+1,e,pm+1,pe)) || (func(m+1,e,ps,pm) && func(s,m,pm+1,pe));
}

int main(){
	srand(time(NULL));
	scanf("%s %s",a,b);
	int l = (int)strlen(a) - 1;
	puts(func(0,l,0,l) ? "YES" : "NO");
}