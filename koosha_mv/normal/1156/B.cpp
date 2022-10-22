#include<iostream>
using namespace std;
int mos(int x){
	if(x<0)
		return 0;
	return x;	
}
string s1;
void print(int x,char y){
	for(int i=0;i<x;i++)
		s1+=y;
}
int main(){
	int q;string s;
	cin>>q;
	for(int pi=0;pi<q;pi++){
		cin>>s;int a[32]={0},m=0,p=0,akh=0;
		for(int i=0;i<s.size();i++){
			if(a[int(s[i])-'a']==0){
				m++;
				if(a[mos(int(s[i])-'a'-1)]>=1)
					p++;
				if(a[mos(int(s[i])-'a'+1)]>=1)
					p++;
			}
			a[int(s[i])-'a']++;
		}
	//	cout<<m<<" "<<p;
		if((m==2 && p==1) || (m==3 && p==2))
			cout<< "No answer" <<endl;
		else{
			akh=-1;
			s1="";
			for(int i=0;i<26;i+=2){
				print(a[i],char(i+'a'));
				if(a[i]>0)
					akh=i;
			}
			//cout<<s1<<endl;
			int y=0,l=0;
			//for(int i=0;i<26;i++)
			//	cout<<a[i]<<" ";
			//cout<<endl;
			for(int i=1;i<26;i+=2){
				if(a[i]>0 && y==0){
					//cout<<a[i]<<":"<<endl;
					if(i==akh+1 || i==akh-1){
						l=1;
						break;
					}
					y=1;
				}
				print(a[i],char(i+'a'));
			}
			//cout<<s1<<endl;
			if(l==1){
				s1="";
				//cout<<10000;
				for(int i=1;i<26;i+=2)
					print(a[i],char(i+'a'));
				for(int i=0;i<26;i+=2)
					print(a[i],char(i+'a'));
			}
			cout<<s1<<endl;
			}
		}
	}