/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    char a[n+7];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n+1;i<=n+6;i++) a[i]='z';

    int cntr=0;
    for(int i=1;i<=n-6;i++)
    {
        if(a[i]=='a' && a[i+1]=='b' && a[i+2]=='a' && a[i+3]=='c' && a[i+4]=='a' && a[i+5]=='b' && a[i+6]=='a') cntr++;
    }

    if(cntr>1) { cout<<"NO"<<endl; return; }

    if(cntr==1)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='?') cout<<'z';
            else cout<<a[i];
        }
        cout<<endl;

        return;
    }

    int i;
    for(i=1;i<=n-6;i++)
    {
        if(a[i]=='a' || a[i]=='?')
        {
            if(a[i+1]=='b' || a[i+1]=='?')
            {
                if(a[i+2]=='a' || a[i+2]=='?')
                {
                    if(a[i+3]=='c' || a[i+3]=='?')
                    {
                        if(a[i+4]=='a' || a[i+4]=='?')
                        {
                            if(a[i+5]=='b' || a[i+5]=='?')
                            {
                                if(a[i+6]=='a' || a[i+6]=='?')
                                {
                                    if(a[i+7]=='c' && a[i+8]=='a' && a[i+9]=='b' && a[i+10]=='a') continue;
                                    if(a[i+7]=='b' && a[i+8]=='a' && a[i+9]=='c' && a[i+10]=='a' && a[i+11]=='b' && a[i+12]=='a') continue;
                                    if(i>=5 && a[i-4]=='a' && a[i-3]=='b' && a[i-2]=='a' && a[i-1]=='c') continue;
                                    if(i>=7 && a[i-6]=='a' && a[i-5]=='b' && a[i-4]=='a' && a[i-3]=='c' && a[i-2]=='a' && a[i-1]=='b') continue;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //cout<<i<<endl;
    if(i>n-6) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;

    for(int j=1;j<i;j++)
    {
        if(a[j]=='?') cout<<'z';
        else cout<<a[j];
    }
    cout<<"abacaba";
    for(int j=i+7;j<=n;j++)
    {
        if(a[j]=='?') cout<<'z';
        else cout<<a[j];
    }
    cout<<endl;
}

int main()
{
	int t; cin>>t;
	while(t--) solve();
	return 0;
}