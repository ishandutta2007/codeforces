#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
int a[M];
vector<int>ans;
void work(){
	ans.clear();
	int s=0,p=0,t=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	for(int i=1;i<=n;++i){
		t+=a[i];
		if(t%2==0&&!a[i]){
			p=i;break;
		}
		if(t%2==1&&!a[i]){
			if(a[i+1]){
				ans.push_back(i-1);
				a[i-1]=a[i+1]=0;
				p=i;
				break;
			}
			else {
				ans.push_back(i-1);
				a[i]=a[i+1]=1;
				t++;
			}
		}
	}
	if(p==0||s%2==1){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=p;i<=n-2;++i){
		if(!a[i]&&a[i+1]&&a[i+2]){
			ans.push_back(i);
			a[i]=a[i+1]=a[i+2]=0;
		}
		if(a[i]){
			ans.push_back(i);
			int x=a[i]^a[i+1]^a[i+2];
			a[i]=a[i+1]=a[i+2]=x;
			if(a[i]){
				ans.push_back(i-1);
				a[i]=a[i+1]=0;
			}
		}
	}
	for(int i=p;i>=3;--i){
		if(!a[i]&&a[i-1]&&a[i-2]){
			ans.push_back(i-2);
			a[i]=a[i-1]=a[i-2]=0;
		}
		if(a[i]){
			ans.push_back(i-2);
			int x=a[i]^a[i-1]^a[i-2];
			a[i]=a[i-1]=a[i-2]=x;
			if(a[i]){
				ans.push_back(i-1);
				a[i]=a[i+1]=0;
			}
		}
	}
	printf("%d\n",ans.size());
	for(auto o:ans)printf("%d ",o);
	if(ans.size())puts("");
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}