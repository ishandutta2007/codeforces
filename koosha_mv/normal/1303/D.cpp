#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,a1[63],a2[63],t,m,x,p,tvn,sum1,sum2,ans,g;
int main(){
	cin>>t;
	f(q,0,t){
		ans=0,g=0;
		f(i,0,60) a1[i]=a2[i]=0;
		cin>>n>>m;
		f(i,0,m){
			cin>>x;p=0;
			g+=x;
			while(x%2==0){
				x/=2;
				p++;
			}
			a1[p]++;
		}
		if(g<n) cout<<-1<<endl;
		else{
		p=0;
		while(n>0){
			a2[p]+=(n%2);
			p++;
			n/=2;
		}
		tvn=1;
		sum1=sum2=0;
		f(i,0,60){
			sum1+=(a1[i]*tvn);
			sum2+=(a2[i]*tvn);
			//cout<<sum1<<" "<<sum2<<endl;
			if(sum1<sum2){
				f(j,i+1,60){
					if(a1[j]>=1){
						p=j;
						a1[j]--;
						break;
					}
				}
				ans+=(p-i);
				sum1+=tvn*2;
				f(j,i+1,p)
					a1[j]++;
			}
			tvn*=2;
		}
		cout<<ans<<endl;
		}
	}
}