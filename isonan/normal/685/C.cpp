#include <cstdio>
#include <algorithm>
 
int T,n;
long long x[100001],y[100001],z[100001],a,b,c,A,B,C;
const long long inf=3100000000000000000ll;
bool cando(long long u){
	long long al=-inf,ar=inf,bl=-inf,br=inf,cl=-inf,cr=inf,dl=-inf,dr=inf;
	for(int j=1;j<=n;j++){
		al=std::max(al,-x[j]+y[j]+z[j]-u);
		ar=std::min(ar,-x[j]+y[j]+z[j]+u);
		bl=std::max(bl,+x[j]-y[j]+z[j]-u);
		br=std::min(br,+x[j]-y[j]+z[j]+u);
		cl=std::max(cl,+x[j]+y[j]-z[j]-u);
		cr=std::min(cr,+x[j]+y[j]-z[j]+u);
		dl=std::max(dl,+x[j]+y[j]+z[j]-u);
		dr=std::min(dr,+x[j]+y[j]+z[j]+u);
	}
	for(int i=0;i<2;i++){
		A=al+((al&1)!=i);
		B=bl+((bl&1)!=i);
		C=cl+((cl&1)!=i);
		a=ar-((ar&1)!=i);
		b=br-((br&1)!=i);
		c=cr-((cr&1)!=i);
		if(A+B+C<dl){
			if(a-A<dl-A-B-C)A=a;
			else{
				A+=dl-A-B-C;
				if((A&1)!=i){
					if(A<a)++A;
					else --A;
				}
			}
		}
		if(A+B+C<dl){
			if(b-B<dl-A-B-C)B=b;
			else{
				B+=dl-A-B-C;
				if((B&1)!=i){
					if(B<b)++B;
					else --B;
				}
			}
		}
		if(A+B+C<dl){
			if(c-C<dl-A-B-C)C=c;
			else{
				C+=dl-A-B-C;
				if((C&1)!=i){
					if(C<c)++C;
					else --C;
				}
			}
		}
		if(A>=al&&A<=ar&&B>=bl&&B<=br&&C>=cl&&C<=cr&&A+B+C>=dl&&A+B+C<=dr)return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%I64d%I64d%I64d",x+i,y+i,z+i);
		long long l=0,r=inf,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(cando(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cando(ans);
		printf("%I64d %I64d %I64d\n",(B+C)>>1ll,(A+C)>>1ll,(A+B)>>1ll);
	}
}