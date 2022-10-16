#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
bool cmp(long long a, long long b){return a>b;}
void solve(){
    int n;
    cin>>n;
    long long tic[n+5];
    for(int i=1;i<=n;i++)cin>>tic[i];
    sort(tic+1,tic+n+1,cmp);
    tic[0]=0;
    for(int i=1;i<=n;i++)tic[i]+=tic[i-1];
    long long x,y,xx,yy,k;
    cin>>x>>xx>>y>>yy>>k;
    if(x<y){swap(x,y);swap(xx,yy);}
    for(int i=1;i<=n;i++){
        int a=floor(i/(xx*yy/__gcd(xx,yy)));
        int b=floor(i/xx)-a;
        int c=floor(i/yy)-a;
        long long sum=0;
        sum+=tic[a]/100*(x+y);
        sum+=(tic[a+b]-tic[a])/100*x;
        sum+=(tic[a+b+c]-tic[a+b])/100*y;
        if(sum>=k){cout<<i<<endl;return;}
    }
    cout<<"-1"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}