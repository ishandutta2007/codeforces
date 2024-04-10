// Hydro submission #62cd06a3e4874952a0849876@1657603748584
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n,s,ans = 0;
    cin >> n >> s;
    int a[n];
    for(register int i = 0; i < n; ++i) cin >> a[i];
    for(register int i = 0; i < n - 1; ++i){
        if(a[i]>=a[i+1])
		{
			ans+=(a[i]-a[i+1])/s+1;
			a[i+1]+=((a[i]-a[i+1])/s+1)*s;
		}
    }
    cout<<ans<<endl;
    return 0;
}