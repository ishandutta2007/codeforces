
#include<iostream>
#include<algorithm>
using namespace std;
int a[2],tol[52],st=0;
int main(){
	int q,t,t0,t1,tf=0,size=0;
	string s;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>t;
		tf=0;t0=0;t1=0;
		for(int w=0;w<t;w++){
			cin>>s;
			for(int j=0;j<s.size();j++){
				if(s[j]=='0')
					t0++;
			}
			if(s.size()%2)
			    tf=1;
		}
		if(tf==0 && t0%2) cout<<t-1<<endl;
		else cout<<t<<endl;
		}
}