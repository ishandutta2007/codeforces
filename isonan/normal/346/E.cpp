#include <cstdio>
#include <algorithm>
using std::max;

long long a,n,h,p;
int T;
long long query(long long a,long long n,long long p){
	long long t=a*n/p;
	if(!t)return max(a,p-a*n);
	return query(a-p%a,t-(a*n%p<(p/a-1)*a),a);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%I64d%I64d%I64d%I64d",&a,&n,&p,&h);a%=p;
		puts(((a*n<p?a:query(a,n,p))>h)?"NO":"YES");
	}
}