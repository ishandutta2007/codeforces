#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;

//static char ss[1<<17],*A=ss,*B=ss;
//char gc(){
//    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
//}
//int read(){
//    int f=1,c; 
//	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
//	int x=c-'0';
//    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
//	return f>0?x:-x;
//}


const LL P=998244353;
const int N=3e5+10;

int n;

int a[10050];

bitset<4010> f1,f2,g;

bool check(int lim){
	f1.reset();g.reset();
	for(int i=0;i<=lim;++i) {
		g[i]=1;
		f1[i]=1;
	}
	for(int i=1;i<=n;++i){
		f2=f1;
		f1=f2<<a[i];
		f1|=f2>>a[i];
		f1&=g;
//		if(lim<10){
//			cout<<lim<<" "<<i<<endl;
//			for(int j=0;j<=10;++j) cout<<f1[j];
//			cout<<endl;
//		}
	}
	if(f1.any()) return 1;
	return 0;
}

void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int l=0,r=2005,mid;
	while(l!=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return;
}

int main(){
	int ttt=1;scanf("%d",&ttt); 
	while(ttt--) MAIN();
	return 0;
}
/*
*/