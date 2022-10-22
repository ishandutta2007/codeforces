#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(a[1]!=n && a[n]!=n){cout<<-1<<endl;continue;}
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
	return 0;
}