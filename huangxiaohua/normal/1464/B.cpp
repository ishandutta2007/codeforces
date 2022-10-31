#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,a[100500],x,y;

char sb[100500];

ll res,one[100500],zero[100500],res2,tmp;

vector<ll> v;

int main(){
	scanf("%s%d%d",sb+1,&x,&y);

	n=strlen(sb+1);
	
	for(i=1;i<=n;i++){
		one[i]+=one[i-1];
		zero[i]+=zero[i-1];
		if(sb[i]=='1'){res+=x*zero[i];one[i]++;}
		else{res+=y*one[i];zero[i]++;}
	}
	
	for(i=1;i<=n;i++){
		if(sb[i]=='?'){
			v.push_back((zero[i]-1)*x-one[i]*y+(zero[n]-zero[i])*y-(one[n]-one[i])*x);
			//printf("%lld\n",v[v.size()-1]);
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++){
		tmp+=v[i];
		//printf("%d\n",tmp);
		res2=min(res2,tmp-(((ll)i+(ll)i*i)/2*(x+y)));
	}
	printf("%lld",res+res2);
}