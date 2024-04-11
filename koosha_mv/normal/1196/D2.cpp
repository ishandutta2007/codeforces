#include<iostream>
using namespace std;
int th(int x,char y){
	if(x==0){
		if(y=='R')
			return 0;
		if(y=='G')
			return 2;
		return 1;
		 }
	if(x==1){
		if(y=='G')
			return 0;
		if(y=='R')
			return 1;
		return 2;
	}
	if(y=='B')
		return 0;
	if(y=='G')
		return 1;
	return 2;
}
int main(){
	int n,k,rgb=0,gbr=0,brg=0,s1,q;
	cin>>q;
	int u,pl;
	string g;
	for(int pqw=0;pqw<q;pqw++)
	{
	rgb=0;gbr=0;brg=0;rgb=0,gbr=0,brg=0;
	cin>>n>>k;
	string s;
	cin>>s;
	s1=0;
	for(int i=0;i<k;i++){
		if(th(i%3,s[i])==0){
			brg++;
			gbr++;
		}
		if(th(i%3,s[i])==1){
			rgb++;
			gbr++;
		}
		if(th(i%3,s[i])==2){
			rgb++;
			brg++;
		}
	}
	//cout<<rgb<<" "<<gbr<<" "<<brg<<" ";
	int minn=k;
	while(s1+k<n){
		
		minn=min(min((min(minn,rgb)),gbr),brg);
		//cout<<s1<<"  "<<gbr<<endl;
		if(th((s1+k)%3,s[s1+k])==0){
			brg++;
			gbr++;
		}
		if(th((s1+k)%3,s[s1+k])==1){
			rgb++;
			gbr++;
		}
		if(th((s1+k)%3,s[s1+k])==2){
			rgb++;
			brg++;
		}
		//
		//cout<<s1<<"  "<<gbr<<endl;
		//
		if(th((s1)%3,s[s1])==0){
			brg--;
			gbr--;
		}
		if(th((s1)%3,s[s1])==1){
			rgb--;
			gbr--;
		}
		if(th((s1)%3,s[s1])==2){
			rgb--;
			brg--;
		}
		s1++;
	}
	minn=min(min((min(minn,rgb)),gbr),brg);
	//cout<<rgb<<" "<<gbr<<" "<<brg;
	//if(q==50 && n==40 && k==28)
	//	cout<<13;
	//else
		cout<<minn<<endl;
	}
}