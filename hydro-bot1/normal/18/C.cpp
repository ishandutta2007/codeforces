// Hydro submission #6308741045cdc66f60c9e1c8@1661498384866
#include<iostream>
using namespace std;
int n,a[100010],s[100010];
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n-1;i++)
	{
        if(s[i]==s[n]-s[i])
        {
           ans++;
    	}
    }
    cout<<ans<<endl;
    return 0;
}