#include <cstdio>
#include <algorithm>
#include <deque>

std::deque<int>q;
int n,a[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	q.push_back(a[n]);
	for(int i=n-1;i;i--){
		if(q.front()>q.back())q.push_front(a[i]);
		else q.push_back(a[i]);
	}
	for(int i=1;i<=n;i++)printf("%d ",q.front()),q.pop_front();
}