#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=509;
int n;
int a[M],b[M];
vector<int>ans;
void change(int i){
	ans.eb(i);
	int t=a[i+2];
	a[i+2]=a[i+1];
	a[i+1]=a[i];
	a[i]=t;
}
void work(){
	ans.clear();
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	bool flag=0;
	for(int i=2;i<=n;++i)if(b[i]==b[i-1])flag=1;
	for(int i=1;i<=n-2;++i){
		int mi=i;
		for(int j=i;j<=n;++j){
			if(a[j]<a[mi])mi=j;
		}
		while(mi!=i){
			if(mi-2>=i){
				change(mi-2);
				mi-=2;
			}
			else{
				change(mi-1);
				mi++;
			}
		}
	}
	if(a[n-1]>a[n]){
		if(!flag){
			cout<<"-1\n";
			return;
		}
		int p=n-2;
		while(a[p+1]>a[p+2]){
			change(p);
			p--;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto o:ans)cout<<o<<" ";
	cout<<"\n";
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1 2 2 4 3 6
*/