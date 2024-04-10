#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5005,mo=1e9+7;
int t,n,ans;
int p[N],a[N],as;
bitset<N>A;
bool can;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(;t--;){
		cin>>n;
		fo(i,1,n*2)cin>>p[i];
		can=0;
		as=0;
		int pos=1;
		fo(i,2,n*2){
			if(p[i]>p[pos]){
				a[++as]=i-pos;
				pos=i;
			}
		}
		a[++as]=n*2+1-pos;
		A.reset();
		A[0]=1;
		fo(i,1,as)
			A|=A<<a[i];
		if(A[n])printf("YES\n");
		else printf("NO\n");
	}
}