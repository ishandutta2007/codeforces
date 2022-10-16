/*
K.D. Vinit
*/

#include <iostream>
#include <cmath>
using namespace std;

long long int hcf(long long int a,long long int b)
{
    if(a%b==0) return b;
    else return hcf(b,a%b);

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	long long int n,k,a,b,c,d,e;
	cin>>n>>k>>a>>b;

	long long int nk=n*k,mn=n*k,mx=1,ans1,ans2;

	c=abs(a-b);
	d=(a+b)%k;
	//e=max(c,d);

	for(long long int r=0;r<=n;r++)
    {
        //if(2*(r*k-e)>nk) break;
        long long int l[4];
        l[0]=r*k+c;l[1]=r*k-c;l[2]=r*k+d;l[3]=r*k-d;
        for(int i=0;i<4;i++)
        {
            if(l[i]<=0) continue;
            mn=min(mn,hcf(nk,l[i]));
            mx=max(mx,hcf(nk,l[i]));
        }
        //cout<<r<<" "<<mn<<" "<<mx<<endl;
    }

    //cout<<mn<<" "<<mx<<endl;
	ans1=(nk/mx);
	ans2=(nk/mn);
	cout<<ans1<<" "<<ans2<<endl;

	return 0;
}