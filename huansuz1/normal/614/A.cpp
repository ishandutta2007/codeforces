#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long

using namespace std;


int main(){
//        freopen("input","r",stdin);
  //      freopen("output","w",stdout);

        ll l,r,k;
        cin>>l>>r>>k;
        ll x = 1;
        int ok = 0;
        while(x <= r) {
        	if(x >= l) {
        		cout<<x<<' ';
        		ok = 1;
        	}
        	if(x > r/k) break;
        	x *= k;
        }
        if(!ok) cout<<"-1";

	return 0;
}