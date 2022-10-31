#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[500500],b[500500],c[500500],it1,it2,it3,res,sb;
int main(){
	cin.tie(0);
	cin>>n>>m;
	while(n--){
		cin>>j>>k;
		if(j==1)a[++it1]=-k;
		if(j==2)b[++it2]=-k;
		if(j==3)c[++it3]=-k;
	}
	sort(a+1,a+it1+1);
	sort(b+1,b+it2+1);
	sort(c+1,c+it3+1);
	for(i=1;i<=500000;i++)a[i]*=-1,a[i]+=a[i-1],b[i]*=-1,b[i]+=b[i-1],c[i]*=-1,c[i]+=c[i-1];
	j=0;
	for(i=it3;i>=0;i--){
		if(i*3>m)continue;
		sb=c[i];
		while(1){
			if(j*2+2+i*3>m)break;
			if((b[j]+a[m-i*3-j*2])<=b[j+1]+a[m-i*3-j*2-2])j++;
			else break;
		}
		sb+=b[j]+a[m-i*3-j*2];
		res=max(res,sb);
	}
	cout<<res;
}