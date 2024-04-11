#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ll long long

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b<a)swap(a,b);
	if(c<b)swap(b,c);
	if(d<c)swap(c,d);
	cout<<d-a<<" "<<d-b<<" "<<d-c<<endl;

    return 0;
}