/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    char a[401];

    for(int i=0;i<=400;i++) a[i]='?';

    int pos=200;
    a[pos]=s[0];

    for(int i=1;i<n;i++)
    {
        if(a[pos+1]==s[i]) ++pos;
        else if(a[pos-1]==s[i]) --pos;
        else if(a[pos+1]=='?') a[++pos]=s[i];
        else if(a[pos-1]=='?') a[--pos]=s[i];
        else { cout<<"NO"<<endl; return; }
    }

    int strt,nd;
    for(strt=0;strt<=400;strt++) { if(a[strt]!='?') break; }
    for(nd=400;nd>=0;nd--) { if(a[nd]!='?') break; }

    int freq[27]={0};
    for(int i=strt;i<=nd;i++) freq[a[i]-96]++;
    for(int i=1;i<=26;i++)
    {
        if(freq[i]>1) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
    for(int i=strt;i<=nd;i++) cout<<a[i];
    for(int i=1;i<=26;i++)
    {
        char x=96+i;
        if(freq[i]==0) cout<<x;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}