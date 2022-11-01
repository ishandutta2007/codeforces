#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,T;
int ans;
int a[N],rv[N],f[N],len[N];
bool yes;
multiset<int>A;
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	fo(ts,1,T){
		cin>>n;
		fo(i,1,n)cin>>a[i],rv[a[i]]=i;
		fo(i,1,n+1)f[i]=i,len[i]=1;
		yes=1;
		A.clear();
		fo(i,1,n)A.insert(1);
		fo(j,1,n){
			int i=rv[j];
			if(*--A.end()!=len[i]){
				yes=0;
				break;
			}
			A.erase(A.find(len[i]));
			f[i]=i+1;
			int x=F(i);
			if(x<=n){
				A.erase(A.find(len[x]));
				len[x]+=len[i];
				A.insert(len[x]);
			}
		}
		printf(yes?"YES\n":"NO\n");
	}
	
}