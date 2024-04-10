#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,n,a[200009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int st=1,en=1,l=1,r=1;
    while(r<=n)
    {
        if(s>=0 && r-l >en-st){st=l,en=r;}
        if(s>=0){s+=a[r++];continue;}
        s-=a[l++];


    }
    if(s>=0 && r-l >en-st){st=l,en=r;}
    if(st==en)cout<<-1<<endl;
    else cout<<st<<" "<<en-1<<endl;

}
	return 0;
}