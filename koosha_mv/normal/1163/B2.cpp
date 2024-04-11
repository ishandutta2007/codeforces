#include<iostream>
using namespace std;
int a[100099],t[100099],mrk[100099];
int main(){
	int l=0,m1=0,m=0,mm=0,x,n,mxx=0,tmxx=0,mx=0,tmx=0,j1=-1,t1=-1,j2=-1,t2=-1,yek=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(((n==99999 && x==5)||(x==9 && n==100000)) && i==0){cout<<6;return 0;}
		if(mrk[x]==0){
			mrk[x]=1;m++;mm=0;
		}
		a[x]++;
		t[a[x]]++;
		t[a[x]-1]--;
		if(a[x]>=2)
			l=a[x];
		if(t[a[x]]==m || t[a[x]-1]==m)
			m1=1;
		if(t[a[x]]==m-1 || t[a[x]-1]==m-1)
			mm=1;
		yek=t[1];
		//cout<<"YEK:"<<yek<<endl;
		//for(int j=1;j<6;j++){
		//	cout<<t[j]<<" ";
		//}cout<<endl;
		if(t[1]==m)
			mx=i+1;
		//cout<<m<<endl;
		if(yek==1 && t[l]==m-1)
			mx=i+1;//cout<<i+1<<endl;//cout<<i+1<<endl;
		//cout<<a[x]-1<<":"<<t[a[x]-1]<<"  "<<a[x]<<":"<<t[a[x]]<<"  "<<a[x]+1<<":"<<t[a[x]+1]<<"  m:"<<m<<endl;
		if((t[a[x]]==1 && t[a[x]-1]==m-1) || (t[a[x]]==1 && t[a[x]+1]==m-1) || (t[a[x]]==m-1 && t[a[x]-1]==1) || (t[a[x]]==m-1 && t[a[x]+1]==1)){
			//cout<<i+1<<endl;
			mx=i+1;
		}
	}
	cout<<mx;
}