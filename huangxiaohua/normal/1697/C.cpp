#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll p[1005000];
int f1[1005000],f2[1005000],it1,it2;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	//cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2;
		s1="X"+s1;s2="X"+s2;
		
		it1=it2=0;
		for(i=1;i<=n;i++){
			if(s1[i]=='a')f1[++it1]=i;
			if(s2[i]=='a')f2[++it2]=i;
		}
		if(it1!=it2){
			cout<<"NO\n";continue;
		}
		k=0;
		for(i=n;i>=1;i--){
			if(s1[i]=='c')k=0;
			else if(s1[i]=='b')k++;
			else{
				if((f2[it2]-i)>k||f2[it2]<i){
					cout<<"NO\n";
					goto aaa;
				}
				swap(s1[i],s1[f2[it2]]);
				it2--;
			}
		}
		//cout<<s1<<'\n';
		
		it1=it2=0;
		for(i=1;i<=n;i++){
			if(s1[i]=='b')f1[++it1]=i;
			if(s2[i]=='b')f2[++it2]=i;
		}
		if(it1!=it2){
			cout<<"NO\n";continue;
		}
		k=0;
		for(i=n;i>=1;i--){
			if(s1[i]=='a')k=0;
			else if(s1[i]=='c')k++;
			else{
				if((f2[it2]-i)>k||f2[it2]<i){
					cout<<"NO\n";
					goto aaa;
				}
				swap(s1[i],s1[f2[it2]]);
				it2--;
			}
		}
		//cout<<s1<<'\n';
		
		cout<<"YES\n";
		aaa:;
	}
}