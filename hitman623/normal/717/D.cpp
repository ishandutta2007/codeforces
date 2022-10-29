#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int mod=hell,lim=(1<<7);
void xorFWHT(double *data,int dim,bool inverse){
	int len;
	double u,v;
	for(len=1;2*len<=dim;len<<=1){
		for(int i=0;i<dim;i+=2*len){
			for(int j=0;j<len;j++){
				u=data[i+j];
				v=data[i+len+j];
				if(!inverse){
					data[i+j]=u+v;
					data[i+len+j]=u-v;
				}
				else{
					data[i+j]=(u+v);
					data[i+len+j]=u-v;
				}
			}
		}
	}
	if(inverse){
		rep(_,0,lim){
			data[_]=data[_]/lim;
		}
	}
}
int n,x;
double data[1001];
double expo(double x,int n){
    if(n==0) return 1;
    if(n==1) return x;
    double d=expo(x,n/2);
    d*=d;
    if(n%2) d*=x;
    return d;
}
void solve(){
    cin>>n>>x;
    rep(i,0,x+1){
        cin>>data[i];
    }
    xorFWHT(data,lim,0);
    rep(i,0,lim){
        data[i]=expo(data[i],n);
    }
    xorFWHT(data,lim,1);
    cout<<fixed<<setprecision(10)<<1-data[0]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}