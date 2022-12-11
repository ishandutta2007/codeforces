#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	long long x,y;
	void scan(){
		scanf("%I64d%I64d",&x,&y);
	}
}A[110000][2],B[210000];
int n,len;
long long ans=0,C[210000];
void add(int k1,int k2){
	atom k3; if (k1<=n) k3=A[k1][0]; else k3=A[k1-n][1];
	if (k2==1) ans+=k3.x; else ans-=k3.y;
}
int compare(atom k1,atom k2){
	return k1.x>k2.x||(k1.x==k2.x&&k1.y<k2.y);
}
int compare2(long long k1,long long k2){
	return k1>k2;
}
void add2(int k1,int k2){
	if (k2==1) ans+=A[k1][0].x-A[k1][1].y; else ans-=A[k1][0].y-A[k1][1].x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) A[i][0].scan(),A[i][1].scan();
	int pre=0;
	for (int i=1;i<=n;i++)
		if (A[i][0].x<=A[i][1].y&&A[i][1].x>=A[i][0].y) continue; else{
			pre++; A[pre][0]=A[i][0]; A[pre][1]=A[i][1];
		}
	n=pre;
	for (int i=1;i<=n;i++){
		if (A[i][0].x+A[i][0].y<A[i][1].x+A[i][1].y) continue;
		len++; B[len]=(atom){A[i][0].x+A[i][0].y,i};
		len++; B[len]=(atom){A[i][1].x+A[i][1].y,i+n};
	}
	sort(B+1,B+len+1,compare);
//	for (int i=1;i<=len;i++) cout<<B[i].y<<endl;
	for (int i=1;i<=len;i++)
		if (i&1) add(B[i].y,1); else add(B[i].y,-1);
	int now=len&1;
	len=0; int k1=0,k2=0;
	for (int i=1;i<=n;i++)
		if (A[i][0].x+A[i][0].y<A[i][1].x+A[i][1].y){
		//	cout<<"fa "<<i<<" "<<ans<<endl;
			if (A[i][0].x>A[i][1].y&&A[i][0].y<=A[i][1].x) ans+=A[i][0].x-A[i][1].y,k1++;
			else if (A[i][0].y>A[i][1].x&&A[i][0].x<=A[i][1].y) ans+=A[i][1].x-A[i][0].y,k2++;
			else B[++len]=(atom){A[i][0].x+A[i][0].y-A[i][1].x-A[i][1].y,i};
		}
	sort(B+1,B+len+1,compare);
	if (len) cout<<"fa"<<endl;
	int k3=1;
	while (k3<=len){
		if (now==1){
			if (k1) k1--; else add2(B[k3].y,1),k3++;
		} else if (k2) k2--; else add2(B[k3].y,-1),k3++;
		now^=1;
	}
	cout<<ans<<endl;
	return 0;
}