#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=509;
int n;
int a[M],b[M];
vector<pii>ans;
void change(int x,int y){
	for(int i=x,j=y;i<=j;++i,--j)swap(a[i],a[j]);
	ans.eb(x,y);
}
void work(){
	ans.clear();
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		if(a[i]!=b[i]){
			int x=a[i-1],y=b[i];
			for(int j=i;j<=n;++j){
				if(a[j]==x&&a[j+1]==y){
					bool flag=0;
					for(int l=i-1;l<=j;++l){
						for(int r=j+1;r<=n;++r){
							if(a[l]==a[r]&&flag==0)change(l,r),flag=1;
						}
					}
					if(flag)break;
				}
			}
			for(int j=i;j<=n;++j){
				if(a[j]==x&&a[j-1]==y){
					change(i-1,j);
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]!=b[i]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	cout<<ans.size()<<endl;
	for(auto o:ans){
		cout<<o.fi<<" "<<o.se<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
6

3 3 4 1 3 3

3 4 1 3 3 3




*/