#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define mod 998244353 
#define int long long
    
int v[1123456];

int32_t main(){

    int n;
    cin>>n;

    int maxi=0;

    for(int i=0;i<n;i++){
    	cin>>v[i];
    	maxi=max(v[i],maxi);
    }

    int x2=maxi+1;

    for(int i=0;i<n;i++){
    	if(v[i]!=maxi)x2-=v[i];
    }

    cout<<x2<<endl;

    return 0;
}