#include <bits/stdc++.h>  
using namespace std; 

typedef long long ll;  
ll n,h;  
const ll cnt=2000000000;  

inline bool check(ll x)
{  
    if(x<=h)
	{  
        if(x>=cnt) return true;  
        return x*(x+1)/2>=n;  
    }  
    ll a=(x-h)/2+h;  
    if(a>=cnt) return true;  
    if((x-h)%2!=0)  
    return a*(a+1)/2+(a+h)*(a+1-h)/2>=n;  
    return a*(a+1)/2+(a-1+h)*(a-h)/2>=n;  
}  

int main()  
{  
    cin>>n>>h;  
    ll ln=1,rn=n;  
    while(ln<=rn)
	{  
        ll mid=(ln+rn)>>1ll;  
        if(check(mid)) rn=mid-1;  
        else ln=mid+1;  
    }  
    cout<<rn+1<<endl;  
}