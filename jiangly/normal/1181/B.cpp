// remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
char s[N];
vector<int>b;
int c[N],d[N];
int l1,l2;
void get(int l,int a[N],int&len){
    memset(a,0,N*sizeof(int));
    len=max(l,n-l);
    for(int i=1;i<=l;++i)
        a[l-i]=s[i]-'0';
    for(int i=l+1;i<=n;++i)
        a[n-i]+=s[i]-'0';
    for(int i=0;i<len;++i)
        if(a[i]>=10){
            a[i]-=10;
            ++a[i+1];
        }
    if(a[len])
        ++len;
}
bool cmp(int a[N],int l1,int b[N],int l2){
    if(l1!=l2)
        return l1>l2;
    for(int i=l1-1;i>=0;--i)
        if(a[i]!=b[i])
            return a[i]>b[i];
    return false;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;++i)
        if(s[i+1]!='0')
            b.push_back(i);
    sort(b.begin(),b.end(),[](int i,int j){return max(i,n-i)<max(j,n-j);});
    get(b[0],c,l1);
    for(int i=1;i<min(b.size(),4u);++i){
        get(b[i],d,l2);
        if(cmp(c,l1,d,l2)){
            swap(c,d);
            swap(l1,l2);
        }
    }
    for(int i=l1-1;i>=0;--i)
        printf("%d",c[i]);
    return 0;
}