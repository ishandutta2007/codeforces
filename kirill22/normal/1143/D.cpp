#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int f(int a1,int a2){
	if (a1<a2){
		swap(a1,a2);
	}
	if(a2 == 0){
		return a1;
	}
	return f(a1%a2,a2);
}
int get_min(int x){
	int ans=1e18;
	for(int y=0;y<=n+2;y++){
		if (k*y-x>=0){
		ans = min(ans,n*k /f(n*k,k*y-x));
		}
	}
	return ans;
}
int get_max(int x){
	int ans=0;
	for(int y=0;y<=n+2;y++){
		if (k*y-x>=0){
		ans = max(ans,n*k /f(n*k,k*y-x));
		}
	}
	return ans;
}
signed main(){
    cin >> n >> k;
    int a,b;
    cin >> a >> b;
    int mini,maxi;
    mini=get_min(a+b);
    maxi=get_max(a+b);
    mini=min(mini,get_min(a-b));
    maxi=max(maxi,get_max(a-b));
    mini=min(mini,get_min(-a-b));
    maxi=max(maxi,get_max(-a-b));
    mini=min(mini,get_min(-a+b));
    maxi=max(maxi,get_max(-a+b));
    cout << mini << " " << maxi;
    

    return 0;

}