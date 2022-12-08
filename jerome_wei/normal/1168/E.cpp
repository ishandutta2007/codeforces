#include<bits/stdc++.h>
using namespace std;

int n;
const int N=5010;
int a[N],b[N],p[N],q[N];
int idx[N];
inline void fix(int i,int j){
	if(a[i]==(p[i]^q[i]))return;
	else if(q[i]==(p[i]^a[j])){
		swap(q[i],q[j]);
		swap(p[i],p[j]);
		swap(idx[p[i]],idx[p[j]]);
	}else if(q[i]==(p[j]^a[i])){
		swap(p[i],p[j]);
		swap(idx[p[i]],idx[p[j]]);
	}else if(q[i]==(p[j]^a[j])){
		swap(q[i],q[j]);
	}else{
		int t=idx[a[i]^q[i]];
		swap(idx[p[t]],idx[p[i]]);
		swap(p[t],p[i]);
		swap(q[t],q[i]);
		swap(q[t],q[j]);
		swap(q[i],q[j]);
		fix(t,j);
	}
}

int main()
{
	cin >> n;n=1<<n;
	int tot=0;
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		idx[i]=p[i]=q[i]=i;tot^=b[i];
	}
	if(tot){
		puts("Fou");return 0;
	}else{
		puts("Shi");
		for(int i=0;i+1<n;i++){
			a[i+1]^=(a[i]^b[i]);
			a[i]=b[i];
			fix(i,i+1);
		}
		for(int i=0;i<n;i++)
			printf("%d ",p[i]);
		puts("");
		for(int i=0;i<n;i++)
			printf("%d ",q[i]);
		puts("");
	}
}