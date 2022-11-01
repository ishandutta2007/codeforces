#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)

int i,j,n,k,a[300500];
ll res;
priority_queue<int> q;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		if(!q.empty()){
			if(q.top()+a[i]>0){
				k=q.top()+a[i];
				res+=k;q.push(-a[i]);
				q.pop();
			}
		}
		q.push(-a[i]);
	}
	printf("%lld",res);
}