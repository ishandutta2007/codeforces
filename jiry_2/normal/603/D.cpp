#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct line{
	int a,b,c;
	void scan(){
		scanf("%d%d%d",&a,&b,&c);
	}
}A[2100];
struct point{
	double x,y;
	double getw(){
		return atan2(y,x); 
	}
}x[2100];
int n,len,len2,w1[2100],w2[2100];
double w[2100],f[2100];
const double eps=1e-11,pi=acos(-1);
int ans=0;
point getpoint(double a,double b,double c){
	if (fabs(c)<eps){
		return (point){0,0};
	}
	double d=b,e=-a,f=0; 
	double y=(c*d-f*a)/(b*d-e*a),x;
	if (fabs(a)>fabs(d)) x=(c-b*y)/a; else x=(f-e*y)/d;
	return (point){x,y};
}
point operator - (point k1,point k2){
	return (point){k1.x-k2.x,k1.y-k2.y};
}
int compare(double k1,double k2){
	return k1>k2;
}
int main(){
	scanf("%d",&n); 
	for (int i=1;i<=n;i++) A[i].scan();
	for (int i=1;i<=n;i++) x[i]=getpoint(A[i].a,A[i].b,A[i].c);
	//for (int i=1;i<=n;i++) cout<<x[i].x<<" "<<x[i].y<<endl;
	int ans1=0; int ans3=0;
	for (int no=1;no<=n;no++){
		int len1=0,len2=0;
		for (int i=1;i<=n;i++)
			if (i!=no){
				if (fabs(x[i].x-x[no].x)<eps&&fabs(x[i].y-x[no].y)<eps){
					ans1+=n-2; continue;
				}
				double k1=(x[i]-x[no]).getw();
				if (k1>-eps) w[++len1]=k1;
				if (k1<eps) f[++len2]=k1;
			}
		if (len1==0||len2==0) continue;
		sort(w+1,w+len1+1);
		sort(f+1,f+len2+1);
	//	cout<<"fa "<<no<<endl;
	//	for (int i=1;i<=len1;i++) cout<<w[i]<<" "; cout<<endl;
	//	for (int i=1;i<=len2;i++) cout<<f[i]<<" "; cout<<endl;
	/*int flag=0;
		for (int i=1;i<=len1;i++)
			for (int j=1;j<=len2;j++) if (fabs(w[i]-f[j]-pi)<eps){
				ans3++; //cout<<"meet "<<w[i]<<" "<<f[j]<<endl; flag=1;
			}*/
	/*	if (flag){
			for (int i=1;i<=len1;i++) cout<<w[i]<<" "; cout<<endl;
			for (int i=1;i<=len2;i++) cout<<f[i]<<" "; cout<<endl;
		}*/
		int now=1,pre=len1;
		len1=1; 
		memset(w1,0x00,sizeof w1);
		memset(w2,0x00,sizeof w2);
		w1[1]=1; w2[1]=1;
		for (int i=2;i<=pre;i++)
			if (fabs(w[i]-w[len1])>eps){
				len1++; w1[len1]=1; w[len1]=w[i];
			} else w1[len1]++;
		pre=len2; len2=1;
		for (int i=2;i<=pre;i++)
			if (fabs(f[i]-f[len2])>eps){
				len2++; w2[len2]=1; f[len2]=f[i];
			} else w2[len2]++;
	/*	if (flag){
			for (int i=1;i<=len1;i++) cout<<w[i]<<" "; cout<<endl;
			for (int i=1;i<=len2;i++) cout<<f[i]<<" "; cout<<endl;
		}*/
	//	for (int i=1;i<=len1;i++) cout<<w[i]<<" "; cout<<endl;
	//	for (int i=1;i<=len2;i++) cout<<f[i]<<" "; cout<<endl;
		for (int i=1;i<=len1;i++){
			int l=1,r=len2+1;
			while (l<r){
				int mid=(l+r)>>1;
				double k1=w[i]-f[mid];
				if (k1>eps+pi) l=mid+1;
				else if (k1<pi-eps) r=mid;
				else {
					ans=ans+w1[i]*w2[mid];
					break;
				}
			}
		}
	//	cout<<ans<<endl;
	}
//	cout<<ans3+ans1/2<<endl;
//	cout<<ans<<" "<<ans1<<endl;
	printf("%d\n",ans+ans1/2);
	return 0;
}