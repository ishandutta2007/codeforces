#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,lst,kk,sb,lst1,lst2;
int a,b;

int main(){
	printf("? 0 0");cout<<endl;
	cin>>k;
	for(t=30;t>=1;t--){
		printf("? %d %d",a|b(t),b|b(t));cout<<endl;
		cin>>kk;
		if(kk==k){
			printf("? %d %d",a|b(t),b|0);cout<<endl;
			cin>>sb;
			if(sb==-1){
				a|=b(t);b|=b(t);
			}
			else{
				
			}
		}
		else{
			if(k==1){
				a|=b(t);
			}
			else{
				b|=b(t);
			}
			printf("? %d %d\n",a,b);cout<<endl;
			cin>>k;
		}
	}
	cout<<"! "<<a<<' '<<b;
}