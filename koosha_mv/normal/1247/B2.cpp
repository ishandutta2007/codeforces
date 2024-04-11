#include<iostream>
using namespace std;
int a[1000009],m[1000009];
int main(){
	int q,n,k,d,p1,p2;
	cin>>q;
	for(int qw=0;qw<q;qw++){
		int mt=0,mn,m[1000009]={0};
		cin>>n>>k>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		p1=0;p2=d;
		mn=d;
		for(int i=0;i<d;i++){
			m[a[i]]++;
			if(m[a[i]]==1)
				mt++;
		}
		mn=mt;
		while(p2<n){
			//cout<<p1<<" "<<p2<<" "<<mt<<endl;
			if(m[a[p1]]==1)
				mt--;
			m[a[p1]]--;
			p1++;
			if(m[a[p2]]==0)
				mt++;
			m[a[p2]]++;
			p2++;
			mn=min(mn,mt);
		}
		cout<<mn<<endl;
	}
}