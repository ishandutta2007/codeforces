#include<bits/stdc++.h>
using namespace std;
map<int,int> l,r,m;
map<int,int>::iterator it,jt;
long long b[300008],c[300008];
int n,k,i,j,a,p=998244353;
int main() {
    for(scanf("%d%d",&n,&k),b[1]=i=1; i++<n; b[i]=p-(p/i)*b[p%i]%p);
    for(c[i=--k]=1; i++<n; c[i]=i*c[i-1]%p*b[i-k]%p);
    for(; n--; scanf("%d%d",&i,&j),++l[i],++r[j],m[i],m[j]);
    for(i=0,it=m.begin(),jt=m.end(); it!=jt; i-=r[it->first],++it)
        for(j=l[it->first]; j--; (a+=c[i++])<p?0:a-=p);
    printf("%d\n",a),exit(0);
}