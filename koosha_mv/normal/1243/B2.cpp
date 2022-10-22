#include<iostream>
using namespace std;
int main(){
	int q,n,k,m,l;string s1,s2;cin>>q;
	for(int pq=0;pq<q;pq++){
		cin>>n>>s1>>s2;
		int al[40]={0},kh[200]={0};
		for(int i=0;i<n;i++){
			al[s1[i]-'a']++;
			al[s2[i]-'a']++;
		}k=0;
		for(int j=0;j<40;j++){
			if(al[j]%2==1){cout<<"NO"<<endl; k=1;break;}
		}
		if(k==0){
			cout<<"YES"<<endl;m=0;
			for(int i=0;i<n-1;i++){
				if(s1[i]!=s2[i]){
					l=0;
					for(int j=i+1;j<n;j++){
						if(s1[j]==s1[i]){l=1;swap(s2[i],s1[j]);m++;kh[m*2-2]=j;kh[m*2-1]=i;break;}
					}
					if(l==0){
						for(int j=i+1;j<n;j++){
							if(s2[j]==s1[i]){swap(s2[j],s1[i+1]);swap(s2[i],s1[i+1]);kh[m*2]=i+1;kh[m*2+1]=j;m++;kh[m*2]=i+1;kh[m*2+1]=i;m++;break;}
						}
					}
				}
			}
			cout<<m<<endl;
			for(int i=0;i<m;i++){
				cout<<kh[i*2]+1<<" "<<kh[i*2+1]+1<<endl;
			}
		}
	}
}