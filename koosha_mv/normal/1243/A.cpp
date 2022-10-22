#include<iostream>
using namespace std;
int a[10000];
int main(){
	int q,x,n;
	cin>>q;
	for(int pq=0;pq<q;pq++){
		cin>>n;
		int a[10000]={0};
		for(int i=0;i<n;i++){
			cin>>x;
			a[x]++;
		}
		int sum=0;
		for(int i=n;i>=0;i--){
			sum+=a[i];
			if(sum>=i){
				cout<<i<<endl;
				break;
			}
		}
	}
}