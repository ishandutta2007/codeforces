#include<bits/stdc++.h>
#define int long long 
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=10010;
int i,j,k,n,m,T,Or[maxn],And[maxn],w[maxn],N;
bool is(int a1,int o1,int a2,int o2){
//	cout<<a1<<' '<<o1<<' '<<a2<<' '<<o2<<endl;
	for(int i=30;i>=0;i--){
		int w=1<<i;
		int s1=(a1&w)+(o1&w),s2=(a2&w)+(o2&w);
		if(s1>s2)return false;
		if(s1<s2)return true;
	}return false;
}
bool cmp(int a,int b){
	return is(And[a],Or[a],And[b],Or[b]);
}
void getans(int x,int y,int s1,int s2){
	int ans=0;
	for(int i=30;i>=0;i--){
		int w=1<<i;
		if((Or[x]&w)==(And[x]&w))ans+=(Or[x]&w);
		else
		if((Or[y]&w)==(And[y]&w))ans+=(Or[y]&w);
		else{
			ans+=w-(s1&w);
		}
	}N=ans;
}
signed main(){
	scanf("%lld %lld",&n,&m);
	for(i=1;i<n;i++){
		w[i]=i;
		printf("or %lld %lld\n",n,i);
		fflush(stdout);
		scanf("%lld",&Or[i]);
		printf("and %lld %lld\n",n,i);
		fflush(stdout);
		scanf("%lld",&And[i]);
	}
	sort(w+1,w+n,cmp);
	int OR1,AND1;
	if(m==n){
		printf("or %lld %lld\n",w[m-1],w[m-2]);
		fflush(stdout);
		scanf("%lld",&OR1);
		printf("and %lld %lld\n",w[m-1],w[m-2]);
		fflush(stdout);
		scanf("%lld",&AND1);
		getans(w[m-1],w[m-2],OR1,AND1);
		if(is(AND1,OR1,And[w[m-2]],Or[w[m-2]]))printf("finish %lld\n",N);
		else printf("finish %lld\n",Or[w[m-1]]+And[w[m-1]]-N);
		return 0;
	}
	if(m==1){
		printf("or %lld %lld\n",w[1],w[2]);
		fflush(stdout);
		scanf("%lld",&OR1);
		printf("and %lld %lld\n",w[1],w[2]);
		fflush(stdout);
		scanf("%lld",&AND1);
		getans(w[1],w[2],OR1,AND1);
		if(is(AND1,OR1,And[w[2]],Or[w[2]]))printf("finish %lld\n",Or[w[1]]+And[w[1]]-N);
		else printf("finish %lld\n",N);
		return 0;
	}
	printf("or %lld %lld\n",w[m-1],w[m]);
	fflush(stdout);
	scanf("%lld",&OR1);
	printf("and %lld %lld\n",w[m-1],w[m]);
	fflush(stdout);
	scanf("%lld",&AND1);
	getans(w[m-1],w[m],OR1,AND1);
	if(is(AND1,OR1,And[w[m-1]],Or[w[m-1]]))printf("finish %lld\n",Or[w[m]]+And[w[m]]-N);
	else if(is(AND1,OR1,And[w[m]],Or[w[m]]))printf("finish %lld\n",N);
	else printf("finish %lld\n",Or[w[m-1]]+And[w[m-1]]-N);
	return 0;
}