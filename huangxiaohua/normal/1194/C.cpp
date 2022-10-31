#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[500],it,it2;
string s1,s2,s3;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>s1>>s2>>s3;
		it=it2=0;
		for(auto i:s1){
			it2=0;
			for(auto &j:s2){
				if(j=='0'){it2++;}
				if(it2<it){continue;}
				if(j==i){j='0';goto aaa;}
			}
			cout<<"NO"<<endl;goto bbb;
			aaa:;
			it++;
		}
		for(auto j:s2){
			if(j!='0'){a[j]--;}
		}
		for(auto j:s3){a[j]++;}
		for(i='a';i<='z';i++){
			if(a[i]<0){cout<<"NO"<<endl;goto bbb;}
		}
		cout<<"YES"<<endl;
		bbb:;
	}
}