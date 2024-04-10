#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s2[100500],s1[100500];
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s1+1>>s2+1;
		n=strlen(s1+1);
		m=strlen(s2+1);
		v.clear();
		for(i=1;i<=n;i++){
			if(s1[i]=='1'){v.push_back(n+1-i);}
		}
		for(i=m;i>=1;i--){
			if(s2[i]=='1'){k=m+1-i;break;}
		}
		sort(v.begin(),v.end());
		for(auto i:v){
			if(k<=i){printf("%d\n",i-k);break;}
		}
	}
}