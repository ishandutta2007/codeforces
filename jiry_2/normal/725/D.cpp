#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct atom{
	long long f,w,where;
	void scan(){
		scanf("%I64d%I64d",&f,&w);
	}
}x[310000];
priority_queue<long long>A,B;
int compare(atom k1,atom k2){
	return k1.f>k2.f||(k1.f==k2.f&&k1.where<k2.where);
}
int n,pre,ans,where;
long long rem;
void insert(long long k1){
	if (!B.empty()){
		long long k2=B.top();
		if (k2>k1){
			A.push(-k2); B.pop(); B.push(k1); rem+=k2-k1; return;
		}
	}
	A.push(-k1); pre++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) x[i].scan(),x[i].where=i;
	n++; x[n]=(atom){0,0,n};
	sort(x+1,x+n+1,compare);
	pre=0,ans=0,where=0;
	long long rem=0;
	for (int i=1;i<=n;i++)
		if (x[i].where==1) where=i;
	ans=where; pre=where;
//	cout<<"asd"<<endl;
//	for (int i=1;i<=n;i++) cout<<x[i].where<<" "<<x[i].f<<" "<<x[i].w<<endl;
	for (int i=1;i<where;i++) A.push(-(x[i].w-x[i].f+1));
	for (int i=where+1;i<=n;i++){
		rem+=x[i-1].f-x[i].f;
		if (i-1!=where) insert(x[i-1].w-x[i-1].f+1);
		while (!A.empty()){
			long long k1=-A.top();
			if (k1<=rem){
				rem-=k1; pre--; A.pop();
			} else break;
		}
		ans=min(ans,pre);
	}
	printf("%d\n",ans);
	return 0;
}