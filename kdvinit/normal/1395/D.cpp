/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;
long long int n,d,cnt=0,m,a[100001];
long long int sum(int x,int y){
    long long int ans=0;
    for(int i=x+1;i<=x+y;i++) ans+=a[i];
    return ans;
}
bool check(int x,int y,int len){
    if(x+len>n-cnt) return false;
    if(y-1<=n-cnt) return false;
    if(sum(x,len)>a[y-1]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>d>>m;
    for(int i=1;i<=n;i++) { cin>>a[i]; if(a[i]>m) cnt++; }
    sort(a+1,a+n+1);
    if(cnt==0) { cout<<sum(0,n)<<endl; return 0; }
    long long int ans=0;
    int nd=((cnt+d)/(d+1)); nd=n-nd+1;
    int strt=0;
    for(int i=nd;i<=n;i++) ans+=a[i];
    for(int i=1;i<=n-cnt;i++) ans+=a[i];
    int y=((cnt-1)%(d+1)); y=d+1-y;
    if(check(strt,nd,y)) { ans+=a[--nd]; ans-=sum(0,y); strt+=y;}
    else { cout<<ans<<endl; return 0;}
    while(1){
        if(check(strt,nd,d+1)) { ans+=a[--nd]; ans-=sum(strt,d+1); strt+=d+1;}
        else { cout<<ans<<endl; return 0;}
    }
}