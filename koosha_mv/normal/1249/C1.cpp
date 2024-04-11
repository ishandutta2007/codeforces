#include<iostream>
int f(int x){
	if(x==0)
		return 1;
	if(x%3>1)
		return 0;
	return f(x/3);
}
using namespace std;
int main(){
	int q,n;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;
		while(f(n)!=1){
			n++;
		}
		cout<<n<<endl;
	}
}