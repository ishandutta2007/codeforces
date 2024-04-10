#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;
    int n=s.size();
    n--;
    if((s[n]-'0')%2==0){cout<<0<<endl;continue;}

    if((s[0]-'0')%2==0){cout<<1<<endl;continue;}
    bool ans=false;
    for(int i=0;i<=n;i++)
    if((s[i]-'0')%2==0){ans=true;break;}
    if(ans)cout<<2<<endl;
    else cout<<-1<<endl;
}
	return 0;
}