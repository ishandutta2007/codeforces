//Problem C
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long
ll n,s,a[N];
int main(){
    cin>>n,s=sqrt(n);
	for(int i=1;i<=s;i++)if(n%i==0)a[++a[0]]=i,a[++a[0]]=n/i;
	sort(a+1,a+a[0]+1);
	a[0]=unique(a+1,a+a[0]+1)-a;
	reverse(a+1,a+a[0]);
	for(int i=1;i<a[0];i++)cout<<n*(n+2-a[i])/(2*a[i])<<" ";
    return 0;
}