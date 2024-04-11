#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=5e5+99,Mx=1e9;

ll n,t;
ll a[N];

int main(){
    cin>>n;
    f(i,1,n+1) cin>>a[i];
    if(n==1){
    	cout<<1<<endl<<1<<endl;
    	cout<<-a[1]<<endl;
    	cout<<1<<endl<<1<<endl;
    	cout<<0<<endl;
    	cout<<1<<endl<<1<<endl;
    	cout<<0<<endl;
    	return 0;
    }
    cout<<1<<" "<<n-1<<endl;
    f(i,1,n){
        cout<<((a[i]+Mx*n)%n)*(n-1)<<" ";
        a[i]+=((a[i]+Mx*n)%n)*(n-1);
    }
    cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<n-((a[n]+Mx*n)%n)<<endl;
    a[n]+=n-((a[n]+Mx*n)%n);
    cout<<1<<" "<<n<<endl;
    f(i,1,n+1) cout<<-a[i]<<" ";
}