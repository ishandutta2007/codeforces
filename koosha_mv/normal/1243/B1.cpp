#include<iostream>
using namespace std;
int main(){
	int q,n;string s1,s2;
	cin>>q;
	for(int pq=0;pq<q;pq++){
		cin>>n>>s1>>s2;
		int m=0,t1,t2,t3,t4;
		for(int i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				if(m>=2){
					m=3;
				}
				if(m==1){
					m++;
					t3=s1[i];
					t4=s2[i];
				}
				if(m==0){
					m++;
					t1=s1[i];
					t2=s2[i];
				}
			}
		}
		//cout<<m<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
		if(m==0 ||(m==2 && t1==t3 && t2==t4)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}