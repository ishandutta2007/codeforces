#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstring>
using namespace std;
const int mo=1e9+7;
const long long N=5ll*mo*mo;
class BM{
	int x[31000],y[31000],len,prelen,prep,A[31000],n,z[31000],prew;
	public:
	int check(int n){
		long long w=0;
		for (int i=0;i<=len;i++){
			w=(w+1ll*A[n-len+i]*x[i]);
			if (w>N) w-=N;
		//	if (w<-N) w+=N;
		}
		return w%mo;
	}
	int quick(int k1,int k2){
		int k3=1;
		while (k2){
			if (k2&1) k3=1ll*k3*k1%mo;
			k2>>=1; k1=1ll*k1*k1%mo;
		}
		return k3;
	}
	void addin(int k1){
		A[++n]=k1;
		int num=check(n);
		if (num==0) return;
		int last=prep-prelen,now=n-len,kk=1ll*prew*num%mo;
		if (now<=last){
			for (int i=last-now;i<=prelen+last-now;i++){
				x[i]=(x[i]-1ll*y[i-last+now]*kk)%mo;
				if (x[i]<0) x[i]+=mo;
			}
			return;
		}
		for (int i=0;i<=len;i++) z[i]=x[i];
		int shi=now-last;
		for (int i=len;i>=0;i--) x[i+shi]=x[i];
		for (int i=0;i<shi;i++) x[i]=0;
		for (int i=0;i<=prelen;i++){
			x[i]=(x[i]-1ll*y[i]*kk)%mo;
			if (x[i]<0) x[i]+=mo;
		}
		prelen=len; prep=n; prew=quick(num,mo-2);
		for (int i=0;i<=len;i++) y[i]=z[i];
		len+=shi;
	}
	BM(){
		memset(x,0x00,sizeof x);
		memset(y,0x00,sizeof y);
		memset(z,0x00,sizeof z);
		memset(A,0x00,sizeof A);
		prelen=0; y[0]=1; prep=0; len=0; x[0]=1; n=0; prew=0;
	}
	void print(){
		for (int i=len+1;i<=n;i++) if (check(i)!=0) cout<<"fa "<<i<<endl;
		//cout<<len<<endl;
		//for (int i=0;i<=len;i++) cout<<x[i]<<" "; cout<<endl;
	}
	int get(int K){
		return x[K];
	}
	int getlen(){
		return len;
	}
};
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
struct atom{
	int x,y,w;
}A[201000];
int d[110000],n,K,len,x[11000],y[11000],z[11000];
int getrand(){
	return abs((1ll*rand()<<32)+(1ll*rand()<<16)+(1ll*rand()<<8)+rand())%mo;
}
void add(int k1,int k2,int k3){
	k1--; k2--;
	if (k1&&k2) A[++len]=(atom){k1,k2,k3};
}
void insert(int k1,int k2){
	d[k1]++; d[k2]++;
	add(k1,k2,mo-1);
	add(k2,k1,mo-1);
}
int l[11000],r[11000],B[120000],C[120000];
int solve(int n){
	if (n==0) return 1;
//	for (int i=1;i<=len;i++)
//		cout<<A[i].x<<" "<<A[i].y<<" "<<A[i].w<<endl;
	int pre=1;
	for (int i=1;i<=n;i++) x[i]=getrand(),y[i]=getrand(),z[i]=getrand(),pre=1ll*pre*z[i]%mo;
//	for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<y[i]<<" "; cout<<endl;
	for (int i=1;i<=len;i++) A[i].w=1ll*A[i].w*z[A[i].y]%mo,C[i]=A[i].w;
//	pre=1;
//	cout<<pre<<endl;
	BM ans;
	for (int i=1;i<=n*2+100;i++){
		int w=0;
		for (int j=1;j<=n;j++) w=(w+1ll*x[j]*y[j])%mo,z[j]=0;
		ans.addin(w); //cout<<"add "<<w<<endl;
		int now=1;
		for (int now=1;now<=n;now++){
			long long w=0;
			for (int k=l[now];k<=r[now];k++){
				w=(w+1ll*C[k]*x[B[k]]);
				if (w>N) w-=N;
			//	if (w<-N) w+=N;
			}
			z[now]=w%mo;
		}
		for (int j=1;j<=n;j++) x[j]=z[j];
	//	ans.print();
	}
//	cout<<pre<<" "<<ans.get(0)<<endl;
	if (n&1) pre=-pre;
	if (ans.getlen()!=n) cout<<"fa "<<ans.getlen()<<" "<<n<<endl; 
	return (1ll*ans.get(0)*quick(pre,mo-2)%mo+mo)%mo;
}
int compare(atom k1,atom k2){
	return k1.x<k2.x;
}
int main(){
	srand(time(0));
 	scanf("%d%d",&n,&K);
	//n=10000; K=5;
	for (int i=1;i<=K;i++)
		for (int j=i+1;j<=K;j++)
			insert(i,j);
	for (int i=K+1;i<=n;i++)
		for (int j=1;j<=K;j++){
			int k1=rand()%(i-1)+1; scanf("%d",&k1); 
			insert(i,k1);
		}
	for (int i=1;i<=n;i++) add(i,i,d[i]);
	sort(A+1,A+len+1,compare);
	for (int i=1;i<=len;i++) r[A[i].x]=i,B[i]=A[i].y,C[i]=A[i].w;
	for (int i=len;i;i--) l[A[i].x]=i;
	printf("%d\n",solve(n-1));
	return 0;
}