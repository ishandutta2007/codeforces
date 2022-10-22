#include<iostream>
#include<vector>
using namespace std;
int a[200003]={0};
int kh[200003]={0};
vector<int> b;
int f(int x,int t){
	b.push_back(x);
	int y=a[x];
	if(a[x]==t)
	{
		a[x]=-1;
		int l=b.size();
		for(int i=0;i<b.size();i++){
			kh[b[i]]=l;
		}
		return 0;
	}
	a[x]=-1;
	f(y,t);
}
int main(){
	int q,n,tt;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>tt;a[j]=tt-1;
		}
		for(int k=0;k<n;k++){
			if(a[k]!=-1){
				b.clear();
				f(k,k);
			}
		}
		for(int i3=0;i3<n;i3++){
			cout<<kh[i3]<<" ";
		}
		cout<<endl;
	}
}