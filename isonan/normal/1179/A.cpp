#include <cstdio>
#include <deque>

int a[100001],n,q;
std::deque<int>dq;
int ans[100001][2];
long long opt;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),dq.push_back(a[i]);
	for(int i=1;i<=n;i++){
		int a=dq.front(),b;
		dq.pop_front();
		b=dq.front();
		dq.pop_front();
		if(a>b)dq.push_front(a),dq.push_back(b);
		else dq.push_back(a),dq.push_front(b);
		ans[i][0]=a,ans[i][1]=b;
	}
	for(int i=1;i<=n;i++)a[i]=dq.front(),dq.pop_front();
	for(int i=1;i<=q;i++){
		scanf("%I64d",&opt);
		if(opt<=n)printf("%d %d\n",ans[opt][0],ans[opt][1]);
		else printf("%d %d\n",a[1],a[2+((opt-n-1)%(n-1))]);
	}
}