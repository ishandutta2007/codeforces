#include<iostream>
#include<vector>
using namespace std;
int a[1000]={0};
int kh[1000]={0};
vector<int> b;
int f(int x,int t){
	b.push_back(x);
	int y=a[x];
	//cout<<x<<" "<<t<<endl;
	if(a[x]==t)
	{
		a[x]=-1;
		int l=b.size();
		//if(l==0)l=1;
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
				//cout<<k;
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