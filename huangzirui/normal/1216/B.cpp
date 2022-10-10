#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
struct node{
	int s,id;
}a[100010];
bool cmp(node a,node b){return a.s>b.s;}
int main() {
    cin>>n;
	for(i=1;i<=n;i++)read(a[i].s),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=a[i].s*(i-1);
	cout<<ans+n<<endl;
	for(i=1;i<=n;i++){cout<<a[i].id;if(i!=n)cout<<' ';}
    //cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
    return 0;
}