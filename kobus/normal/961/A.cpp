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

int v[1123];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int num;
    	cin>>num;
    	v[num]++;
    }
    int resp=INF;
    for(int i=1;i<=n;i++)resp=min(resp,v[i]);
    	cout<<resp<<endl;
    return 0;

}