#include<iostream>
using namespace std;
string s1,s2,s3;
int a[100][2],za[27]={0},t;
int q,sa,ss2;
int main(){
	cin>>q;
	for(int pq=0;pq<q;pq++){
		int b[27]={0},a[100][2],za[27]={0};
		cin>>s2>>s1>>s3;
		a[0][0]=int(s1[0]);
		a[0][1]=1;
		sa=0;
		for(int i=1;i<s1.size();i++){
			if(s1[i]==a[sa][0])
				a[sa][1]++;
			else{
				sa++;
				a[sa][0]=int(s1[i]);
				a[sa][1]=1;
			}
			}
		for(int i=0;i<s3.size();i++){
			za[int(s3[i])-int('a')]++;
		}
		ss2=-1;
		int l=0;
		for(int i=0;i<sa+1;i++){
			while(s2[ss2+1]==char(a[i][0]) && a[i][1]>0){
				ss2++;
				a[i][1]--;
			}
			if(a[i][1]<0){cout<<"NO"<<endl;l=1;break;}
			if(a[i][1]>za[a[i][0]-int('a')]){cout<<"NO"<<endl;l=1;break;}
			else {za[a[i][0]-int('a')]-=a[i][1];}
		}
		if(ss2!=s2.size()-1 && l==0){cout<<"NO"<<endl;l=1;}
		if(l==0)
			cout<<"YES"<<endl;
	}
}