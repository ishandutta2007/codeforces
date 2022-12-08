#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back
#define inf INT_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--){

    int a,b;
    cin>>a>>b;
    int x=b*((a+b-1)/b);
    cout<<x-a<<endl;

    }
    return 0;
 
}