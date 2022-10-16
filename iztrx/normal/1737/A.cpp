#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,m,T,i,j,k,x,y,a[N],b[N],c[N];
char ch;
string s;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=0;i<26;++i)c[i]=0; 
		cin>>s; 
		for(i=0;i<n;++i){
			++c[s[i]-'a'];
		}
		for(i=1;i<=k;++i){
			int qwq=0;
			for(j=0;j<n/k;++j){
				if(c[j])++qwq,--c[j];
				else break;
			}
			cout<<char(qwq+'a');
		}cout<<'\n';
	}
}