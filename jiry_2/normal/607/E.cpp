#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,K,len,l[60000],r[60000],m,c[60000],A[110000],where[60000],rem,flag;
long double a[60000],b[60000],p,q,L[60000],R[60000],x[110000],ans;
vector<int>num[410000];
const long double pi=acos(-1),eps=1e-14;
long double rr;
int check(long double k1,long double k2){
	return k1==k1&&k2==k2&&(fabs(k1-k2)<eps||fabs((k1-k2)/max(fabs(k1),fabs(k2)))<eps);
}
int getcross(int k){
	long double A=a[k]*a[k]+1,B=-2*p-2*a[k]*(q-b[k]),C=p*p+(q-b[k])*(q-b[k])-rr*rr,D=B*B-4*A*C;
	if (D<0) return 0;
	long double x1=(-B+sqrt(D))/(2*A),x2=(-B-sqrt(D))/(2*A),y1=x1*a[k]+b[k],y2=x2*a[k]+b[k];
	long double LL=atan2(y1-q,x1-p),RR=atan2(y2-q,x2-p);
	if (LL>RR) swap(LL,RR);
	L[++len]=LL; R[len]=RR;
	return 1;
}
int get(long double k1){
	int l=1,r=m+1;
	while (l<r){
		int mid=(l+r)>>1;
		if (check(k1,x[mid])) return mid;
		else if (x[mid]>k1) r=mid;
		else l=mid+1;
	}
}
int compare(int k1,int k2){
	return l[k1]<l[k2]||(l[k1]==l[k2]&&r[k1]<r[k2]);
}
void add(int k1){
	for (;k1<=m;k1+=k1&(-k1)) A[k1]++;
}
int find(int k1){
	int ans=0; for (;k1;k1-=k1&(-k1)) ans+=A[k1]; return ans;
}
int check(double kk){
	rr=kk; len=0; //cout<<endl<<endl<<"check "<<kk<<endl;
	for (int i=1;i<=n;i++) getcross(i);
	int N=0;
	for (int i=1;i<=len;i++) x[++N]=L[i],x[++N]=R[i];
	sort(x+1,x+N+1); m=1;
	for (int i=2;i<=N;i++) if (!check(x[i],x[m])) x[++m]=x[i];
	for (int i=1;i<=len;i++) l[i]=get(L[i]),r[i]=get(R[i]);
//	cout<<"check "<<kk<<" "<<len<<" "<<n<<endl;	
//	for (int i=1;i<=len;i++) cout<<(double)L[i]<<" "<<(double)R[i]<<" "<<l[i]<<" "<<r[i]<<endl;
	for (int i=1;i<=len;i++) c[i]=i;
	sort(c+1,c+len+1,compare); int ans=0;
	memset(A,0x00,sizeof A);
	for (int i=1;i<=len;i++){
		int k1=l[c[i]],k2=r[c[i]]; if (k1>=k2) continue;
		add(k2); if (k2>k1) ans+=find(k2-1)-find(k1);
	}
//	cout<<ans<<endl;
	return ans;
}
void insert(int k1,int k2,int k3,int k4,int k5){
	num[k1].push_back(k5);
	if (k2==k3) return;
	int mid=k2+k3>>1;
	if (mid>=k4) insert(k1*2,k2,mid,k4,k5); else insert(k1*2+1,mid+1,k3,k4,k5);
}
#define sqr(x) ((x)*(x))
long double getcross(int k1,int k2){
//	cout<<"getcross "<<k1<<" "<<k2<<endl;
	long double x=(b[k2]-b[k1])/(a[k1]-a[k2]),y=a[k1]*x+b[k1];
	return sqrt(sqr(x-p)+sqr(y-q));
}
long double find(int k1,int k2,int k3,int k4,int k5,int k6){
	 if (k2>k5||k3<k4) return 0;
	 if (k2>=k4&&k3<=k5){
	 	long double ans=0;
	 	for (int i=0;i<num[k1].size();i++) ans+=getcross(k6,num[k1][i]),rem--;
	 //	if (rem<0&&flag) cout<<"fa"<<endl;
	 	return ans;
	 }
	 int mid=k2+k3>>1;
	 return find(k1*2,k2,mid,k4,k5,k6)+find(k1*2+1,mid+1,k3,k4,k5,k6);
}
int calc(double kk){
	rr=kk; len=0; if (kk<0) {ans=0; return 1;}
	for (int i=1;i<=n;i++) if (getcross(i)) where[len]=i;
	int N=0;
	for (int i=1;i<=len;i++) x[++N]=L[i],x[++N]=R[i];
	sort(x+1,x+N+1); m=1;
	for (int i=2;i<=N;i++) if (!check(x[i],x[m])) x[++m]=x[i];
	for (int i=1;i<=len;i++) l[i]=get(L[i]),r[i]=get(R[i]);
//	for (int i=1;i<=len;i++) cout<<l[i]<<" "<<r[i]<<endl;
	for (int i=1;i<=len;i++) c[i]=i;
	memset(A,0x00,sizeof A);
	sort(c+1,c+len+1,compare); ans=0; int num=0;
	for (int i=1;i<=len;i++){
		int k1=l[c[i]],k2=r[c[i]]; if (k1>=k2) continue;
		add(k2); if (k2>k1) num+=find(k2-1)-find(k1);
	}
	if (flag) cout<<"fa "<<num<<endl;
	if (num>K) return 0;
	for (int i=1;i<=len;i++){
		int k1=l[c[i]],k2=r[c[i]]; 
		if (k1>=k2) continue;
		insert(1,1,m,k2,where[c[i]]);
		ans+=find(1,1,m,k1+1,k2-1,where[c[i]]);
	}
	ans+=(K-num)*kk;
	//cout<<ans<<endl;
	return 1;
}
int main(){
	scanf("%d",&n); double k1,k2; 
	scanf("%lf%lf%d",&k1,&k2,&K); flag=0; rem=K;
	//if (fabs(k2-(-953428))<eps) flag++;
	p=k1/1000; q=k2/1000;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&k1,&k2); a[i]=k1/1000; b[i]=k2/1000;
	}
	double l=0,r=1e10;
	for (int i=1;i<=60;i++){
		double mid=(l+r)/2;
		if (check(mid)<K) l=mid; else r=mid;
	}
//	cout<<(double)l<<" "<<r<<endl;
	for (long double i=eps;calc((l+r)/2-i)==0;i*=10) if (flag) cout<<"fail "<<(double)i<<" "<<((l+r)/2-i)<<endl;
	//cout<<l<<" "<<r<<" "<<check((l+r)/2)<<endl;
	printf("%.11lf\n",(double)ans);
	return 0;
}