#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX

int v[112345];
bool awk[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int k,n;
    cin>>k>>n;
    int resp=0;
    for(int i=0;i<k;i++)
    	cin>>v[i];
    for(int i=0;i<k;i++){
    	cin>>awk[i];
    	resp+=v[i]*awk[i];
    	awk[i]=!awk[i];
    }

    int win=0;
    for(int i=0;i<n;i++)win+=v[i]*awk[i];
    int maxw=win;
	for(int i=n;i<k;i++){
		win+=v[i]*awk[i];
		win-=v[i-n]*awk[i-n];
		maxw=max(maxw,win);
	}
	resp+=maxw;
	cout<<resp<<endl;





    return 0;

}