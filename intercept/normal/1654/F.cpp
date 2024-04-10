#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
using namespace std;
const int M=1<<18;
int n;
string s;
int a[M],b[M],c[M];
int main(){
	cin>>n>>s;
	for(int i=0;i<1<<n;++i)a[i]=s[i]-'0',b[i]=i;
	for(int i=0;i<n;++i){
		sort(b,b+(1<<n),[&](const int&l,const int&r){return a[l]==a[r]?a[l^(1<<i)]<a[r^(1<<i)]:a[l]<a[r];});
		c[b[0]]=0;
		for(int j=1,k=0;j<1<<n;++j){
			if(a[b[j]]!=a[b[j-1]]||a[b[j]^(1<<i)]!=a[b[j-1]^(1<<i)])k++;
			c[b[j]]=k;
		}
		for(int j=0;j<1<<n;++j)a[j]=c[j];
	}
	for(int i=0;i<1<<n;++i)putchar(s[i^b[0]]);
	return 0;
}